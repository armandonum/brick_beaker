// Fill out your copyright notice in the Description page of Project Settings.


#include "capsula_poder_duplica_pelota.h"

#include"Components/StaticMeshComponent.h"
#include"Components/BoxComponent.h"
#include"Ball.h"
#include"paddle.h"

#include"Kismet/GameplayStatics.h"
// llamada a paddle controler 
#include"paddle_player_controler.h"

// Sets default values
Acapsula_poder_duplica_pelota::Acapsula_poder_duplica_pelota()
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
void Acapsula_poder_duplica_pelota::BeginPlay()
{
	Super::BeginPlay();


	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &Acapsula_poder_duplica_pelota::OnOverlapBegin);

	PlayerController_REF1 = Cast<Apaddle_player_controler>(UGameplayStatics::GetPlayerController(GetWorld(), 0));// se crea una variable  de tipo padle controler 
	
}


// Called every frame
void Acapsula_poder_duplica_pelota::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void Acapsula_poder_duplica_pelota::OnOverlapBegin(UPrimitiveComponent* OverlappeComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor->ActorHasTag("paleta")) {
		APawn* mypaleta = Cast<Apaddle>(OtherActor);// cramos una variable que contenga la paleta 
		ABall* MyBall = Cast<ABall>(OtherActor);





		//FVector BallVelocity = mypaleta->GetVelocity();//paleta
		//BallVelocity *= (SpeedModifierOnBounce - 3.0f);// paleta



		//FVector BallVelocity = MyBall->GetVelocity();//pelota
		//BallVelocity *= (SpeedModifierOnBounce - 3.0f);//pelota

		//MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);//pelota

		PlayerController_REF1->SpawnNewBall();// crea una nueva pelota
		

		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("una capsula destruido"));

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &Acapsula_poder_duplica_pelota::DestroyBrick, 1.1f, false);
		DestroyBrick();

		


	}


}
void Acapsula_poder_duplica_pelota::DestroyBrick()
{
	this->Destroy();
}


