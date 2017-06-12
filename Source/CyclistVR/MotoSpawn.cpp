// Fill out your copyright notice in the Description page of Project Settings.

#include "CyclistVR.h"
#include "MotoSpawn.h"
#include "Moto.h"
#include "CharacterVR.h"


// Sets default values
AMotoSpawn::AMotoSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	RootComponent = Root;
	CountMotoToSpawn = 15;
}

// Called when the game starts or when spawned
void AMotoSpawn::BeginPlay()
{
	Super::BeginPlay();
	UWorld * World = GetWorld();
	GetWorld()->GetTimerManager().SetTimer(FuzeTimerHandle, this, &AMotoSpawn::SpawMoto, 1.0f, true);
	
}

// Called every frame
void AMotoSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0);
	ACharacterVR* vrchar = Cast<ACharacterVR>(Pawn);
	levelProgress = vrchar->GetQuilometragem();
	//UE_LOG(LogTemp, Warning, TEXT("levelProgress: %d"), levelProgress);
}

void AMotoSpawn::SpawMoto() {
	UWorld * World = GetWorld();
		if (levelProgress > 20000) {
			if (World != nullptr) {

				APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0);
				ACharacterVR* Char = Cast<ACharacterVR>(Pawn);

				float LocationX = Char->GetPlayerLocation().X + 5000.0f;
				float LocationZ = 7.0f;



				Ramdom = FMath::RandRange(0, 8);
				//UE_LOG(LogTemp, Warning, TEXT("Random: %d"), Ramdom);
				FActorSpawnParameters SpawParameters;

				if (Ramdom == 1) {
					FVector Location(LocationX, -24.0f, 12.0f);
					AMoto * moto = World->SpawnActor<AMoto>(Location, FRotator::ZeroRotator, SpawParameters);
					LocationX += 3000.0f;
					CountMotoToSpawn++;
					//UE_LOG(LogTemp, Warning, TEXT("APessoa 1"));
				}
		}	
	}
}
