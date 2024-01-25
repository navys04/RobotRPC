// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SettingsOption.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "UI/UIDataStruct.h"

void USettingsOption::RedrawOptionWithNewIndex(const int32& NewIndex)
{
	CurrentIndex = NewIndex;
	RedrawText();
}

USettingsOption::USettingsOption(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	LeftArrowButton = nullptr;
	RightArrowButton = nullptr;
	LeftArrowText = nullptr;
	RightArrowText = nullptr;

	CurrentIndex = 0;
	MaxIndex = 0;
}

void USettingsOption::NativeConstruct()
{
	Super::NativeConstruct();

	LeftArrowText->SetText(FText::FromString("<"));
	RightArrowText->SetText(FText::FromString(">"));

	LeftArrowButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnLeftArrowButtonClicked);
	RightArrowButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnRightArrowButtonClicked);
}

void USettingsOption::RedrawText() const
{
	OptionText->SetText(GetTextForIndex(CurrentIndex));
}

void USettingsOption::OnLeftArrowButtonClicked()
{
	CurrentIndex--;

	if (CurrentIndex < 0) CurrentIndex = MaxIndex;

	RedrawText();
}

void USettingsOption::OnRightArrowButtonClicked()
{
	CurrentIndex++;

	if (CurrentIndex >= MaxIndex) CurrentIndex = 0;

	RedrawText();
}

FText USettingsOption::GetTextForIndex_Implementation(const int32& Index) const
{
	FSettingsOptionDefaultData OptionDefaultData;

	if (Index >= OptionDefaultData.QualityDisplayInfos.Num() || Index < 0)
	{
		return FText::GetEmpty();
	}

	return OptionDefaultData.QualityDisplayInfos[Index];
}