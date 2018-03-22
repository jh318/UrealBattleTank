// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;	

private:	

	ATank();


	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 10;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr; //TODO Remove

	double LastFireTime = 0;
};
