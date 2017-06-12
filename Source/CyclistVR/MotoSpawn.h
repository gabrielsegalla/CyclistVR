// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MotoSpawn.generated.h"

UCLASS()
class CYCLISTVR_API AMotoSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMotoSpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		USceneComponent * Root;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AMoto> Moto;

	UPROPERTY(EditAnywhere)
		int CountMotoToSpawn;
	int Ramdom;
	UPROPERTY(EditAnywhere)
		FTimerHandle FuzeTimerHandle;

	UFUNCTION()
		void  SpawMoto();

	UPROPERTY(EditAnywhere)
		int levelProgress;
	
};
