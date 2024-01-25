// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuTabBase.h"
#include "SettingsWidget.generated.h"

class UButton;
class USettingsOption;


/**
	Handles all settings functionality. 
 */
UCLASS()
class TURBOLINKFD_API USettingsWidget : public UMainMenuTabBase
{
	GENERATED_BODY()

public:
	inline static const TMap<int32, FIntPoint> Resolutions {
		{ 0, FIntPoint(1920, 1080) },
		{ 1, FIntPoint(1280, 720) }
	};
	
protected:
	USettingsWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;
	
	// ~IMainMenuTabInterface start
	virtual void InitTab(UWidget* InParentWidget) override;
	virtual void OnTabSelected() override;
	virtual void OnTabHidden() override;
	// ~IMainMenuTabInterface end

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingsOption> ResolutionOption;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingsOption> ShadowQualityOption;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingsOption> TextureQualityOption;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USettingsOption> WindowModeOption;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ApplyButton;

private:
	UFUNCTION()
	void OnApplyButtonClicked();
	
	void RedrawWidget();
};

#undef LOCTEXT_NAMESPACE