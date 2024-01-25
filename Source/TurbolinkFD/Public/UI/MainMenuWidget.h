// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;

/**
	Main menu widget. Have Start, Settings and Quit tabs 
 */
UCLASS()
class TURBOLINKFD_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UMainMenuWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;

	// Buttons
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	TObjectPtr<UButton> PlayButton;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	TObjectPtr<UButton> SettingsButton;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	TObjectPtr<UButton> QuitButton;
	
	// Tabs
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	TObjectPtr<class UWidgetSwitcher> MainMenuWidgetSwitcher;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	TObjectPtr<UWidget> SettingsTab;

	// Play Game Section
	UPROPERTY()
	TSoftObjectPtr<UWorld> LevelInstance;

	UPROPERTY(BlueprintReadOnly, Category = "Main Menu Widget")
	TObjectPtr<UWidget> CurrentSelectedWidget;

private:
	UFUNCTION()
	void OnPlayButtonClicked();

	UFUNCTION()
	void OnSettingsButtonClicked();

	UFUNCTION()
	void OnQuitButtonClicked();

	void OnNewTabSelected(UWidget* NewTab);
	void InitNewTab(UWidget* NewTab);

	int32 SettingsWidgetIndex;
};
