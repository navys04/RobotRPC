// Fill out your copyright notice in the Description page of Project Settings.


#include "Services/RobotService.h"

grpc::Status FRobotService::SetLinearSpeed(grpc::ServerContext* context, const Robot::RobotLinearSpeedRequest* request,
	Robot::RobotResponse* response)
{
	UE_LOG(LogTemp, Display, TEXT("Linear speed request received"));
	if (FMath::IsNearlyEqual(request->linearspeed(), 0.0f))
	{
		UE_LOG(LogTemp, Display, TEXT("Request handle canceled, because linear speed value is 0.0f"));
		response->set_responsemessage("Please, provide linear speed more than zero");
		return grpc::Status::CANCELLED;
	}

	if (OnLinearSpeedRequestReceived.ExecuteIfBound(request->linearspeed()))
	{
		UE_LOG(LogTemp, Display, TEXT("Linear speed changed"));
		response->set_responsemessage("Linear speed changed on actor");
	}
	
	return grpc::Status::OK;
}

grpc::Status FRobotService::SetAngularSpeed(grpc::ServerContext* context,
	const Robot::RobotAngularSpeedRequest* request, Robot::RobotResponse* response)
{
	UE_LOG(LogTemp, Display, TEXT("Angular speed request received"));
	if (FMath::IsNearlyEqual(request->angularspeed(), 0.0f))
	{
		UE_LOG(LogTemp, Display, TEXT("Request handle canceled, because angular speed value is 0.0f"));
		response->set_responsemessage("Please, provide angular speed more than zero");
		return grpc::Status::CANCELLED;
	}

	if (OnAngularSpeedRequestReceived.ExecuteIfBound(request->angularspeed()))
	{
		UE_LOG(LogTemp, Display, TEXT("Angular speed changed"));
		response->set_responsemessage("Angular speed changed on actor");
	}

	return grpc::Status::OK;
}