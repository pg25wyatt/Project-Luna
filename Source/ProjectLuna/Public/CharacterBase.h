// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UInputAction;

UCLASS()
class PROJECTLUNA_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

	// Setup animations
	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> LightAttack;

	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> MediumAttack;

	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> HeavyAttack;

	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> SpecialAttack;

	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> SpecialAbility;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Setup input actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputAction> LightAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputAction> MediumAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputAction> HeavyAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputAction> SpecialAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputAction> SpecialAbilityAction;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
