// Fill out your copyright notice in the Description page of Project Settings.

#include "CyclistVR.h"
#include "Carro.h"


// Sets default values
ACarro::ACarro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->SetCollisionProfileName("BlockAllDynamic");
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->SetWorldRotation(FRotator(0.0f, 90.0f, 0.0f));
	MeshComp->SetWorldScale3D(FVector(0.21875f, 0.21875f, 0.21875f));

	ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Mesh(TEXT("SkeletalMesh'/Game/FBX/carro/carrro3.carrro3'"));

	if (Mesh.Succeeded()) {
		MeshComp->SetSkeletalMesh(Mesh.Object);

	}
	MeshComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACarro::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//velocidade = Root->GetComponentLocation().X - 1;
	//Root->SetWorldLocation(velocidade, Root->GetWorldLocation(), z);
	FVector ActualLocation = Root->GetComponentLocation();
	ActualLocation.X -= 5;
	Root->SetWorldLocation(ActualLocation);

}


