// Fill out your copyright notice in the Description page of Project Settings.


#include "paddle_player_controler.h"



#include"Components/StaticMeshComponent.h"//extra
#include"Components/BoxComponent.h"//extra


#include"Kismet/GameplayStatics.h"
#include"Camera/CameraActor.h"



#include"paddle.h"
#include"Ball.h"


// llamada al aechivo header de disparo
#include"disparo.h"



Apaddle_player_controler::Apaddle_player_controler()
{


}
// pertenece a enmy_Controlable


void Apaddle_player_controler::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	nuevo_Ball();

	//llamamos a crear bala
	SpawnNewBallet();

	
	

}
void Apaddle_player_controler::SetupInputComponent()
{
	Super::SetupInputComponent();


	EnableInput(this);
	// hacemos las referencias (buscamos en blueprint)
	InputComponent->BindAxis("MoveHorizontal", this, &Apaddle_player_controler::MoveHorizontal);
	InputComponent->BindAxis("MoveVertical", this, &Apaddle_player_controler::moveVertical);
	// solo para la bola 
	InputComponent->BindAction("Launch", IE_Pressed, this, &Apaddle_player_controler::Launch);


	//ACCION DE DISPARAR LA BALA
	InputComponent->BindAction("disparo", IE_Pressed, this, &Apaddle_player_controler::disparo);

	
}

void Apaddle_player_controler::MoveHorizontal(float AxisValue)
{
	auto MyPawn = Cast<Apaddle>(GetPawn());
	if (MyPawn) {
		MyPawn->MoveHorizontal(AxisValue);
	}
	//para el misil 

}
void Apaddle_player_controler::moveVertical(float AxisValue)
{
	auto MyPawn = Cast<Apaddle>(GetPawn());
	if (MyPawn) {
		MyPawn->moveVertical(AxisValue);
	}

}





void Apaddle_player_controler::Launch()
{
	MyBall->Launch();
	
}

// pertenece a disparo
void Apaddle_player_controler::disparo()
{
	MyBallet->disparo();
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &Apaddle_player_controler::destruir_misil, 1.1f, false, 10);
}
// pertenece a disparo
void Apaddle_player_controler::SpawnNewBallet()
{
	if (!MyBallet)
		MyBallet = nullptr;
	if (BalaObj) {
		MyBallet = GetWorld()->SpawnActor<Adisparo>(BalaObj, ubicacion, rotacion, informacion);
		/*FTimerHandle UnusedHandle;*/
		/*GetWorldTimerManager().SetTimer(-1,4, &Apaddle_player_controler::destruir, 1.1f, false);*/

	}
	
}


void Apaddle_player_controler::nuevo_Ball()
{
	if (!MyBall)
		MyBall = nullptr;
	if (BallObj) {
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotation, SpawnInfo);

		
	}
}

void Apaddle_player_controler::SpawnNewBall()
{
	if (!MyBall)
		MyBall = nullptr;
	if (BallObj) {
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotation, SpawnInfo);

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &Apaddle_player_controler::destruir, 1.1f, false, 10);
	}
}


void Apaddle_player_controler::Spawn_paleta()
{
	
	int randX = FMath::RandRange(-330, 330);
	if (!Mypaleta)
		Mypaleta = nullptr;
	if (paletaObj) {
		Mypaleta = GetWorld()->SpawnActor<Apaddle>(paletaObj,FVector(randX,0.0f,40.0f), rot_paleta, info_paleta);

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this,&Apaddle_player_controler::destruir_paleta, 1.1f, false, 10);
		
	}
}
void Apaddle_player_controler::destruir()
{

	MyBall->Destroy();
}

void Apaddle_player_controler::destruir_paleta()
{
	Mypaleta->Destroy();
}
void Apaddle_player_controler::destruir_misil()
{
	MyBallet->Destroy();

}


