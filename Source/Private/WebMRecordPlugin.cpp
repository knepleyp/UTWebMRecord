// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "WebMRecord.h"

#include "Core.h"
#include "Engine.h"
#include "ModuleManager.h"
#include "ModuleInterface.h"
#include "Engine/World.h"

IMPLEMENT_MODULE( FWebMRecordPlugin, WebMRecord )

void FWebMRecordPlugin::StartupModule()
{
	// Make an actor that ticks
	FWebMRecord* WebMRecorder = new FWebMRecord();

	FWorldDelegates::FWorldInitializationEvent::FDelegate OnWorldCreatedDelegate = FWorldDelegates::FWorldInitializationEvent::FDelegate::CreateRaw(WebMRecorder, &FWebMRecord::OnWorldCreated);
	FDelegateHandle OnWorldCreatedDelegateHandle = FWorldDelegates::OnPostWorldInitialization.Add(OnWorldCreatedDelegate);

	FWorldDelegates::FWorldEvent::FDelegate OnWorldDestroyedDelegate = FWorldDelegates::FWorldEvent::FDelegate::CreateRaw(WebMRecorder, &FWebMRecord::OnWorldDestroyed);
	FDelegateHandle OnWorldDestroyedDelegateHandle = FWorldDelegates::OnPreWorldFinishDestroy.Add(OnWorldDestroyedDelegate);
}


void FWebMRecordPlugin::ShutdownModule()
{
}