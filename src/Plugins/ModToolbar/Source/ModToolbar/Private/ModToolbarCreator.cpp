// Copyright Epic Games, Inc. All Rights Reserved.

//#include "ModToolbarPrivatePCH.h"
#include "ModToolbarCreator.h"

#include "ModToolbarPluginWizardDefinition.h"
#include "Widgets/Docking/SDockTab.h"

// This depends on the Plugin Browser module to work correctly...
#include "IPluginBrowser.h"



#define LOCTEXT_NAMESPACE "FModToolbarCreator"

const FName FModToolbarCreator::ModToolbarPluginCreatorName("ModToolbarPluginCreator");

FModToolbarCreator::FModToolbarCreator()
{
	RegisterTabSpawner();
}

FModToolbarCreator::~FModToolbarCreator()
{
	UnregisterTabSpawner();
}

void FModToolbarCreator::OpenNewPluginWizard(bool bSuppressErrors) const
{
	if (IPluginBrowser::IsAvailable())
	{
		FGlobalTabmanager::Get()->InvokeTab(ModToolbarPluginCreatorName);
	}
	else if (!bSuppressErrors)
	{
		FMessageDialog::Open(EAppMsgType::Ok,
			LOCTEXT("PluginBrowserDisabled", "Creating a game mod requires the use of the Plugin Browser, but it is currently disabled."));
	}
}

void FModToolbarCreator::RegisterTabSpawner()
{
	FTabSpawnerEntry& Spawner = FGlobalTabmanager::Get()->RegisterNomadTabSpawner(ModToolbarPluginCreatorName,
																FOnSpawnTab::CreateRaw(this, &FModToolbarCreator::HandleSpawnPluginTab));

	// Set a default size for this tab
	FVector2D DefaultSize(800.0f, 500.0f);
	FTabManager::RegisterDefaultTabWindowSize(ModToolbarPluginCreatorName, DefaultSize);

	Spawner.SetDisplayName(LOCTEXT("NewModTabHeader", "Create New Mod Package"));
	Spawner.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FModToolbarCreator::UnregisterTabSpawner()
{
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(ModToolbarPluginCreatorName);
}

TSharedRef<SDockTab> FModToolbarCreator::HandleSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	check(IPluginBrowser::IsAvailable());
	return IPluginBrowser::Get().SpawnPluginCreatorTab(SpawnTabArgs, MakeShared<FModToolbarPluginWizardDefinition>());
}

#undef LOCTEXT_NAMESPACE
