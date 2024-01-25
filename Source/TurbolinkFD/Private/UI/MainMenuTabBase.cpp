// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuTabBase.h"

void UMainMenuTabBase::InitTab(UWidget* InParentWidget)
{
	IMainMenuTabInterface::InitTab(InParentWidget);

	ParentWidget = InParentWidget;
}

void UMainMenuTabBase::OnTabSelected()
{
	IMainMenuTabInterface::OnTabSelected();
}

void UMainMenuTabBase::OnTabHidden()
{
	IMainMenuTabInterface::OnTabHidden();
}
