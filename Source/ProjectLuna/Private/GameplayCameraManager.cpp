// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayCameraManager.h"
#include "ProjectLunaLibrary.h"
#include "GameFramework/GameState.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

void AGameplayCameraManager::UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime)
{
	FVector location = GetCameraLocation();
	FRotator rotation = GetCameraRotation();

	if (!IsValid(CameraData))
	{
		return;
	}

	TArray<TObjectPtr<AActor>> pawns;

	// Get average character location from ProjectLunaLibrary
	FVector averageLocation = UProjectLunaLibrary::GetPositionBetweenCharacters(this);
	averageLocation += CameraData->CameraOffset;

	FVector lerpLocation = FMath::VInterpTo(GetCameraLocation(), averageLocation, DeltaTime, CameraData->CameraDelay);

	rotation = CameraData->CameraRotationOffset;

	OutVT.POV.Location = lerpLocation;
	OutVT.POV.Rotation = rotation;

	// Set FOV to 90 if no FOV is set in CameraData
	if (CameraData->CameraFOV == 0.0f)
	{
		OutVT.POV.FOV = 90.0f;		
	}
	else
	{
		OutVT.POV.FOV = CameraData->CameraFOV;
	}
	
}

