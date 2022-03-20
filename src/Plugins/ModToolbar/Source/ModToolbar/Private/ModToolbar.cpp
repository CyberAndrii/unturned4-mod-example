// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModToolbar.h"
#include "ModToolbarStyle.h"
#include "ModToolbarCommands.h"
#include "ModToolbarCreator.h"
#include "Misc/MessageDialog.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "LevelEditor.h"

static const FName ModToolbarTabName("ModToolbar");

#define LOCTEXT_NAMESPACE "FModToolbarModule"

void FModToolbarModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	ModCreator = MakeShared<FModToolbarCreator>();
	ModPackager = MakeShared<FModToolbarPackager>();

	FModToolbarStyle::Initialize();
	FModToolbarStyle::ReloadTextures();

	FModToolbarCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FModToolbarCommands::Get().CreateModAction,
		FExecuteAction::CreateRaw(this, &FModToolbarModule::CreateModButtonClicked),
		FCanExecuteAction()
	);

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	// Add commands
	{
		FName MenuSection = "FileProject";
		FName ToolbarSection = "Misc";

		// Add creator button to the menu
		{
			TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
			MenuExtender->AddMenuExtension(MenuSection, EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FModToolbarModule::AddModCreatorMenuExtension));

			LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
		}

		// Add creator button to the toolbar
		{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
			ToolbarExtender->AddToolBarExtension(ToolbarSection, EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FModToolbarModule::AddModCreatorToolbarExtension));

			LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
		}

		// Add packager button to the menu
		{
			TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
			MenuExtender->AddMenuExtension(MenuSection, EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FModToolbarModule::AddModPackagerMenuExtension));

			LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
		}

		// Add packager button to the toolbar
		{
			TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
			ToolbarExtender->AddToolBarExtension(ToolbarSection, EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FModToolbarModule::AddModPackagerToolbarExtension));

			LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
		}
	}
}

void FModToolbarModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FModToolbarStyle::Shutdown();

	FModToolbarCommands::Unregister();

}

void FModToolbarModule::CreateModButtonClicked()
{
	if (ModCreator.IsValid())
	{
		ModCreator->OpenNewPluginWizard();
	}
}

void FModToolbarModule::AddModCreatorMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FModToolbarCommands::Get().CreateModAction);
}

void FModToolbarModule::AddModCreatorToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FModToolbarCommands::Get().CreateModAction);
}

void FModToolbarModule::AddModPackagerMenuExtension(FMenuBuilder& Builder)
{
	FModToolbarPackager* Packager = ModPackager.Get();

	Builder.AddSubMenu(LOCTEXT("PackageModMenu_Label", "Package Mod"),
		LOCTEXT("PackageModMenu_Tooltip", "Share and distribute Mod"),
		FNewMenuDelegate::CreateRaw(Packager, &FModToolbarPackager::GeneratePackagerMenuContent),
		false,
		FSlateIcon(FModToolbarStyle::GetStyleSetName(), "ModToolbar.PackageModAction")
	);
}

void FModToolbarModule::AddModPackagerToolbarExtension(FToolBarBuilder& Builder)
{
	FModToolbarPackager* Packager = ModPackager.Get();

	Builder.AddComboButton(FUIAction(),
		FOnGetContent::CreateSP(Packager, &FModToolbarPackager::GeneratePackagerComboButtonContent),
		LOCTEXT("PackageMod_Label", "Package Mod"),
		LOCTEXT("PackageMod_Tooltip", "Share and distribute Mod"),
		FSlateIcon(FModToolbarStyle::GetStyleSetName(), "ModToolbar.PackageModAction")
	);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FModToolbarModule, ModToolbar)
