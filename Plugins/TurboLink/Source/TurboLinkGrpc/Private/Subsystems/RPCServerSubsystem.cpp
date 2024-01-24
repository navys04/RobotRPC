// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/RPCServerSubsystem.h"

void URPCServerSubsystem::StartServer()
{
	AsyncTask(ENamedThreads::AnyBackgroundHiPriTask, [&]()
	{
		ServerRunAsyncTask = new FAsyncTask<FRunServerAsyncTask>(this);
		ServerRunAsyncTask->StartBackgroundTask();
	});
}

void URPCServerSubsystem::StopServer()
{
	if (ServerRunAsyncTask)
	{
		UE_LOG(LogTemp, Display, TEXT("Server stopped"));
		ServerRunAsyncTask->EnsureCompletion(false, true);
		delete ServerRunAsyncTask;
	}
}