// Copyright Epic Games, Inc. All Rights Reserved.


#include "ARCAGameModeBase.h"
#include"Brick.h"


//
//void AARCAGameModeBase::mensage()
//{
//	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("bienvenido"));
//	FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
//}


void AARCAGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("hola como estais"));



	FTransform spawnlocalizacion;
	GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), spawnlocalizacion);
}