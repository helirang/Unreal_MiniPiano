// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PianoKeyboard.generated.h"

class USkeletalMesh;

UCLASS()
class MINIPROJECT_PIANO_API APianoKeyboard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APianoKeyboard();
	void ChangedMaterial();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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
