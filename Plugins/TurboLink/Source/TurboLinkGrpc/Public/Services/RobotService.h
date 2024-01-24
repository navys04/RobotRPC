// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "pb/RobotService.grpc.pb.h"

DECLARE_DELEGATE_OneParam(FOnLinearSpeedRequestReceived, float);
DECLARE_DELEGATE_OneParam(FOnAngularSpeedRequestReceived, float);

class TURBOLINKGRPC_API FRobotService : public Robot::RobotService::Service
{
public:
	FOnLinearSpeedRequestReceived OnLinearSpeedRequestReceived;
	FOnAngularSpeedRequestReceived OnAngularSpeedRequestReceived;
 
protected:
	virtual grpc::Status SetLinearSpeed(grpc::ServerContext* context, const Robot::RobotLinearSpeedRequest* request, Robot::RobotResponse* response) override;
	virtual grpc::Status SetAngularSpeed(grpc::ServerContext* context, const Robot::RobotAngularSpeedRequest* request, Robot::RobotResponse* response) override;
};
