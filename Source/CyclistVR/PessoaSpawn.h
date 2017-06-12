// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PessoaSpawn.generated.h"

UCLASS()
class CYCLISTVR_API APessoaSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APessoaSpawn();

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
		TSubclassOf<class APessoa> Pessoa;

	UPROPERTY(EditAnywhere)
		int CountPessoaToSpawn;
	int Ramdom;
	UPROPERTY(EditAnywhere)
		FTimerHandle FuzeTimerHandle;

	UFUNCTION()
		void  SpawPessoas();
	UPROPERTY(EditAnywhere)
		int levelProgress;
	
};
