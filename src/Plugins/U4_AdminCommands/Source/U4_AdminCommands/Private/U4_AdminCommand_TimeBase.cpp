// Copyright Smartly Dressed Games Ltd. All Rights Reserved.


#include "U4_AdminCommand_TimeBase.h"

void UU4_AdminCommand_TimeBase::SetNormalizedTimeOfDay(float InNormalizedTimeOfDay)
{
}

void UU4_AdminCommand_TimeBase::SetNamedTimeOfYear(const FU4_AdminCommandContext& InContext, U4_EU4_NamedTimeOfYear InTimeOfYear)
{
}

void UU4_AdminCommand_TimeBase::SetNamedTimeOfDay(const FU4_AdminCommandContext& InContext, U4_EU4_NamedTimeOfDay InTimeOfDay)
{
}

void UU4_AdminCommand_TimeBase::SetNamedLunarPhase(const FU4_AdminCommandContext& InContext, U4_EU4_NamedLunarPhase InLunarPhase)
{
}

bool UU4_AdminCommand_TimeBase::ParseTimespan(const FU4_AdminCommandContext& InContext, const FString& InValue, FTimespan& OutValue)
{
    return false;
}

void UU4_AdminCommand_TimeBase::AddTimespan(const FTimespan& InTimespan)
{
}
