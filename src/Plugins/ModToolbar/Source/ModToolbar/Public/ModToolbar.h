// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Slate.h"
#include "ModToolbarPackager.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FModToolbarModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	// When the Create Button is clicked
	void CreateModButtonClicked();

	/** Adds the plugin creator as a new toolbar button */
	void AddModCreatorToolbarExtension(FToolBarBuilder& Builder);

	/** Adds the plugin creator as a new menu option */
	void AddModCreatorMenuExtension(FMenuBuilder& Builder);

	/** Adds the plugin packager as a new toolbar button */
	void AddModPackagerToolbarExtension(FToolBarBuilder& Builder);

	/** Adds the plugin packager as a new menu option */
	void AddModPackagerMenuExtension(FMenuBuilder& Builder);
	
private:

	TSharedPtr<class FModToolbarCreator> ModCreator;
	TSharedPtr<class FModToolbarPackager> ModPackager;
	TSharedPtr<class FUICommandList> PluginCommands;
};