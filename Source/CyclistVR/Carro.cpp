// Fill out your copyright notice in the Description page of Project Settings.

#include "CyclistVR.h"
#include "Carro.h"
#include "CharacterVR.h"


// Sets default values
ACarro::ACarro()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &ACarro::OnOverlapBegin);
	Root->SetWorldScale3D(FVector(0.412219f, 0.368846f, 0.330663f));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -33.266502f));
	MeshComp->SetWorldRotation(FRotator(0.0f, 90.0f, 0.0f));
	MeshComp->SetWorldScale3D(FVector(1.127806f, 0.966449f, 1.28775f));

	ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Mesh(TEXT("SkeletalMesh'/Game/FBX/VRCYCLE_3D/carro/carrro3.carrro3'"));

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
	ActualLocation.X -= 3;
	Root->SetWorldLocation(ActualLocation);

}

void ACarro::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherActor->IsA(ACharacterVR::StaticClass())) {
		ACharacterVR* Char = Cast<ACharacterVR>(OtherActor);
		Char->SetLife(0);
	}

}