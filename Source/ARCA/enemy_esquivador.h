// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "enemy_esquivador.generated.h"

UCLASS()
class ARCA_API Aenemy_esquivador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aenemy_esquivador();

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

	void DestroyBrick();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
