// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tasks/RunServerAsyncTask.h"
#include "RPCServerSubsystem.generated.h"

class FRobotService;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLinearSpeedChanged, const float&, NewLinearSpeed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAngularSpeedChanged, const float&, NewAngularSpeed);

/** Handles RPC server start and end logic async, can be called from any part of game framework */
UCLASS()
class TURBOLINKGRPC_API URPCServerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	FORCEINLINE FRobotService* GetRobotService() const
	{
		if (ServerRunAsyncTask) return ServerRunAsyncTask->GetTask().GetRobotService();

		UE_LOG(LogTemp, Error, TEXT("You are trying to get RobotService, but server is not working with async task at this moment"));
		return nullptr;
	}

	UPROPERTY(BlueprintAssignable, Category = "RPCServerSubsystem|Delegates")
	FOnAngularSpeedChanged OnAngularSpeedChanged;

	UPROPERTY(BlueprintAssignable, Category = "RPCServerSubsystem|Delegates")
	FOnLinearSpeedChanged OnLinearSpeedChanged;

	void StartServer();
	void StopServer();
	
private:
	FAsyncTask<FRunServerAsyncTask>* ServerRunAsyncTask;
};
