// Copyright Smartly Dressed Games Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "U4_AdminCommand.h"
#include "U4_GameModeBase.generated.h"

UCLASS()
class U4_API AU4_GameModeBase : public AGameMode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 bEnablePersistence : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 bRequireNumPlayersToStartMatch : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 NumPlayersRequiredToStartMatch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<FName, UU4_AdminCommand*> AdminCommands;

public:
	UFUNCTION(BlueprintCallable)
		void SendTextChatMessage(const FString& InMessage);

	UFUNCTION(BlueprintCallable)
		void SendTextChatLocalizedMessage(const FText& InMessage);
};
