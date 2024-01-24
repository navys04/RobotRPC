// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RobotGameModeBase.generated.h"

/** GameMode class here is handling server start and server end when game is started and game is ended
 * So, why just not copy here code of subsystem and delete it? Because if in future we need to start server when game is not started
 * we won't do this. At this time we have code what handling server start and server end at any lifetime period of engine (from engine started)
 */
UCLASS()
class TURBOLINKFD_API ARobotGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
