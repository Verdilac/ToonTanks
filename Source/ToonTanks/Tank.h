// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()


public:
	ATank();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



private:
	UPROPERTY(VisibleAnywhere,Category = "Components")
		class USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere,Category = "Components")
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement",meta = (AllowPrivateAccess = "true"))
		float Speed = 600.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float RotationSpeed = 300.f;


	void Move(float Value);
	void Turn(float Value);
};
