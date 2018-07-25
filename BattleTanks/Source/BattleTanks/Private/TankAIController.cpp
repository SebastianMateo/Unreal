// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank)
	{
		auto ControlledTank = Cast<ATank>(GetPawn());

		// TODO Move towards the player

		// Aim at the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();

		// Fire if ready
	}
}
