// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CharacterController.generated.h"

/**
 * 
 */

class FInputActionValue;
class UInputMappingContext;
class UInputAction;

UCLASS()
class PROJECTLUNA_API ACharacterController : public APlayerController
{
	GENERATED_BODY()

public:

	ACharacterController(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	TObjectPtr<UInputMappingContext> MovementContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	TObjectPtr<UInputAction> MovementInputAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	TObjectPtr<UInputAction> JumpInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AActor> ActorToSpawn;

	UFUNCTION(BlueprintCallable)
	void SpawnCharacter();

protected:

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupInputComponent() override;

	UFUNCTION()
	void SideMove(const FInputActionValue& value);
	

	UFUNCTION()
	void Jump(const FInputActionValue& value);

	UFUNCTION()
	void UpdateCharacterControllerRotation();
};
