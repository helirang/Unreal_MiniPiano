// Fill out your copyright notice in the Description page of Project Settings.

#include "PianoKeyboard.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APianoKeyboard::APianoKeyboard()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> SK_Mesh(TEXT("StaticMesh'/Game/Do_StaticMesh.Do_StaticMesh'"));
	if (SK_Mesh.Succeeded())
	{
		MeshComp->SetStaticMesh(SK_Mesh.Object);
	}
	check = 0;
}

// Called when the game starts or when spawned
void APianoKeyboard::BeginPlay()
{
	Super::BeginPlay();
	
}

void APianoKeyboard::ChangedMaterial()
{
	//check = true;

	switch (check)
	{
	case false:
		check = true;
		MeshComp->SetMaterial(1, pressed);
		break;
	case true:
		check = false;
		MeshComp->SetMaterial(1, Original);
		break;
	}
}


