// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "capsula_poder.generated.h"

class Apaddle_player_controler;//para llamar a la clase  padle controller 

UCLASS()
class ARCA_API Acapsula_poder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Acapsula_poder();

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

	Apaddle_player_controler* PlayerController_REF1;//referencia a paddle controler


	
	void DestroyBrick();
public:	
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
 
	//void interrogative(int indicador);
private:
	/*void duplicar_pelota(AActor* original);*/



   

};
