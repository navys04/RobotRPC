// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RobotCharacter.generated.h"

/** Character class to demonstrate how Unreal Engine project works as a gRPC server.
 * Here we are handling gRPC's Robot Service methods and reacting to change of linear and angular speed
 */
UCLASS()
class TURBOLINKFD_API ARobotCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARobotCharacter();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnAngularSpeedChanged(const float& NewAngularSpeed);

	UFUNCTION()
	void OnLinearSpeedChanged(const float& NewLinearSpeed);
};