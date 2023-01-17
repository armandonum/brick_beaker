// Fill out your copyright notice in the Description page of Project Settings.


#include "enemy_esquivador.h"

#include"Components/StaticMeshComponent.h"
#include"Components/BoxComponent.h"
#include"Ball.h"


// llamada al archivo header disparo.h
#include"disparo.h"

// Sets default values
Aenemy_esquivador::Aenemy_esquivador()
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
void Aenemy_esquivador::BeginPlay()
{
	Super::BeginPlay();

	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &Aenemy_esquivador::OnOverlapBegin);


	
}

// Called every frame
void Aenemy_esquivador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Aenemy_esquivador::OnOverlapBegin(UPrimitiveComponent* OverlappeComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult)
{


	if (OtherActor->ActorHasTag("Ball")) {
		
		ABall* MyBall = Cast<ABall>(OtherActor);// crea una variable de tipo ball
		
		//FVector BallVelocity = mypaleta->GetVelocity();//paleta
		//BallVelocity *= (SpeedModifierOnBounce - 3.0f);// paleta
          

			
		FVector BallVelocity = MyBall->GetVelocity();// crea una variable para la belocidada de ball
		BallVelocity *= (SpeedModifierOnBounce - 3.0f);// ajusta la velocidad de la pelota

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);


		


		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &Aenemy_esquivador::DestroyBrick, 1.1f, false);
		DestroyBrick();

		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("un enemigo esquivador a sido destruido"));
	
	}
	if (OtherActor->ActorHasTag("misil")) {
		this->Destroy();
	}
}

void Aenemy_esquivador::DestroyBrick()
{
	this->Destroy();
}



