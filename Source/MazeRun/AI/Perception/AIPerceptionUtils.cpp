// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPerceptionUtils.h"

void UAIPerceptionUtils::SetSightSenseMaxAge(AAIController* AIController, float NewMaxAge)
{
	FAISenseID Id = UAISense::GetSenseID(UAISense_Sight::StaticClass());

	if (!Id.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Wrong Sense ID"));
		return;
	}

	auto PerceptionComponent = AIController->GetPerceptionComponent();

	if (PerceptionComponent == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("No Perception component found!"));
		return;
	}

	auto Config = PerceptionComponent->GetSenseConfig(Id);

	if (Config == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Sense config not found"));
		return;
	}

	auto ConfigSight = Cast<UAISenseConfig_Sight>(Config);

	if (ConfigSight == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Cast to config failed!"));
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("New Max Age: %f"), NewMaxAge));
	ConfigSight->SetMaxAge(NewMaxAge);
	PerceptionComponent->RequestStimuliListenerUpdate();
}
