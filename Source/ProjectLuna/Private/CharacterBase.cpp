// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "Animation/AnimMontage.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterBase::LightAttack(const FInputActionValue& value)
{
	if (!IsValid(LightAttackAnimation))
	{
		return;
	}

	PlayAnimMontage(LightAttackAnimation);
}

void ACharacterBase::MediumAttack(const FInputActionValue& value)
{
	if (!IsValid(MediumAttackAction))
	{
		return;
	}

	PlayAnimMontage(MediumAttackAnimation);
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	const TObjectPtr<AController> controller = GetController();
	if (TObjectPtr<APlayerController> playerCon = Cast<APlayerController>(Controller))
	{
		UEnhancedInputLocalPlayerSubsystem* enhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerCon->GetLocalPlayer());

		UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);
		if (IsValid(InputComp))
		{
			if (IsValid(LightAttackAction))
			{
				InputComp->BindAction(LightAttackAction, ETriggerEvent::Triggered, this, &ACharacterBase::LightAttack);
			}

			if (IsValid(MediumAttackAction))
			{
				InputComp->BindAction(MediumAttackAction, ETriggerEvent::Triggered, this, &ACharacterBase::MediumAttack);
			}
		}
	}

}

