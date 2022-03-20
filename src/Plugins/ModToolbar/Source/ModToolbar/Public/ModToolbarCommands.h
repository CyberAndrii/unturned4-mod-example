// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "ModToolbarStyle.h"

class FModToolbarCommands : public TCommands<FModToolbarCommands>
{
public:

	FModToolbarCommands()
		: TCommands<FModToolbarCommands>(TEXT("ModToolbar"), NSLOCTEXT("Contexts", "ModToolbar", "ModToolbar Plugin"), NAME_None, FModToolbarStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

	TArray<TSharedPtr<FUICommandInfo>> RegisterModCommands(const TArray<TSharedRef<class IPlugin>>& ModList) const;
	void UnregisterModCommands(TArray<TSharedPtr<FUICommandInfo>>& UICommands) const;

public:
	TSharedPtr< FUICommandInfo > CreateModAction;
	TSharedPtr< FUICommandInfo > PackageModAction;
};