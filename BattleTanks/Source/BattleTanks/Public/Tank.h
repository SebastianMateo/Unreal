// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate); // Event

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:

	// Return current health as a percentage of staring health between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	FTankDelegate OnDeath;

	virtual void BeginPlay() override;
private:
	ATank();

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	float CurrentHealth = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxHealth = 100.0f;
};
