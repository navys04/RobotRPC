// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuTabInterface.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuTabBase.generated.h"

/**
 * 
 */
UCLASS()
class TURBOLINKFD_API UMainMenuTabBase : public UUserWidget, public IMainMenuTabInterface
{
	GENERATED_BODY()

protected:
	// ~IMainMenuTabInterface start
	virtual void InitTab(UWidget* InParentWidget) override;
	virtual void OnTabSelected() override;
	virtual void OnTabHidden() override;
	// ~IMainMenuTabInterface end
	
	// Helper functions
	UFUNCTION(BlueprintPure, Category = "Main Menu Tab Interface|Getters", meta = (DisplayName = "GetParentWidget"))
	UWidget* K2_GetParentWidget() const { return ParentWidget; }
	
	template<class T>
	FORCEINLINE T* GetParentWidget() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, UWidget>::Value, "'T' template parameter to GetParentWidget should derive from UWidget");

		if (!IsValid(ParentWidget))
		{
			return nullptr;
		}

		return Cast<T>(ParentWidget);
	}

private:
	UPROPERTY()
	TObjectPtr<UWidget> ParentWidget;
};
