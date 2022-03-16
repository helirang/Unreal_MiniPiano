
#include "Piano.h"
#include "ConstructorHelpers.h"
#include "Sound/SoundCue.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
APiano::APiano()
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

void APiano::BeginPlay()
{
	Super::BeginPlay();
}

void APiano::ChangedMaterial()
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


