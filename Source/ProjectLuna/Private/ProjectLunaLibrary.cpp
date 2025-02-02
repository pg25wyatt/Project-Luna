// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectLunaLibrary.h"
#include "GameFramework/GameState.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"

FVector UProjectLunaLibrary::GetPositionBetweenCharacters(const UObject* worldContext)
{
	// Validate world context
	if (!IsValid(worldContext))
	{
		return FVector::ZeroVector;
	}

	// Get and validate world
	const TObjectPtr<UWorld> world = worldContext->GetWorld();
	if (!IsValid(world))
	{
		return FVector::ZeroVector;
	}

	// Get and validate game state
	const TObjectPtr<AGameStateBase> gameState = world->GetGameState();
	if (!IsValid(gameState))
	{
		return FVector::ZeroVector;
	}
	
	TArray<TObjectPtr<AActor>> pawns;

	// Get all characters and add them to an array
	for (const TObjectPtr<APlayerState> playerStateIter : gameState->PlayerArray)
	{
		TObjectPtr<APawn> pawnIter = playerStateIter->GetPawn();
		if (!IsValid(pawnIter))
		{
			continue;
		}
		pawns.AddUnique(pawnIter);
	}

	return UGameplayStatics::GetActorArrayAverageLocation(pawns);
}

