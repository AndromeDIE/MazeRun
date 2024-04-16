// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <Perception/AIPerceptionTypes.h>
#include <AIController.h>
#include <Perception/AISense_Sight.h>
#include <Perception/AIPerceptionComponent.h>
#include <Perception/AISenseConfig_Sight.h>
#include "AIPerceptionUtils.generated.h"

class UAISense;
class UAIPerceptionComponent;
class UAISenseConfig_Sight;

/**
 * 
 */
UCLASS()
class MAZERUN_API UAIPerceptionUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintCallable, Category="AI Perception Utils")
		static void SetSightSenseMaxAge(AAIController* AIController, float NewMaxAge);
	
};
