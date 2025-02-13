// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayPlayerController.generated.h"

/**
 * 
 */

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;

UCLASS()
class PROJECTLUNA_API AGameplayPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AGameplayPlayerController(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> MovementInputContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<AActor> ActorToSpawn;

protected:

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupInputComponent() override;

	UFUNCTION()
	void HorizontalMove(const FInputActionValue& Value);

	UFUNCTION()
	void Jump(const FInputActionValue& Value);

	UFUNCTION()
	void UpdateControllerRotation();
};
