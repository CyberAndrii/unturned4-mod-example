// Copyright Epic Games, Inc. All Rights Reserved.

#include "U4_AdminCommands.h"

#define LOCTEXT_NAMESPACE "FU4_AdminCommandsModule"

void FU4_AdminCommandsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FU4_AdminCommandsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FU4_AdminCommandsModule, U4_AdminCommands)