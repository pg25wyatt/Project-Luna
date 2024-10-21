// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "Runtime/Datasmith/DatasmithCore/Public/DatasmithDefinitions.h"

ACharacterController::ACharacterController(const FObjectInitializer& ObjectInitializer)
{
	// Initialize and create reference to the camera manager
}

void ACharacterController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ACharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
