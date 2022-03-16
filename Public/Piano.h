// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Piano.generated.h"

class USkeletalMesh;

UCLASS()
class MINIPROJECT_PIANO_API APiano : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APiano();
	virtual void BeginPlay() override;
	void ChangedMaterial();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

public:
	bool check;
	UStaticMesh* SK_Mesh;

	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UMaterialInterface* Original;

	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UMaterialInterface* pressed;
};
