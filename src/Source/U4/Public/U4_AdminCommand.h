// Copyright Smartly Dressed Games Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "U4_AdminCommand.generated.h"

USTRUCT(BlueprintType)
struct U4_API FU4_AdminCommandArguments
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
		TArray<FName> Switches;

	UPROPERTY(BlueprintReadWrite)
		TMap<FName, FString> Parameters;

	UPROPERTY(BlueprintReadWrite)
		TArray<FString> Operands;
};

USTRUCT(BlueprintType)
struct U4_API FU4_AdminCommandContext
{
	GENERATED_BODY()

public:
	//UPROPERTY(BlueprintReadWrite)
	//	unsigned char Instigator[0x10]; // unknown type

	UPROPERTY(BlueprintReadWrite)
		FU4_AdminCommandArguments Arguments;
};

UENUM(BlueprintType)
enum class U4_EU4_AdminCommandParameterUsage : uint8
{
	EU4_AdminCommandParameterUsage__Flag = 0,
	EU4_AdminCommandParameterUsage__Value = 1,
	EU4_AdminCommandParameterUsage__EU4_MAX = 2,
};

USTRUCT(BlueprintType)
struct U4_API FU4_AdminCommandParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		U4_EU4_AdminCommandParameterUsage Usage;

	//unsigned char UnknownData_IYMC[0x7]; // unknown type 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FName> Aliases;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText HelpText;
};

UCLASS(Abstract, Blueprintable, BlueprintType, NotPlaceable)
class U4_API UU4_AdminCommand : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FName> Aliases;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText HelpText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FU4_AdminCommandParameter> Parameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Permission;

	UFUNCTION(BlueprintCallable)
		bool TryGetStringArgument(const FU4_AdminCommandContext& InContext, const FName& InKey, FString OutValue);

	UFUNCTION(BlueprintCallable)
		void LogWarningText(const FU4_AdminCommandContext& InContext, const FText& InMessage);

	UFUNCTION(BlueprintCallable)
		void LogWarningString(const FU4_AdminCommandContext& InContext, const FString& InMessage);

	UFUNCTION(BlueprintCallable)
		void LogInfoText(const FU4_AdminCommandContext& InContext, const FText& InMessage);

	UFUNCTION(BlueprintCallable)
		void LogInfoString(const FU4_AdminCommandContext& InContext, const FString& InMessage);

	UFUNCTION(BlueprintCallable)
		void LogErrorText(const FU4_AdminCommandContext& InContext, const FText& InMessage);

	UFUNCTION(BlueprintCallable)
		void LogErrorString(const FU4_AdminCommandContext& InContext, const FString& InMessage);

	UFUNCTION(BlueprintCallable)
		bool HasPermission(const FU4_AdminCommandContext& InContext, const FName& InPermission);

	UFUNCTION(BlueprintCallable)
		bool HasFlag(const FU4_AdminCommandContext& InContext, const FName& InLongName);

	UFUNCTION(BlueprintCallable)
		FString GetStringArgument(const FU4_AdminCommandContext& InContext, const FName& InKey, const FString& InDefaultValue);

	UFUNCTION(BlueprintCallable)
		TArray<FString> GetOperands(const FU4_AdminCommandContext& InContext);

	UFUNCTION(BlueprintCallable)
		int GetInt32Argument(const FU4_AdminCommandContext& InContext, const FName& InKey, int InDefaultValue);

	UFUNCTION(BlueprintCallable)
		APlayerState* GetInstigatorPlayerState(const FU4_AdminCommandContext& InContext);

	UFUNCTION(BlueprintCallable)
		APawn* GetInstigatorPawn(const FU4_AdminCommandContext& InContext);

	//class AU4_PlayerController* GetInstigatorController(const struct FU4_AdminCommandContext& InContext);

	UFUNCTION(BlueprintImplementableEvent)
		void ExecuteCommand(const FU4_AdminCommandContext& InContext);

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
