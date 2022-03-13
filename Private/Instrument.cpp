// Fill out your copyright notice in the Description page of Project Settings.

#include "Instrument.h"
#include "Components/AudioComponent.h"
#include "SoundWarehouse.h"
#include "Sound/SoundCue.h"

static int32 DebugInstrument = 0;
FAutoConsoleVariableRef CVARDebugInstrument(
	TEXT("MainGame.DebugInstrument"),
	DebugInstrument,
	TEXT("Debug Instrument"),
	ECVF_Cheat);

// Sets default values
AInstrument::AInstrument()
{
	PrimaryActorTick.bCanEverTick = false;
	AudioMake();
}

// Called when the game starts or when spawned
void AInstrument::BeginPlay()
{
	Super::BeginPlay();
	currentSoundWarehouse = GetWorld()->SpawnActor<ASoundWarehouse>(soundWarehouseClass, FVector::ZeroVector, FRotator::ZeroRotator);
	currentSoundWarehouse->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	if (DebugInstrument) {
		if (!currentSoundWarehouse)
			UE_LOG(LogTemp, Warning, TEXT("none SoundWarehouse"));
	}
	AudioSetting();
}

void AInstrument::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
}

void AInstrument::AudioSetting()
{
	if (staccatoAudio->IsValidLowLevelFast())
	{
		staccatoAudio->SetSound(currentSoundWarehouse->staccatoSound);
	}

	for (int i = 0; i < currentSoundWarehouse->harmonySoundArr.Num(); i++)
	{
		if (harmonyAudioArr[i]->IsValidLowLevelFast())
			harmonyAudioArr[i]->SetSound(currentSoundWarehouse->harmonySoundArr[i]);
	}
}

void AInstrument::AudioMake()
{
	staccatoAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("staccatoAudioComp"));
	staccatoAudio->bAutoActivate = false;
	staccatoAudio->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	for (int i = 0; i < 10; i++)
	{
		FString sTempString = "HarmonyAudio" + FString::FromInt(i);
		harmonyAudioArr.Add(CreateDefaultSubobject<UAudioComponent>(FName(*sTempString)));
		harmonyAudioArr[i]->bAutoActivate = false;
		harmonyAudioArr[i]->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

void AInstrument::Key0()
{
	UE_LOG(LogTemp, Error, TEXT("tsteeeeeeeeee"));
}

