// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ProjectLunaLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTLUNA_API UProjectLunaLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FVector GetPositionBetweenCharacters(const UObject* worldContext);
};
