// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayPlayerController.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "GameplayCameraManager.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"

AGameplayPlayerController::AGameplayPlayerController(const FObjectInitializer& ObjectInitializer)
{
	PlayerCameraManagerClass = AGameplayCameraManager::StaticClass();

	const TObjectPtr<UWorld> world = GetWorld();
	if (!IsValid(world))
	{
		return;
	}

	const TObjectPtr<APawn> pawn = GetPawn();
	if (!IsValid(pawn))
	{
		return;
	}

	world-
}



