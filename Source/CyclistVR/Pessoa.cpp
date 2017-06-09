// Fill out your copyright notice in the Description page of Project Settings.

#include "CyclistVR.h"
#include "Pessoa.h"
#include "CharacterVR.h"


// Sets default values
APessoa::APessoa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &APessoa::OnOverlapBegin);
	Root->SetWorldScale3D(FVector(0.09375f, 0.095581f, 0.375f));

	RootComponent = Root;
	sexo = FMath::RandRange(0, 1);
	if (sexo == 1) {
		MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
		MeshComp->SetCollisionProfileName("NoCollision");
		MeshComp->SetWorldRotation(FRotator(0.0f, 90.0f, 0.0f));
		MeshComp->SetWorldScale3D(FVector(1.299617f, 1.479864f, 0.36248f));

		ConstructorHelpers::FObjectFinder<USkeletalMesh>
			Mesh(TEXT("SkeletalMesh'/Game/FBX/VRCYCLE_3D/Men/men_animation.men_animation'"));

		if (Mesh.Succeeded()) {
			MeshComp->SetSkeletalMesh(Mesh.Object);

		}
		ConstructorHelpers::FObjectFinder<UAnimSequence>AnimWalkingLoad(TEXT("AnimSequence'/Game/FBX/VRCYCLE_3D/Men/men_animation_Anim.men_animation_Anim'"));
		if (AnimWalkingLoad.Succeeded()) {
			AnimWalking = AnimWalkingLoad.Object;
		}
		MeshComp->SetupAttachment(RootComponent);
	}
	else {
		MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
		MeshComp->SetCollisionProfileName("NoCollision");
		MeshComp->SetWorldRotation(FRotator(0.0f, 90.0f, 0.0f));
		MeshComp->SetWorldScale3D(FVector(1.299617f, 1.479864f, 0.36248f));

		ConstructorHelpers::FObjectFinder<USkeletalMesh>
			Mesh(TEXT("SkeletalMesh'/Game/FBX/VRCYCLE_3D/woman/woman.woman'"));

		if (Mesh.Succeeded()) {
			MeshComp->SetSkeletalMesh(Mesh.Object);

		}
		ConstructorHelpers::FObjectFinder<UAnimSequence>AnimWalkingLoad(TEXT("AnimSequence'/Game/FBX/VRCYCLE_3D/woman/woman_Anim.woman_Anim'"));
		if (AnimWalkingLoad.Succeeded()) {
			AnimWalking = AnimWalkingLoad.Object;
		}
		MeshComp->SetupAttachment(RootComponent);
	}
	
	

}

// Called when the game starts or when spawned
void APessoa::BeginPlay()
{
	Super::BeginPlay();
	if (AnimWalking != nullptr) {
		MeshComp->PlayAnimation(AnimWalking, true);
		UE_LOG(LogTemp, Warning, TEXT("men isn walking"));


	}
	
}

// Called every frame
void APessoa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector ActualLocation = Root->GetComponentLocation();
	ActualLocation.X -= 0.5;
	Root->SetWorldLocation(ActualLocation);

}

void APessoa::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherActor->IsA(ACharacterVR::StaticClass())) {

		ACharacterVR* Char = Cast<ACharacterVR>(OtherActor);
		Char->SetLife(0);
	}

}

