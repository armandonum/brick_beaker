// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

class UBoxComponent;
UCLASS()
class ARCA_API ABrick : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Brick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* Box_Collision;
	float SpeedModifierOnBounce = 1.0f;

      AActor* nada;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappeComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult);

	void DestroyBrick();

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// actor componente de escena 


private:
	void duplicar(AActor* original);

	//// sonido al colisionar 
	//void Teletransporte(AActor* Actor);

	//UPROPERTY(EditAnywhere)
	//	ABrick* Target = nullptr;

	//UPROPERTY(EditAnywhere)
	//	class USoundCue* sonido_teletransporteB;

	//UFUNCTION()
	//	void OnOverlapBegin(AActor* TeleporterActor, AActor* OtherActor);


};
