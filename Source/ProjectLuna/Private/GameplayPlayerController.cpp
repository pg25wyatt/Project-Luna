// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayPlayerController.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "GameplayCameraManager.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "ProjectLunaLibrary.h"
#include "Kismet/KismetMathLibrary.h"

AGameplayPlayerController::AGameplayPlayerController(const FObjectInitializer& ObjectInitializer)
{
	PlayerCameraManagerClass = AGameplayCameraManager::StaticClass();
}

void AGameplayPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateControllerRotation();
}

void AGameplayPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}

void AGameplayPlayerController::HorizontalMove(const FInputActionValue& Value)
{
}

void AGameplayPlayerController::Jump(const FInputActionValue& Value)
{
}

void AGameplayPlayerController::UpdateControllerRotation()
{
	FVector avgLocation = UProjectLunaLibrary::GetPositionBetweenCharacters(this);

	const TObjectPtr<APawn> owningPawn = GetPawn();
	if (!IsValid(owningPawn))
	{
		return;
	}

	const FRotator lookRotation = UKismetMathLibrary::FindLookAtRotation(owningPawn->GetActorLocation(), avgLocation);

	SetControlRotation(FRotator(0.0f, lookRotation.Yaw, 0.0f));
}

