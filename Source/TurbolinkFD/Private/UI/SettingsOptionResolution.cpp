// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SettingsOptionResolution.h"

#include "UI/UIDataStruct.h"

FText USettingsOptionResolution::GetTextForIndex_Implementation(const int32& Index) const
{
	FSettingsOptionResolutionData SettingsOptionResolutionData;

	if (Index >= SettingsOptionResolutionData.Resolutions.Num() || Index < 0) return FText::GetEmpty();

	return SettingsOptionResolutionData.Resolutions[Index];
}
