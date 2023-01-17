// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ladrillo_potencia.generated.h"

UCLASS()
class ARCA_API Aladrillo_potencia : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aladrillo_potencia();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Brick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* Box_Collision;
	float SpeedModifierOnBounce = 1.0f;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappeComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
//private:
//	//variable de tipo actor 
//	AActor* cubo;// para hcer una referencia al cubo que posee este scrip de este tipo actor 
//
//	UPROPERTY(EditAnywhere)//este permite que se vea en el editor(para que no sea nescesario volver al codigo)
//		FVector posiciones = FVector(3, 0, 0); // asi se deckara un vertor 3
//	FVector rever;
//
//	UPROPERTY(EditAnywhere) // este permite que se vea en el editor (para que no sea nescesario volver al codigo)
//		int velocidad = 1; // variable entera usada para mover el cubo 

};
