// Fill out your copyright notice in the Description page of Project Settings.

#include "CyclistVR.h"
#include "CarsSpawn.h"
#include "CharacterVR.h"
#include "Carro.h"


// Sets default values
ACarsSpawn::ACarsSpawn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	RootComponent = Root;
	CountCarsToSpawn = 15;
}

// Called when the game starts or when spawned
void ACarsSpawn::BeginPlay()
{
	Super::BeginPlay();
	UWorld * World = GetWorld();
	GetWorld()->GetTimerManager().SetTimer(FuzeTimerHandle, this, &ACarsSpawn::SpawCars, 1.0f, true);



}

// Called every frame
void ACarsSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACarsSpawn::SpawCars() {
	UWorld * World = GetWorld();
	if (World != nullptr) {

		APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0);
		ACharacterVR* Char = Cast<ACharacterVR>(Pawn);

		float LocationX = Char->GetPlayerLocation().X + 5000.0f;
		float LocationZ = 12.0f;



		Ramdom = FMath::RandRange(0, 4);
		//UE_LOG(LogTemp, Warning, TEXT("Random: %d"), Ramdom);
		FActorSpawnParameters SpawParameters;

		if (Ramdom == 1) {
			FVector Location(LocationX, -50.0f, LocationZ);
			ACarro * carro = World->SpawnActor<ACarro>(Location, FRotator::ZeroRotator, SpawParameters);
			LocationX += 5000.0f;
			CountCarsToSpawn++;
			//UE_LOG(LogTemp, Warning, TEXT("carro 1"));
		}

		else if (Ramdom == 0) {
			FVector Location(LocationX, -6.0f, LocationZ);
			ACarro * carro = World->SpawnActor<ACarro>(Location, FRotator::ZeroRotator, SpawParameters);
			LocationX += 5000.0f;
			CountCarsToSpawn++;
			//UE_LOG(LogTemp, Warning, TEXT("carro 2"));
		}



	}
}

