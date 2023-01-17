// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "disparo.generated.h"

UCLASS()
class ARCA_API Adisparo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Adisparo();
	// para disparar
		virtual void disparo();

	bool BalaDisparo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// creamos los componentes de malla y de movimiento 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Bullet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class	UProjectileMovementComponent* BulletMovement;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UFloatingPawnMovement* FloatingMovement;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
	
	// una funcion de componente estatica punteado al disparo
	UFUNCTION()

		UStaticMeshComponent* GetBala();

};
