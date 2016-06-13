// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TensaisToolboxPrivatePCH.h"
#include "TensaisToolboxBPLibrary.h"




UTensaisToolboxBPLibrary::UTensaisToolboxBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

AActor* UTensaisToolboxBPLibrary::GetClosestActorOfClass(AActor* source_actor, TArray<TSubclassOf<AActor>> classes)
{
	AActor* closest_so_far = nullptr;
	float closest_distance = -1.0;
	float current_distance = 0.0;
	
	for (TSubclassOf<AActor> given_class : classes) {
		for (TActorIterator<AActor> ActorItr(source_actor->GetWorld(), given_class); ActorItr; ++ActorItr)
		{
			current_distance = source_actor->GetDistanceTo(*ActorItr);
			//UE_LOG(LogTemp, Warning, TEXT("Actor of class found! -> %.3f"), current_distance);
			if (current_distance < closest_distance || closest_distance < 0) {
				closest_so_far = *ActorItr;
				closest_distance = current_distance;
			}
		}
	}
	return closest_so_far;
}

