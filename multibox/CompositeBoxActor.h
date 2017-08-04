// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BoxActor.h"
#include <vector>
#include <zmq.hpp>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CompositeBoxActor.generated.h"


UCLASS()
class MULTIBOX_API ACompositeBoxActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACompositeBoxActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    int t;
    void* traj_data_gp;
    std::vector<ABoxActor*> boxActors;
    zmq::socket_t* socket_p;
};
