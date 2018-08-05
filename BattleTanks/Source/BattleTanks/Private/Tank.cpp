// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth; // If we put this in the constructor it will be override
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	CurrentHealth -= DamageAmount;
	FMath::Clamp<float>(CurrentHealth, 0, MaxHealth);

	if (CurrentHealth == 0)
	{
		OnDeath.Broadcast();
	}

	return DamageAmount;
}

float ATank::GetHealthPercent() const
{
	return (CurrentHealth / MaxHealth);
}