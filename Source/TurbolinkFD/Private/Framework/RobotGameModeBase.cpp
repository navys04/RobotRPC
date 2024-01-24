// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/RobotGameModeBase.h"

#include "Subsystems/RPCServerSubsystem.h"

void ARobotGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld()) GetGameInstance()->GetSubsystem<URPCServerSubsystem>()->StartServer();
}

void ARobotGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (GetWorld()) GetGameInstance()->GetSubsystem<URPCServerSubsystem>()->StopServer();
}