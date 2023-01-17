// Fill out your copyright notice in the Description page of Project Settings.


#include "paddle.h"

#include"GameFramework/FloatingPawnMovement.h"
#include"Components/StaticMeshComponent.h"


// Sets default values
Apaddle::Apaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM paddel"));
	RootComponent = SM_paddle;

	SM_paddle->SetEnableGravity(false);
	SM_paddle->SetConstraintMode(EDOFMode::XZPlane);

	// establecemos la coliscion habilitada
	SM_paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_paddle->SetCollisionProfileName(TEXT("physicsActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("floating pawn Movement"));



}



// Called when the game starts or when spawned
void Apaddle::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void Apaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Apaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void Apaddle::MoveHorizontal(float AxisValue)
{

	
	AddMovementInput(FVector(AxisValue, 0.0f,0.0f ), 1.0f, false);

}

void Apaddle::moveVertical(float AxisValue)
{
	AddMovementInput(FVector(0.0f, 0.0f, AxisValue), 1.0f, false);
}

UStaticMeshComponent* Apaddle::Getpaleta()
{
	return SM_paddle;
}



