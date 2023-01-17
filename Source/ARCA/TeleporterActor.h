// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeleporterActor.generated.h"

class USoundCue;

UCLASS()
class ARCA_API ATeleporterActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleporterActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// funcion teletransporte enviamos una variable de tipo actor 
	void Teletransporte(AActor* Actor);

	UPROPERTY(EditAnywhere)
		ATeleporterActor* Target = nullptr;

	UPROPERTY(EditAnywhere)
		USoundCue* sonido_teletransporteB;

	UFUNCTION()

		// nueva funcion overlap a la que enviamos dos variables de tipo actor 
		void OnOverlapBegin(AActor* TeleporterActor, AActor* OtherActor);



};
