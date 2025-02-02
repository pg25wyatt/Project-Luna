// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "Engine/DataAsset.h"
#include "GameplayCameraManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UGameplayCameraData : public UDataAsset
{
	GENERATED_BODY()
public:

	// Camera Placement Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CameraOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CameraRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CameraDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CameraFOV;
	
};

UCLASS()
class PROJECTLUNA_API AGameplayCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

	virtual void UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime) override;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UGameplayCameraData> CameraData;
	
};
