// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingsOption.generated.h"

class UButton;
class UTextBlock;

/**
 * Handles logic to change settings option by clicking left or right arrow
 */
UCLASS()
class TURBOLINKFD_API USettingsOption : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category = "Settings Option")
	FText GetTextForIndex(const int32& Index) const;

	UFUNCTION(BlueprintPure, Category = "Settings Option|Getters")
	FORCEINLINE int32 GetCurrentIndex() const { return CurrentIndex; }

	void RedrawOptionWithNewIndex(const int32& NewIndex);
	
protected:
	USettingsOption(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> LeftArrowButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> RightArrowButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> LeftArrowText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> RightArrowText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> OptionText;

	UFUNCTION(BlueprintPure, Category = "Settings Option|Getters")
	FORCEINLINE int32 GetMaxIndex() const { return MaxIndex; }

private:
	void RedrawText() const;
	
	UFUNCTION()
	void OnLeftArrowButtonClicked();

	UFUNCTION()
	void OnRightArrowButtonClicked();
	
	int32 CurrentIndex;
	int32 MaxIndex;
};
