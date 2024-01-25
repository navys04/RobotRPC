// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuTabBase.h"
#include "SettingsWidget.generated.h"

class UButton;

/**
	Handles all settings functionality. 
 */
UCLASS()
class TURBOLINKFD_API USettingsWidget : public UMainMenuTabBase
{
	GENERATED_BODY()

public:
	
	
protected:
	USettingsWidget(const FObjectInitializer& ObjectInitializer);
	
	// ~IMainMenuTabInterface start
	virtual void InitTab(UWidget* InParentWidget) override;
	virtual void OnTabSelected() override;
	virtual void OnTabHidden() override;
	// ~IMainMenuTabInterface end

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ApplyButton;
};
