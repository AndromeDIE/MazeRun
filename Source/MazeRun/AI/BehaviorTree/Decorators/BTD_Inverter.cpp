// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_Inverter.h"
#include "GameFramework/Actor.h"
#include "VisualLogger/VisualLogger.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(BTD_Inverter)

UBTD_Inverter::UBTD_Inverter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = TEXT("Inverter");
	INIT_DECORATOR_NODE_NOTIFY_FLAGS();

	bAllowAbortNone = false;
	bAllowAbortLowerPri = false;
	bAllowAbortChildNodes = false;
}

void UBTD_Inverter::OnNodeProcessed(FBehaviorTreeSearchData& SearchData, EBTNodeResult::Type& NodeResult)
{
	switch (NodeResult)
	{
	case EBTNodeResult::Succeeded:
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Inverting to failure (from success)!"));
		NodeResult = EBTNodeResult::Failed;
		break;
	case EBTNodeResult::Failed:
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Inverting to success (from failure)!"));
		NodeResult = EBTNodeResult::Succeeded;
		break;
	case EBTNodeResult::Aborted:
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("ABORTED!"));
		break;
	case EBTNodeResult::InProgress:
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("In Progress!"));
		break;
	default:
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Unknown result!"));
	}

	BT_SEARCHLOG(SearchData, Log, TEXT("Inverting NodeResult: %s"), *UBehaviorTreeTypes::DescribeNodeHelper(this));
}

#if WITH_EDITOR

FName UBTD_Inverter::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Decorator.Inverter.Icon");
}

#endif //WITH_EDITOR
