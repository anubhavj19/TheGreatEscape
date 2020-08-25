// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEGREATESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor();
	void CloseDoor();
	float TotalMassOfActors() const;

private:
	
	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
		float TargetYaw = 90.f;


	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	float DoorLastOpened = 0.f;
	float DoorCloseDelay = 0.3f;
		
};
