// Copyright Smartly Dressed Games Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "U4_AdminCommand.h"
#include "U4_AdminCommand_TimeBase.generated.h"

UENUM(BlueprintType)
enum class U4_EU4_NamedTimeOfYear : uint8
{
    EU4_NamedTimeOfYear__MarchEquinox = 0,
    EU4_NamedTimeOfYear__JuneSolstice = 1,
    EU4_NamedTimeOfYear__SeptemberEquinox = 2,
    EU4_NamedTimeOfYear__DecemberSolstice = 3,
    EU4_NamedTimeOfYear__NorthernVernalEquinox = 4,
    EU4_NamedTimeOfYear__NorthernSummerSolstice = 5,
    EU4_NamedTimeOfYear__NorthernAutumnalEquinox = 6,
    EU4_NamedTimeOfYear__NorthernWinterSolstice = 7,
    EU4_NamedTimeOfYear__SouthernVernalEquinox = 8,
    EU4_NamedTimeOfYear__SouthernSummerSolstice = 9,
    EU4_NamedTimeOfYear__SouthernAutumnalEquinox = 10,
    EU4_NamedTimeOfYear__SouthernWinterSolstice = 11,
    EU4_NamedTimeOfYear__EU4_MAX = 12,

};

UENUM(BlueprintType)
enum class U4_EU4_NamedTimeOfDay : uint8
{
    EU4_NamedTimeOfDay__Dawn = 0,
    EU4_NamedTimeOfDay__Sunrise = 1,
    EU4_NamedTimeOfDay__SolarNoon = 2,
    EU4_NamedTimeOfDay__Sunset = 3,
    EU4_NamedTimeOfDay__Dusk = 4,
    EU4_NamedTimeOfDay__SolarMidnight = 5,
    EU4_NamedTimeOfDay__EU4_MAX = 6,

};

UENUM(BlueprintType)
enum class U4_EU4_NamedLunarPhase : uint8
{
    EU4_NamedLunarPhase__New = 0,
    EU4_NamedLunarPhase__WaxingCrescent = 1,
    EU4_NamedLunarPhase__WaxingQuarter = 2,
    EU4_NamedLunarPhase__WaxingGibous = 3,
    EU4_NamedLunarPhase__Full = 4,
    EU4_NamedLunarPhase__WaningGibous = 5,
    EU4_NamedLunarPhase__WaningQuarter = 6,
    EU4_NamedLunarPhase__WaningCrescent = 7,
    EU4_NamedLunarPhase__EU4_MAX = 8,
};

UCLASS(Abstract, Blueprintable)
class U4_ADMINCOMMANDS_API UU4_AdminCommand_TimeBase : public UU4_AdminCommand
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
        void SetNormalizedTimeOfDay(float InNormalizedTimeOfDay);

    UFUNCTION(BlueprintCallable)
        void SetNamedTimeOfYear(const FU4_AdminCommandContext& InContext, U4_EU4_NamedTimeOfYear InTimeOfYear);

    UFUNCTION(BlueprintCallable)
        void SetNamedTimeOfDay(const FU4_AdminCommandContext& InContext, U4_EU4_NamedTimeOfDay InTimeOfDay);

    UFUNCTION(BlueprintCallable)
        void SetNamedLunarPhase(const FU4_AdminCommandContext& InContext, U4_EU4_NamedLunarPhase InLunarPhase);

    UFUNCTION(BlueprintCallable)
        bool ParseTimespan(const FU4_AdminCommandContext& InContext, const FString& InValue, FTimespan& OutValue);

    UFUNCTION(BlueprintCallable)
        void AddTimespan(const FTimespan& InTimespan);
};
