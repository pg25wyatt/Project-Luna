// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"

ACharacterController::ACharacterController(const FObjectInitializer& ObjectInitializer)
{
	// Initialize and create reference to the camera manager
}

void ACharacterController::SpawnCharacter()
{
}

void ACharacterController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ACharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
}

void ACharacterController::SideMove(const FInputActionValue& value)
{
}

void ACharacterController::Jump(const FInputActionValue& value)
{
}

void ACharacterController::UpdateCharacterControllerRotation()
{
}
