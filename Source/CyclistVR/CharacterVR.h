// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CharacterVR.generated.h"

UCLASS()
class CYCLISTVR_API ACharacterVR : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterVR();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere)
		int Life = 100;
	UPROPERTY(EditAnywhere)
		int Quilometragem;	

	UFUNCTION()
		void RotateHead();
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
