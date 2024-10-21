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

protected:

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupInputComponent() override;
};
