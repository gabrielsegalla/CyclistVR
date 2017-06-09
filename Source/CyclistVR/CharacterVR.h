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

	UFUNCTION(BlueprintCallable, Category = "Player")
		int GetLife();
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetLife(int NewLife);

	UFUNCTION(BlueprintCallable, Category = "Player")
		FVector GetPlayerLocation();
	UFUNCTION(BlueprintCallable, Category = "Player")
		int GetQuilometragem();
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetQuilometragem(int NewQuilometragem);
	UFUNCTION(BlueprintCallable, Category = "Player")
		int GetVelocidade();
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetVelocidade(int NewVelocidade);
	UFUNCTION(BlueprintCallable, Category = "Player")
		void RestartGame();

private:
	// BlueprintReadWrite || BlueprintReadOnly
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere)
		int Life = 100;
	UPROPERTY(EditAnywhere)
		int Quilometragem = 0;
	UPROPERTY(EditAnywhere)
		int Velocidade = 5;
	UFUNCTION()
		void RotateHead();
	UPROPERTY(EditAnywhere)
		USoundCue *level;
	UPROPERTY(EditAnywhere)
		UAudioComponent *AudioComp;
	
};