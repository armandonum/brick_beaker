// Fill out your copyright notice in the Description page of Project Settings.


#include "ladrillo_potencia.h"


#include"Components/StaticMeshComponent.h"
#include"Components/BoxComponent.h"
#include"Ball.h"


// Sets default values
Aladrillo_potencia::Aladrillo_potencia()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));

	//SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	Box_Collision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = Box_Collision;

}

// Called when the game starts or when spawned
void Aladrillo_potencia::BeginPlay()
{



	Super::BeginPlay();

	//cubo = GetOwner();// el cubo es iguak a este objeto 

	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &Aladrillo_potencia::OnOverlapBegin);
	
}

void Aladrillo_potencia::OnOverlapBegin(UPrimitiveComponent* OverlappeComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor->ActorHasTag("Ball"))
	{
		ABall* MyBall = Cast<ABall>(OtherActor);

			FVector BallVelocity = MyBall->GetVelocity();
			BallVelocity *= (SpeedModifierOnBounce + 1.5f);

			MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);
			this->Destroy();

	}

	
}

// Called every frame
void Aladrillo_potencia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if (cubo->GetActorLocation().X == 330) {// si la posicion es igual a 300 cambia de direccion 

	//	rever = -posiciones;

	//}
	//if (cubo->GetActorLocation().X == -360) {// si la posicion es igual a -350 cambia de direccion
	//	rever = posiciones;
	//}

	//cubo->AddActorLocalOffset(rever);//mueve objeto 
}

