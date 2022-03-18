// Copyright Smartly Dressed Games Ltd. All Rights Reserved.


#include "U4_AdminCommand.h"

bool UU4_AdminCommand::TryGetStringArgument(const FU4_AdminCommandContext& InContext, const FName& InKey, FString OutValue)
{
	return false;
}

void UU4_AdminCommand::LogWarningText(const FU4_AdminCommandContext& InContext, const FText& InMessage)
{
}

void UU4_AdminCommand::LogWarningString(const FU4_AdminCommandContext& InContext, const FString& InMessage)
{
}

void UU4_AdminCommand::LogInfoText(const FU4_AdminCommandContext& InContext, const FText& InMessage)
{
}

void UU4_AdminCommand::LogInfoString(const FU4_AdminCommandContext& InContext, const FString& InMessage)
{
}

void UU4_AdminCommand::LogErrorText(const FU4_AdminCommandContext& InContext, const FText& InMessage)
{
}

void UU4_AdminCommand::LogErrorString(const FU4_AdminCommandContext& InContext, const FString& InMessage)
{
}

bool UU4_AdminCommand::HasPermission(const FU4_AdminCommandContext& InContext, const FName& InPermission)
{
	return false;
}

bool UU4_AdminCommand::HasFlag(const FU4_AdminCommandContext& InContext, const FName& InLongName)
{
	return false;
}

FString UU4_AdminCommand::GetStringArgument(const FU4_AdminCommandContext& InContext, const FName& InKey, const FString& InDefaultValue)
{
	return "";
}

TArray<FString> UU4_AdminCommand::GetOperands(const FU4_AdminCommandContext& InContext)
{
	return TArray<FString>();
}

int UU4_AdminCommand::GetInt32Argument(const FU4_AdminCommandContext& InContext, const FName& InKey, int InDefaultValue)
{
	return 0;
}

APlayerState* UU4_AdminCommand::GetInstigatorPlayerState(const FU4_AdminCommandContext& InContext)
{
	return nullptr;
}

APawn* UU4_AdminCommand::GetInstigatorPawn(const FU4_AdminCommandContext& InContext)
{
	return nullptr;
}

FPrimaryAssetId UU4_AdminCommand::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(FPrimaryAssetType("AdminCommand"), GetFName());
}
