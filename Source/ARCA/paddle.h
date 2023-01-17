// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "paddle.generated.h"

class UFloatingPawnMovement;

UCLASS()
class ARCA_API Apaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Apaddle();



	bool palet; // condicion para la paleta 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_paddle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatingMovement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void MoveHorizontal(float AxisValue);

	virtual void moveVertical(float AxisValue);

	// una funcion de componente estatica punteado a la paleta
	UFUNCTION()

		UStaticMeshComponent* Getpaleta();
};
