// Fill out your copyright notice in the Description page of Project Settings.


#include "MoverCubo.h"



//metodo constructor de la clse 
UMoverCubo::UMoverCubo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;



	// ...
}


// se llama una ves al comienzo 
void UMoverCubo::BeginPlay()
{
	Super::BeginPlay();


	cubo = GetOwner();// el cubo es iguak a este objeto 

	// ...

}




// se llama cada frame
void UMoverCubo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//velocidad += velocidad * DeltaTime; // se le multiplica para que la velocidad sea constante en todos los lados 



		//posiciones.X = velocidad + cubo->GetActorLocation().X;// a la posicion del jugador le sumo la velicidad 

		//posiciones.Y = cubo->GetActorLocation().Y;//posicion en el eje y
		//posiciones.Z = cubo->GetActorLocation().Z;//posicion en el eje z

		////cambio la posicion del cubo 
	 // cubo->SetActorLocation(posiciones);



	//cubo->AddActorLocalOffset(posiciones);
	//if (cubo->GetActorLocation().X > 300)
	//{
	//	cubo->SetActorLocation(FVector(-440, -20, 70));
	//}
	//	
	
	
	/*if ( interrogative()== 1) {
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("se esta ejecutanto la caida"));
	}*/
	if (cubo->GetActorLocation().X == 330) {// si la posicion es igual a 300 cambia de direccion 

		rever = -posiciones;

	}
	if (cubo->GetActorLocation().X == -360) {// si la posicion es igual a -350 cambia de direccion
		rever = posiciones;
	}

	cubo->AddActorLocalOffset(rever);//mueve objeto 

}


