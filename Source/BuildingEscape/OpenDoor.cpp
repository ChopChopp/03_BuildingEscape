// Copyright Chop Chop Inc. 2019, all right reserved.

#include "OpenDoor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	//*FString DoorRotation = GetOwner()->GetActorRotation().ToString();
	//*UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *DoorRotation);

	OpeningActor = GetWorld()->GetFirstPlayerController()->GetPawn();

	//GetOwner()->SetActorRotation(20.0f);
	//UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *DoorRotation);

	//OpenDoor();
	
}

void UOpenDoor::OpenDoor()
{
	AActor* actor = GetOwner();
	FRotator NewRotation = FRotator(0.0f, 45.0f, 0.0f);
	actor->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (PressurePlate->IsOverlappingActor(OpeningActor)) {
		OpenDoor();
	}

	
	// ...
}

