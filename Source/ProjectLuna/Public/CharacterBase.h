// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

struct FInputActionValue;
class UInputAction;
class UAnimMontage;

UCLASS()
class PROJECTLUNA_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

	// Setup Animations
	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> LightAttackAnimation;

	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> MediumAttackAnimation;

	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> HeavyAttackAnimation;

	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> SpecialAttackAnimation;

	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> SpecialAbilityAnimation;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Setup Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	TObjectPtr<UInputAction> LightAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	TObjectPtr<UInputAction> MediumAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	TObjectPtr<UInputAction> HeavyAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	TObjectPtr<UInputAction> SpecialAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	TObjectPtr<UInputAction> SpecialAbilityAction;

	// Setup Attack Functions
	UFUNCTION(BlueprintCallable)
	void LightAttack(const FInputActionValue& value);

	UFUNCTION(BlueprintCallable)
	void MediumAttack(const FInputActionValue& value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
