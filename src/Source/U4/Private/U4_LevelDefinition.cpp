// Copyright Smartly Dressed Games Ltd. All Rights Reserved.


#include "U4_LevelDefinition.h"

FPrimaryAssetId UU4_LevelDefinition::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(FPrimaryAssetType("LevelDefinition"), GetFName());
}
