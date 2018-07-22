// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI not controlling a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controlling tank : %s"), *(ControlledTank->GetName()));
	}

	//Find the player tank
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI not found the player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found the player tank : %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim at the player
		//GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation()); 

		// Fire if ready
	}
}
