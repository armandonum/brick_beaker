// Fill out your copyright notice in the Description page of Project Settings.


#include "disparo.h"

#include"GameFramework/FloatingPawnMovement.h"
#include"Components/StaticMeshComponent.h"
#include"GameFramework/ProjectileMovementComponent.h"

// Sets default values
Adisparo::Adisparo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Bullet = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = SM_Bullet;

	SM_Bullet->SetSimulatePhysics(true);
	SM_Bullet->SetEnableGravity(false);
	SM_Bullet->SetConstraintMode(EDOFMode::XZPlane);
	SM_Bullet->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Bullet->SetCollisionProfileName(TEXT("PhysicsActor"));

	BulletMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement "));

	BulletMovement->bShouldBounce = true;
	BulletMovement->Bounciness = 1.1f;
	BulletMovement->Friction = 0.0f;
	BulletMovement->Velocity.X = 0.0f;

}

void Adisparo::disparo()
{
	if (!BalaDisparo) {
		SM_Bullet->AddImpulse(FVector(0.0f, 0.0f, 300.0f),FName(),true);


		BalaDisparo = true;
	}


}


UStaticMeshComponent* Adisparo::GetBala()
{
	return SM_Bullet;
}

// Called when the game starts or when spawned
void Adisparo::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void Adisparo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}





