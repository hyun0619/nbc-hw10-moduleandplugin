// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sample_NBC_Log_Plugin.h"

#define LOCTEXT_NAMESPACE "FSample_NBC_Log_PluginModule"

void FSample_NBC_Log_PluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FSample_NBC_Log_PluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSample_NBC_Log_PluginModule, Sample_NBC_Log_Plugin)