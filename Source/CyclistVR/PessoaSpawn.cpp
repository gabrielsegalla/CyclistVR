// Fill out your copyright notice in the Description page of Project Settings.

#include "CyclistVR.h"
#include "PessoaSpawn.h"
#include "Pessoa.h"
#include "CharacterVR.h"


// Sets default values
APessoaSpawn::APessoaSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	RootComponent = Root;
	CountPessoaToSpawn = 15;

}

// Called when the game starts or when spawned
void APessoaSpawn::BeginPlay()
{
	Super::BeginPlay();
	UWorld * World = GetWorld();
	GetWorld()->GetTimerManager().SetTimer(FuzeTimerHandle, this, &APessoaSpawn::SpawPessoas, 1.0f, true);
	
}

// Called every frame
void APessoaSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APessoaSpawn::SpawPessoas() {
	UWorld * World = GetWorld();
	if (World != nullptr) {
		APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0);
		ACharacterVR* Char = Cast<ACharacterVR>(Pawn);

		float LocationX = Char->GetPlayerLocation().X + 5000.0f;
		float LocationZ = 7.0f;



		Ramdom = FMath::RandRange(0, 7);
		//UE_LOG(LogTemp, Warning, TEXT("Random: %d"), Ramdom);
		FActorSpawnParameters SpawParameters;

		if (Ramdom == 1) {
			FVector Location(LocationX, 40.0f, LocationZ);
			APessoa * pessoa = World->SpawnActor<APessoa>(Location, FRotator::ZeroRotator, SpawParameters);
			LocationX += 3000.0f;
			CountPessoaToSpawn++;
			//UE_LOG(LogTemp, Warning, TEXT("APessoa 1"));
		}

		else if (Ramdom == 0) {
			FVector Location(LocationX, -79.0f, LocationZ);
			APessoa * pessoa = World->SpawnActor<APessoa>(Location, FRotator::ZeroRotator, SpawParameters);
			LocationX += 3000.0f;
			CountPessoaToSpawn++;
			//UE_LOG(LogTemp, Warning, TEXT("APessoa 2"));
		}
		else if (Ramdom == 2) {
			FVector Location(LocationX, 28.0f, LocationZ);
			APessoa * pessoa = World->SpawnActor<APessoa>(Location, FRotator::ZeroRotator, SpawParameters);
			LocationX += 3000.0f;
			CountPessoaToSpawn++;
			//UE_LOG(LogTemp, Warning, TEXT("APessoa 3"));
		}
		else if (Ramdom == 3) {
			FVector Location(LocationX, -72.0f, LocationZ);
			APessoa * pessoa = World->SpawnActor<APessoa>(Location, FRotator::ZeroRotator, SpawParameters);
			LocationX += 3000.0f;
			CountPessoaToSpawn++;
			//UE_LOG(LogTemp, Warning, TEXT("APessoa 4"));
		}


	}
}

