// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/RunServerAsyncTask.h"
#include <grpcpp/server_builder.h>
#include "Services/RobotService.h"
#include "Subsystems/RPCServerSubsystem.h"

FRunServerAsyncTask::~FRunServerAsyncTask()
{
	if (ServerPtr)
	{
		ShutdownServer();
		ServerPtr.reset();
	}

	RPCServerSubsystem = nullptr;
	RobotServicePtr.Reset();
}

void FRunServerAsyncTask::ShutdownServer() const
{
	if (!ServerPtr) return;

	ServerPtr->Shutdown();
}

void FRunServerAsyncTask::DoWork()
{
	RobotServicePtr = MakeShareable(new FRobotService());

	grpc::ServerBuilder Builder;
	Builder.AddListeningPort("localhost:8080", grpc::InsecureServerCredentials());
	Builder.RegisterService(RobotServicePtr.Get());

	ServerPtr = Builder.BuildAndStart();
	if (ServerPtr)
	{
		// Binding here this because i don't want to bring gRPC classes and includes to other project
		// So, any other class can subscribe subsystem's delegates and handle functionality of this service
		RobotServicePtr->OnAngularSpeedRequestReceived.BindLambda([this](float NewAngularSpeed)
		{
			if (IsValid(RPCServerSubsystem))
			{
				if (RPCServerSubsystem->OnAngularSpeedChanged.IsBound())
				{
					RPCServerSubsystem->OnAngularSpeedChanged.Broadcast(NewAngularSpeed);
				}
			}
		});

		RobotServicePtr->OnLinearSpeedRequestReceived.BindLambda([this](float NewLinearSpeed)
		{
			if (IsValid(RPCServerSubsystem))
			{
				if (RPCServerSubsystem->OnAngularSpeedChanged.IsBound())
				{
					RPCServerSubsystem->OnLinearSpeedChanged.Broadcast(NewLinearSpeed);
				}
			}
		});
		
		UE_LOG(LogTemp, Display, TEXT("Server listening on address localhost:8080"));

		// Calling Server Wait() function on another thread to avoid blocking this tasks's thread,
		// so if we do not do this we cannot finish task work and shutdown server, without any other async code
		// writing this here to incapsulate all server control functionality into one task class
		AsyncTask(ENamedThreads::AnyThread, [&]()
		{
			ServerPtr->Wait();
		});
	}

	else
	{
		UE_LOG(LogTemp, Error, TEXT("Server is not created"));
	}
}
