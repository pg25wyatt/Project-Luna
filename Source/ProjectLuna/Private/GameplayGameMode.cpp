// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayGameMode.h"
#include "GameplayGameState.h"
#include "GameplayPlayerState.h"
#include "GameplayPlayerController.h"
#include "GameplayHUD.h"

AGameplayGameMode::AGameplayGameMode(const FObjectInitializer& ObjectInitializer)
{
	GameStateClass = AGameplayGameState::StaticClass();
	PlayerStateClass = AGameplayPlayerState::StaticClass();
	PlayerControllerClass = AGameplayPlayerController::StaticClass();
	HUDClass = AGameplayHUD::StaticClass();
}
