// Fill out your copyright notice in the Description page of Project Settings.

#include "BoxActor.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include <iostream>

// Sets default values
ABoxActor::ABoxActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ABoxActor::BeginPlay() {
    Super::BeginPlay();
}

void ABoxActor::InitVehicle(FVector dims, FVector location) {
    // Generate a Box actora
    // Add a cube
	pComponent = NewObject<UBoxComponent>(this);
    pComponent->InitBoxExtent(dims);
    pComponent->SetHiddenInGame(false);
    pComponent->RegisterComponent();
    RootComponent = pComponent;
	SetActorLocation(location);
}

// Never called
void ABoxActor::Tick(float DeltaTime)
{
}

void ABoxActor::Act(float DeltaTime, double acceleration, double turnRate) {

    // Apply acceleration to each actor
    // Update each actors
    // retrieve location, velocity for all actors

    Super::Tick(DeltaTime);
    FVector loc = GetActorLocation();
    FRotator rot = GetActorRotation();
    FVector Velocity = GetActorRotation().Vector() * Speed;


    double newSpeed = Speed + acceleration * DeltaTime;
    double newYaw = rot.Yaw + turnRate * DeltaTime; // * Speed 

    rot.Yaw = newYaw;
    FVector newVelocity = rot.Vector() * newSpeed;

    loc.X += (Velocity.X + newVelocity.X) * DeltaTime / 2;
    loc.Y += (Velocity.Y + newVelocity.Y) * DeltaTime / 2;

    Speed = newSpeed;

    SetActorLocation(loc);
    SetActorRotation(rot);

}

void ABoxActor::Update(float DeltaTime, float x, float y, double theta, double v) {
    
    // Apply acceleration to each actor
    // Update each actors
    // retrieve location, velocity for all actors
    if (DeltaTime > 1e-7) {
        Super::Tick(DeltaTime);
    }
    
    FVector loc = GetActorLocation();
    FRotator rot = GetActorRotation();
    
    
    loc.X = x;
    loc.Y = y;
    rot.Yaw = theta;
    Speed = v;
    
    SetActorLocation(loc);
    SetActorRotation(rot);
    
}
