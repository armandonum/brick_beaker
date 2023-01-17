// Fill out your copyright notice in the Description page of Project Settings.


#include "Compo_vertical.h"

// Sets default values for this component's properties
UCompo_vertical::UCompo_vertical()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCompo_vertical::BeginPlay()
{
	Super::BeginPlay();


	//ladillo = GetOwner();// el cubo es iguak a este objeto 
	// ...
	
}




// Called every frame
void UCompo_vertical::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	//if (ladillo->GetActorLocation().X == 330) {// si la posicion es igual a 300 cambia de direccion 

	//	rever = -posiciones;

	//}
	//if (ladillo->GetActorLocation().X == -360) {// si la posicion es igual a -350 cambia de direccion
	//	rever = posiciones;
	//}

	//ladillo->AddActorLocalOffset(rever);//mueve objeto 
}

