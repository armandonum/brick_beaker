// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "paddle_player_controler.generated.h"

class Acapsula_poder_duplica_pelota;//clase de duplicar la pelota unicamente 


class Adisparo;// calase del disparo que contien los encabezados 

class ABall;

class Apaddle;// clase del disparo que contiene los encabezados de la paleta
/**
 * 
 */
UCLASS()
class ARCA_API Apaddle_player_controler : public APlayerController
{
	GENERATED_BODY()

		Apaddle_player_controler();

	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:



	virtual void BeginPlay() override;
	void MoveHorizontal(float AxisValue);
	void moveVertical(float AxisValue);

	void destruir();
	void destruir_paleta();


	// referencias a ball
	void Launch();
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;
	ABall* MyBall;

	FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;



	// referencias al disparo a enemigo 
	void disparo();

	UPROPERTY(EditAnywhere)
		TSubclassOf<Adisparo> BalaObj;
	Adisparo* MyBallet;

	FVector ubicacion = FVector(150.0f, 0.0f, 40.0f);
	FRotator rotacion = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters informacion;


	// referencias a la nueva paleta
	UPROPERTY(EditAnywhere)
		TSubclassOf<Apaddle> paletaObj;
	Apaddle* Mypaleta;
	

	FRotator rot_paleta = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters info_paleta;
public:
	// referencia a disparo
	void SpawnNewBallet();

	void nuevo_Ball();
	void SpawnNewBall();
	void destruir_misil();
	void Spawn_paleta();// para clonar la paleta
};
