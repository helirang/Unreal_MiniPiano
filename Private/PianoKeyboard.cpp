// Fill out your copyright notice in the Description page of Project Settings.

#include "PianoKeyboard.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APianoKeyboard::APianoKeyboard()
{
	PrimaryActorTick.bCanEverTick = false;
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("StaticMesh'/Game/Do_StaticMesh.Do_StaticMesh'"));
	if (staticMesh.Succeeded())
	{
		meshComp->SetStaticMesh(staticMesh.Object);
	}
	bcheck = 0;
}

// Called when the game starts or when spawned
void APianoKeyboard::BeginPlay()
{
	Super::BeginPlay();
}

void APianoKeyboard::ChangedMaterial()
{
	switch (bcheck)
	{
	case false:
		bcheck = true;
		meshComp->SetMaterial(1, pressed);
		break;
	case true:
		bcheck = false;
		meshComp->SetMaterial(1, original);
		break;
	}
}


