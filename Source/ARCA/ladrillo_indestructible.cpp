// Fill out your copyright notice in the Description page of Project Settings.


#include "ladrillo_indestructible.h"

#include"Components/StaticMeshComponent.h"
#include"Components/BoxComponent.h"
#include"Ball.h"

// llamada al archivo header de disparo 
#include"disparo.h"

// Sets default values
Aladrillo_indestructible::Aladrillo_indestructible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));

	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	Box_Collision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = Box_Collision;
}

// Called when the game starts or when spawned
void Aladrillo_indestructible::BeginPlay()
{
	Super::BeginPlay();

	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &Aladrillo_indestructible::OnOverlapBegin);
	
}

// Called every frame
void Aladrillo_indestructible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void Aladrillo_indestructible::OnOverlapBegin(UPrimitiveComponent* OverlappeComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType,
	bool bFromSweep, const FHitResult& SweepResult)
{
	//preguntamoc si hay un actor con la etiqueta "Ball"
	if (OtherActor->ActorHasTag("misil")) {
	/*ABall* MyBall = Cast<ABall>(OtherActor);

	FVector BallVelocity = MyBall->GetVelocity();
	BallVelocity *= (SpeedModifierOnBounce - 1.0f);

	MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);*/

	this->Destroy();
	
	//if (OtherActor->ActorHasTag("Ball")) {
	//	

	//	/*FTimerHandle UnusedHandle;
	//	GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 0.1f, false);

	//	DestroyBrick();*/
	}
}
