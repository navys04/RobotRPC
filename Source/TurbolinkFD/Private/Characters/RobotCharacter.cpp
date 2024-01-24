// Fill out your copyright notice in the Description page of Project Settings.


#include "TurbolinkFD/Public/Characters/RobotCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Subsystems/RPCServerSubsystem.h"


ARobotCharacter::ARobotCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ARobotCharacter::BeginPlay()
{
	Super::BeginPlay();

	URPCServerSubsystem* ServerSubsystem = GetGameInstance()->GetSubsystem<URPCServerSubsystem>();
	if (!IsValid(ServerSubsystem))
	{
		UE_LOG(LogTemp, Error, TEXT("Server subsystem is not valid, check this"));
		return;
	}

	ServerSubsystem->OnAngularSpeedChanged.AddUniqueDynamic(this, &ThisClass::OnAngularSpeedChanged);
	ServerSubsystem->OnLinearSpeedChanged.AddUniqueDynamic(this, &ThisClass::OnLinearSpeedChanged);
}

void ARobotCharacter::OnAngularSpeedChanged(const float& NewAngularSpeed)
{
	GetCharacterMovement()->RotationRate = FRotator(0.0f, NewAngularSpeed, 0.0f);

	UE_LOG(LogTemp, Display, TEXT("Angular speed changed to %f"), NewAngularSpeed);
}

void ARobotCharacter::OnLinearSpeedChanged(const float& NewLinearSpeed)
{
	GetCharacterMovement()->MaxWalkSpeed = NewLinearSpeed;
	
	UE_LOG(LogTemp, Display, TEXT("Linear speed changed to %f"), NewLinearSpeed);
}
