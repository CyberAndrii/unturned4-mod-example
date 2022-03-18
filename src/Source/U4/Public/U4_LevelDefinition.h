// Copyright Smartly Dressed Games Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "U4_LevelDefinition.generated.h"

UCLASS(BlueprintType)
class U4_API UU4_LevelDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FSoftObjectPath Map;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FGuid LevelGuid;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
