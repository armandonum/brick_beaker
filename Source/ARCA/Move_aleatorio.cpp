// Fill out your copyright notice in the Description page of Project Settings.


#include "Move_aleatorio.h"
#include"Ball.h"

// Sets default values for this component's properties
UMove_aleatorio::UMove_aleatorio()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMove_aleatorio::BeginPlay()
{
	Super::BeginPlay();

	cubo = GetOwner();// el cubo es iguak a este objeto
	

	// ...
	
}





// Called every frame
void UMove_aleatorio::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	int randX = FMath::RandRange(-111, 111)*3;
	int randX2 = FMath::RandRange(-111, 111) * 3;

	

		if (cubo->GetActorLocation().X == 330) {// si la posicion es igual a 300 cambia de direccion 

			rever = -posiciones;

		}
		if (cubo->GetActorLocation().X == -360) {// si la posicion es igual a -350 cambia de direccion
			rever = posiciones;
		}

		if (cubo->GetActorLocation().X == randX) {// si la posicion es igual a 300 cambia de direccion 

			rever = -posiciones;

		}
		if (cubo->GetActorLocation().X == randX2) {// si la posicion es igual a 300 cambia de direccion 

			rever = posiciones;

		}
		cubo->AddActorLocalOffset(rever);//mueve objeto 
	

	// ...
}

