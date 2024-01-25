// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuTabInterface.h"

void IMainMenuTabInterface::InitTab(UWidget* InParentWidget)
{
	K2_InitTab(InParentWidget);
}

void IMainMenuTabInterface::OnTabSelected()
{
	K2_OnTabSelected();
}

void IMainMenuTabInterface::OnTabHidden()
{
	K2_OnTabHidden();
}
