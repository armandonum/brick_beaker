// Fill out your copyright notice in the Description page of Project Settings.


#include "enmy_Controlable.h"

// Sets default values
Aenmy_Controlable::Aenmy_Controlable()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aenmy_Controlable::BeginPlay()
{
	Super::BeginPlay();

	AddMovementInput(FVector(0.0f, 0.0f, 0.0f), 1.0f, false);
}

// Called every frame
void Aenmy_Controlable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

// Called to bind functionality to input
void Aenmy_Controlable::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}
