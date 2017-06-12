// Fill out your copyright notice in the Description page of Project Settings.

#include "CyclistVR.h"
#include "CharacterVR.h"
#include "Carro.h"


// Sets default values
ACharacterVR::ACharacterVR()
{

	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionProfileName("BlockAllDynamic");
	ConstructorHelpers::FObjectFinder<USoundCue>SoundCue(TEXT("SoundCue'/Game/songs/sucess_Cue.sucess_Cue'"));
	
	if (SoundCue.Succeeded()) {
		level = SoundCue.Object;
	}

	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	AudioComp->bAutoActivate = false;

	AudioComp->SetSound(level);
	

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
	if (Life != 0) {
		SetQuilometragem(GetQuilometragem() + 5);
		FVector NewLocation(GetCapsuleComponent()->GetComponentLocation().X + GetVelocidade(), GetCapsuleComponent()->GetComponentLocation().Y, GetCapsuleComponent()->GetComponentLocation().Z);
		GetCapsuleComponent()->SetWorldLocation(NewLocation);
		//UE_LOG(LogTemp, Warning, TEXT("KM: %d"),Quilometragem);
		RotateHead();
	}

	

}

// Called to bind functionality to input
void ACharacterVR::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterVR::RotateHead() {

	if (GetQuilometragem() == 50000) {
		SetVelocidade(GetVelocidade() + 5);
		AudioComp->Play();
	}
	else if (GetQuilometragem() == 10000) {
		SetVelocidade(GetVelocidade() + 5);
		AudioComp->Play();
	}
	//float Rotate = PlayerCamera->GetComponentRotation().Roll;
	float Rotate = PlayerCamera->GetComponentRotation().Yaw;
	if (Rotate < -5) {
		FVector NewLocation(GetCapsuleComponent()->GetComponentLocation().X, GetCapsuleComponent()->GetComponentLocation().Y - 2, GetCapsuleComponent()->GetComponentLocation().Z);
		GetCapsuleComponent()->SetWorldLocation(NewLocation);
	}
	else if (Rotate > 5) {
		FVector NewLocation(GetCapsuleComponent()->GetComponentLocation().X, GetCapsuleComponent()->GetComponentLocation().Y + 2, GetCapsuleComponent()->GetComponentLocation().Z);
		GetCapsuleComponent()->SetWorldLocation(NewLocation);
	}
	else {

	}
}



int ACharacterVR::GetLife() {
	return Life;
}

void ACharacterVR::SetLife(int NewLife) {
	Life = NewLife;
}

FVector ACharacterVR::GetPlayerLocation() {
	return GetCapsuleComponent()->GetComponentLocation();
}

int ACharacterVR::GetQuilometragem() {
	return Quilometragem;
}

void ACharacterVR::SetQuilometragem(int NewQuilometragem) {
	Quilometragem = NewQuilometragem;
}

int ACharacterVR::GetVelocidade() {
	return Velocidade;
}

void ACharacterVR::SetVelocidade(int NewVelocidade) {
	Velocidade = NewVelocidade;
}

int ACharacterVR::GetDesempenho() {
	return Desempenho;
}

void ACharacterVR::SetDesempenho(int NewDesempenho) {
	Desempenho = NewDesempenho;
}



void ACharacterVR::RestartGame() {
	FVector InitialLocation(71.999939f, 0.0f, 116.669983f);
	SetLife(100);
	SetQuilometragem(0);
	SetVelocidade(5);
	GetCapsuleComponent()->SetWorldLocation(InitialLocation);


}





