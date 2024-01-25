// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SettingsOptionWindowMode.h"

#include "UI/UIDataStruct.h"

FText USettingsOptionWindowMode::GetTextForIndex_Implementation(const int32& Index) const
{
	FSettingsOptionWindowModeData SettingsOptionWindowModeData;

	if (Index >= SettingsOptionWindowModeData.FullscreenTypes.Num() || Index < 0) return FText::GetEmpty();
	
	return SettingsOptionWindowModeData.FullscreenTypes[Index];
}
