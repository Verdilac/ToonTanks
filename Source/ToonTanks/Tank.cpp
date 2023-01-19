// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"


ATank::ATank() {
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Sprint Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef = Cast<APlayerController>(GetController());

}



// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerControllerRef) {

		FHitResult  HitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,HitResult);
		RotateTurret(HitResult.ImpactPoint)
;

	}

}

void ATank::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this,&ATank::Turn);
	PlayerInputComponent->BindAction(TEXT("Fire"),IE_Pressed,this,&ATank::Fire);

 }





void ATank::Move(float Value) {

	FVector DeltaLocation = FVector::ZeroVector;

	DeltaLocation.X = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * Speed;
	AddActorLocalOffset(DeltaLocation,true);

}

void ATank::Turn(float Value) {

	FRotator DeltaRoation = FRotator::ZeroRotator;
	DeltaRoation.Yaw = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * RotationSpeed;
	AddActorLocalRotation(DeltaRoation, true);
}