// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <grpcpp/server.h>

class URPCServerSubsystem;

class FRobotService;

/** Runs server and shutting it down when task is being deleted */
class TURBOLINKGRPC_API FRunServerAsyncTask : public FNonAbandonableTask
{
public:
	FRunServerAsyncTask(URPCServerSubsystem* InRPCServerSubsystem) : RPCServerSubsystem(InRPCServerSubsystem) {}
	~FRunServerAsyncTask();

	void ShutdownServer() const;

	// Async task implementation
	void DoWork();
	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FRunServerAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}

	FORCEINLINE FRobotService* GetRobotService() const { return RobotServicePtr.Get(); }

private:
	TSharedPtr<FRobotService> RobotServicePtr;
	std::unique_ptr<grpc::Server> ServerPtr;

	TObjectPtr<URPCServerSubsystem> RPCServerSubsystem;
};
