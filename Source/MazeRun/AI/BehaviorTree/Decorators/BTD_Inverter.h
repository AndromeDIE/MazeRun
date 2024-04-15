// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_Inverter.generated.h"

/**
 * 
 */
UCLASS(HideCategories=(Condition), MinimalAPI)
class UBTD_Inverter : public UBTDecorator 
{
	GENERATED_UCLASS_BODY()

protected:

	MAZERUN_API virtual void OnNodeProcessed(struct FBehaviorTreeSearchData& SearchData, EBTNodeResult::Type& NodeResult) override;

#if WITH_EDITOR
	MAZERUN_API virtual FName GetNodeIconName() const override;
#endif //WITH_EDITOR
	
};
