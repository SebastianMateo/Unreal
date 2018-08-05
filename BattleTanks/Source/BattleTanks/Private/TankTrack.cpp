// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "SprungWheel.h"
#include "SpawnPoint.h"

UTankTrack::UTankTrack()
{
}

void UTankTrack::SetThrottle(float Throttle)
{
	DriveTrack(FMath::Clamp(Throttle, -1.0f, 1.0f));
}

void UTankTrack::DriveTrack(float Throttle)
{
	auto ForceApplied = Throttle * TrackMaxDrivingForce;

	// Apply the force to all the wheels
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();
	for (auto Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel*> ResultArray;
	TArray<USceneComponent*> Children;

	GetChildrenComponents(true, Children);
	for (auto Child : Children)
	{
		auto SpawnPointChild = Cast<USpawnPoint>(Child);

		if (!SpawnPointChild) { continue; }

		auto SpawnedChild = SpawnPointChild->GetSpawnedActor();
		auto SprungWheel = Cast<ASprungWheel>(SpawnedChild);

		if (!SprungWheel) { continue; }

		// Finally we got a SprungWheel!
		ResultArray.Add(SprungWheel);
	}
	
	return ResultArray;
}