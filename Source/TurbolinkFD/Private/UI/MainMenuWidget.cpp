// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "UI/MainMenuTabInterface.h"

UMainMenuWidget::UMainMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PlayButton = nullptr;
	SettingsButton = nullptr;
	QuitButton = nullptr;
	MainMenuWidgetSwitcher = nullptr;
	SettingsTab = nullptr;
	LevelInstance = nullptr;

	SettingsWidgetIndex = 0;
}

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PlayButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnPlayButtonClicked);
	SettingsButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnSettingsButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnQuitButtonClicked);

	if (MainMenuWidgetSwitcher->AddChild(SettingsTab))
	{
		SettingsWidgetIndex = MainMenuWidgetSwitcher->GetChildIndex(SettingsTab);
	}
}

void UMainMenuWidget::OnPlayButtonClicked()
{
	if (!LevelInstance.IsValid()) return;

	const UWorld* Level = LevelInstance.LoadSynchronous();
	if (!Level) return;

	UE_LOG(LogTemp, Display, TEXT("Getting into next level, level path is: %s"), *LevelInstance.ToString());
	GetWorld()->ServerTravel(LevelInstance.ToString());
}

void UMainMenuWidget::OnSettingsButtonClicked()
{
	MainMenuWidgetSwitcher->SetActiveWidgetIndex(SettingsWidgetIndex);
}

void UMainMenuWidget::OnQuitButtonClicked()
{
	FGenericPlatformMisc::RequestExit(false);
}

void UMainMenuWidget::OnNewTabSelected(UWidget* NewTab)
{
	if (NewTab == CurrentSelectedWidget) return;

	if (IsValid(CurrentSelectedWidget))
	{
		if (IMainMenuTabInterface* MainMenuTabInterface = Cast<IMainMenuTabInterface>(CurrentSelectedWidget))
		{
			MainMenuTabInterface->OnTabHidden();
		}
	}

	CurrentSelectedWidget = NewTab;
	if (IMainMenuTabInterface* MainMenuTabInterface = Cast<IMainMenuTabInterface>(CurrentSelectedWidget))
	{
		MainMenuTabInterface->OnTabSelected();
	}
}

void UMainMenuWidget::InitNewTab(UWidget* NewTab)
{
	if (!IsValid(NewTab)) return;

	if (IMainMenuTabInterface* MainMenuTabInterface = Cast<IMainMenuTabInterface>(NewTab))
	{
		MainMenuTabInterface->InitTab(this);
	}
}