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


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ATank();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaTime) override;



private:
	UPROPERTY(VisibleAnywhere,Category = "Components")
		class USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere,Category = "Components")
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement",meta = (AllowPrivateAccess = "true"))
		float Speed = 600.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float RotationSpeed = 300.f;

	APlayerController* PlayerControllerRef;


	void Move(float Value);
	void Turn(float Value);


};
