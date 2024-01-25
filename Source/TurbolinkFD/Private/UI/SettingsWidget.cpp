// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SettingsWidget.h"
#include "Components/Button.h"
#include "GameFramework/GameUserSettings.h"
#include "UI/SettingsOption.h"

const TMap<int32, FIntPoint> Resolutions = USettingsWidget::Resolutions;

USettingsWidget::USettingsWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ApplyButton = nullptr;
}

void USettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ApplyButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnApplyButtonClicked);
	RedrawWidget();
}

void USettingsWidget::InitTab(UWidget* InParentWidget)
{
	Super::InitTab(InParentWidget);

	RedrawWidget();
}

void USettingsWidget::OnTabSelected()
{
	Super::OnTabSelected();

	RedrawWidget();
}

void USettingsWidget::OnTabHidden()
{
	Super::OnTabHidden();
}

void USettingsWidget::OnApplyButtonClicked()
{
	UGameUserSettings* GameUserSettings = UGameUserSettings::GetGameUserSettings();

	if (const FIntPoint* Resolution = Resolutions.Find(ResolutionOption->GetCurrentIndex()))
	{
		GameUserSettings->SetScreenResolution(*Resolution);
	}

	GameUserSettings->SetShadowQuality(ShadowQualityOption->GetCurrentIndex());
	GameUserSettings->SetTextureQuality(TextureQualityOption->GetCurrentIndex());
	GameUserSettings->SetFullscreenMode(static_cast<EWindowMode::Type>(WindowModeOption->GetCurrentIndex()));
}

void USettingsWidget::RedrawWidget()
{
	const UGameUserSettings* GameUserSettings = UGameUserSettings::GetGameUserSettings();

	if (const int32* Key = Resolutions.FindKey(GameUserSettings->GetScreenResolution()))
	{
		ResolutionOption->RedrawOptionWithNewIndex(*Key);
	}

	ShadowQualityOption->RedrawOptionWithNewIndex(GameUserSettings->GetShadowQuality());
	TextureQualityOption->RedrawOptionWithNewIndex(GameUserSettings->GetTextureQuality());
	WindowModeOption->RedrawOptionWithNewIndex(GameUserSettings->GetFullscreenMode());
}
