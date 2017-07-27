// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "BoxActor.generated.h"

UCLASS()
class MULTIBOX_API ABoxActor : public AActor
{
	GENERATED_BODY()
  UPROPERTY(VisibleAnywhere)
  UBoxComponent* pComponent;

public:
	// Sets default values for this actor's properties
	ABoxActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	double Speed;
    void Update(float DeltaTime, double acceleration, double turnRate);
    void InitVehicle(FVector dims, FVector location);
};
