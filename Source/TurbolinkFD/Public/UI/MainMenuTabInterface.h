// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Components/Widget.h"
#include "MainMenuTabInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UMainMenuTabInterface : public UInterface
{
	GENERATED_BODY()
};

/** Needs to be implemented by all main menu tabs,
 * handles tab selected and tab hidden events
 */
class TURBOLINKFD_API IMainMenuTabInterface
{
	GENERATED_BODY()

public:
	/** Initialize tab and sets parent widget variable */
	virtual void InitTab(UWidget* InParentWidget);
	
	/** Calls when user selected this tab from main menu */
	virtual void OnTabSelected();

	/** Calls when user get into other tab */
	virtual void OnTabHidden();

protected:
	// Blueprint Events
	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Tab Interface", meta = (DisplayName = "InitTab"))
	void K2_InitTab(UWidget* InParentWidget);
	
	UFUNCTION(BlueprintNativeEvent, Category = "Main Menu Tab Interface", meta = (DisplayName = "OnTabSelected"))
	void K2_OnTabSelected();

	UFUNCTION(BlueprintNativeEvent, Category = "Main Menu Tab Interface", meta = (DisplayName = "OnTabHidden"))
	void K2_OnTabHidden();
};
