﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SettingsOption.h"
#include "SettingsOptionWindowMode.generated.h"


UCLASS()
class TURBOLINKFD_API USettingsOptionWindowMode : public USettingsOption
{
	GENERATED_BODY()

public:
	virtual FText GetTextForIndex_Implementation(const int32& Index) const override;
};
