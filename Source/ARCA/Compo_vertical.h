// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Compo_vertical.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCA_API UCompo_vertical : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCompo_vertical();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

//private:
//	//variable de tipo actor 
//	AActor* ladrillo;// para hcer una referencia al cubo que posee este scrip de este tipo actor 
//
//	UPROPERTY(EditAnywhere)//este permite que se vea en el editor(para que no sea nescesario volver al codigo)
//		FVector posiciones = FVector(0, 0, 1); // asi se deckara un vertor 3
//	FVector rever;
//
//	UPROPERTY(EditAnywhere) // este permite que se vea en el editor (para que no sea nescesario volver al codigo)
//		int velocidad = 1; // variable entera usada para mover el cubo 
		
};
