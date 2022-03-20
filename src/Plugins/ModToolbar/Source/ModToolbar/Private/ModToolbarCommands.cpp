// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModToolbarCommands.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FModToolbarModule"

void FModToolbarCommands::RegisterCommands()
{
	UI_COMMAND(CreateModAction, "Create Mod", "Create a new Mod", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(PackageModAction, "Package Mod", "Share and distribute your Mod", EUserInterfaceActionType::Button, FInputGesture());
}

TArray<TSharedPtr<FUICommandInfo>> FModToolbarCommands::RegisterModCommands(const TArray<TSharedRef<class IPlugin>>& ModList) const
{
	TArray<TSharedPtr<FUICommandInfo>> AvailableModActions;
	AvailableModActions.Reserve(ModList.Num());

	FModToolbarCommands* MutableThis = const_cast<FModToolbarCommands*>(this);

	for (int32 Index = 0; Index < ModList.Num(); ++Index)
	{
		AvailableModActions.Add(TSharedPtr<FUICommandInfo>());
		TSharedRef<IPlugin> Mod = ModList[Index];

		FString CommandName = "ModEditorMod_" + Mod->GetName();

		FUICommandInfo::MakeCommandInfo(MutableThis->AsShared(),
			AvailableModActions[Index],
			FName(*CommandName),
			FText::FromString(Mod->GetName()),
			FText::FromString(Mod->GetBaseDir()),
			FSlateIcon(),
			EUserInterfaceActionType::Button,
			FInputGesture());
	}

	return AvailableModActions;
}

void FModToolbarCommands::UnregisterModCommands(TArray<TSharedPtr<FUICommandInfo>>& UICommands) const
{
	FModToolbarCommands* MutableThis = const_cast<FModToolbarCommands*>(this);

	for (TSharedPtr<FUICommandInfo> Command : UICommands)
	{
		FUICommandInfo::UnregisterCommandInfo(MutableThis->AsShared(), Command.ToSharedRef());
	}
}

#undef LOCTEXT_NAMESPACE
