// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIDataStruct.generated.h"

#define LOCTEXT_NAMESPACE "UIDataOptions"

USTRUCT(Blueprintable, BlueprintType)
struct FSettingsOptionDefaultData
{
	GENERATED_BODY();
	
	UPROPERTY(BlueprintReadOnly, Category = "Settings Option Default Data")
	TMap<int32, FText> QualityDisplayInfos {
				{ 0, LOCTEXT("QualitySettingLow", "Low") },
				{ 1, LOCTEXT("QualitySettingMedium", "Medium") },
				{ 2, LOCTEXT("QualitySettingHigh", "High") },
				{ 3, LOCTEXT("QualitySettingUltra", "Ultra") },
				{ 4, LOCTEXT("QualitySettingCinematic", "Cinematic") }
	};
};

USTRUCT(Blueprintable, BlueprintType)
struct FSettingsOptionWindowModeData
{
	GENERATED_BODY();
	
	UPROPERTY(BlueprintReadOnly, Category = "Settings Option Window Mode Data")
	TMap<int32, FText> FullscreenTypes {
					{ 0, LOCTEXT("FullscreenMode", "Fullscreen") },
					{ 1, LOCTEXT("WindowedFullscreenMode", "WindowedFullscreen") },
					{ 2, LOCTEXT("WindowedMode", "Windowed") }
	};
};

USTRUCT(Blueprintable, BlueprintType)
struct FSettingsOptionResolutionData
{
	GENERATED_BODY();
	
	UPROPERTY(BlueprintReadOnly, Category = "Settings Option Resolution Data")
	TMap<int32, FText> Resolutions {
			{ 0, FText::FromString("1920x1080") },
			{ 1, FText::FromString("1280x720") }
	};
};

#undef LOCTEXT_NAMESPACE