// Fill out your copyright notice in the Description page of Project Settings.

#include "CyclistVR.h"
#include "CharacterVR.h"
#include "Carro.h"


// Sets default values
ACharacterVR::ACharacterVR()
{

	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionProfileName("BlockAllDynamic");
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ACharacterVR::OnHit);

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	GetMesh()->SetupAttachment(PlayerCamera);

	FVector cameraLocation(30.0f, PlayerCamera->GetComponentLocation().Y, PlayerCamera->GetComponentLocation().Z);
	PlayerCamera->SetRelativeLocation(cameraLocation);
}

// Called when the game starts or when spawned
void ACharacterVR::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ACharacterVR::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation(GetCapsuleComponent()->GetComponentLocation().X + 5, GetCapsuleComponent()->GetComponentLocation().Y, GetCapsuleComponent()->GetComponentLocation().Z);
	GetCapsuleComponent()->SetWorldLocation(NewLocation);
	RotateHead();


}

// Called to bind functionality to input
void ACharacterVR::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterVR::RotateHead() {
	float Rotate = PlayerCamera->GetComponentRotation().Yaw;
	if (Rotate < -5) {
		FVector NewLocation(GetCapsuleComponent()->GetComponentLocation().X, GetCapsuleComponent()->GetComponentLocation().Y -2, GetCapsuleComponent()->GetComponentLocation().Z);
		GetCapsuleComponent()->SetWorldLocation(NewLocation);
	}else if(Rotate > 5){
		FVector NewLocation(GetCapsuleComponent()->GetComponentLocation().X, GetCapsuleComponent()->GetComponentLocation().Y + 2, GetCapsuleComponent()->GetComponentLocation().Z);
		GetCapsuleComponent()->SetWorldLocation(NewLocation);
	}else {

	}
}

void ACharacterVR::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	if (OtherActor != nullptr &&
		OtherActor->IsA(ACarro::StaticClass()) &&
		OtherComp != nullptr) {

		UE_LOG(LogTemp, Warning, TEXT("ATROPELADO"));

	}
}

