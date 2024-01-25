// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SettingsWidget.h"

USettingsWidget::USettingsWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ApplyButton = nullptr;
}

void USettingsWidget::InitTab(UWidget* InParentWidget)
{
	Super::InitTab(InParentWidget);

	
}

void USettingsWidget::OnTabSelected()
{
	Super::OnTabSelected();

	
}

void USettingsWidget::OnTabHidden()
{
	Super::OnTabHidden();
}
