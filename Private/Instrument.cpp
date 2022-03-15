// Fill out your copyright notice in the Description page of Project Settings.

#include "Instrument.h"
#include "Components/AudioComponent.h"
#include "SoundWarehouse.h"
#include "Sound/SoundCue.h"
#include "Engine/World.h"
#include "SoundRecoder.h"
#include "Kismet/KismetSystemLibrary.h"

static int32 DebugInstrument = 0;
FAutoConsoleVariableRef CVARDebugInstrument(
	TEXT("MainGame.DebugInstrument"),
	DebugInstrument,
	TEXT("Debug Instrument"),
	ECVF_Cheat);

// Sets default values
AInstrument::AInstrument()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	AudioMake();
	sheetRecoder = CreateDefaultSubobject<USoundRecoder>(TEXT("SheetRecoder"));
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("root"));
}

// Called when the game starts or when spawned
void AInstrument::BeginPlay()
{
	Super::BeginPlay();
	currentSoundWarehouse = GetWorld()->SpawnActor<ASoundWarehouse>(soundWarehouseClass, FVector::ZeroVector, FRotator::ZeroRotator);
	currentSoundWarehouse->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	AudioSetting();
	bPressedOrReleased.Init(true, currentSoundWarehouse->harmonySoundArr.Num());
	bMode = false,bNext = true;
	sheetNum=0,waitTime=0,timeCheck=0;
	/*UE_LOG(LogTemp, Error, TEXT("bpressedOrReleased Num:: %d"), bPressedOrReleased.Num());*/
}

void AInstrument::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AInstrument::Tick(float DeltaTime)
{
	if (sheetMusicArr.Num() >= 2)
	{
		if (sheetNum >= sheetMusicArr.Num()) {
			SetActorTickEnabled(false);
			UE_LOG(LogTemp, Error, TEXT("instrument Arra over floor"));
			return;
		}

		if (bNext)
		{
			waitTime = FCString::Atof(*sheetMusicArr[sheetNum]);
			/*UE_LOG(LogTemp, Error, TEXT("waitTime : %f "), WaitTime);*/
			timeCheck = waitTime + GetWorld()->GetTimeSeconds();
			/*UE_LOG(LogTemp, Error, TEXT("SetTimeCheck : %f "), SetTimeCheck);*/
			bNext = !bNext;
			sheetNum++;
		}
		else
		{
			if (timeCheck <= GetWorld()->GetTimeSeconds())
			{
				if (0 <= FCString::Atoi(*sheetMusicArr[sheetNum]) && FCString::Atoi(*sheetMusicArr[sheetNum]) < harmonyAudioArr.Num())
				{
					PlayInstrument(FCString::Atoi(*sheetMusicArr[sheetNum]));
					bNext = !bNext;
					sheetNum++;
					if (sheetMusicArr.Num() <= sheetNum)
					{
						SetActorTickEnabled(false);
						sheetNum = 0;
						sheetMusicArr.Empty();
					}
				}
			}
		}
	}
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

void AInstrument::PlayInstrument(int soundNum)
{
	PlaySound(soundNum);
	sheetRecoder->RecordSheetMusic(soundNum);
}

void AInstrument::ModeChange()
{
	bMode = !bMode;
}

void AInstrument::StartAutoPlay(bool bOnOff)
{
	if (bOnOff) 
	{
		SetActorTickEnabled(true);
	}
	else
	{
		SetActorTickEnabled(false);
	}
}

void AInstrument::PlaySound(int soundNum)
{
	if (soundNum >= harmonyAudioArr.Num()) {
		UE_LOG(LogTemp, Error, TEXT("sound Num spill over Array"));
		return;
	}
	/*UE_LOG(LogTemp, Log, TEXT("bPressedOrReleased :: %s"), bPressedOrReleased[soundNum] ? TEXT("true") : TEXT("false"));*/
	if (bPressedOrReleased[soundNum])
	{
		if (bMode)
		{
			staccatoAudio->SetIntParameter(FName("SoundPitchSwPa"), soundNum);
			staccatoAudio->Play();
		}
		else
		{
			harmonyAudioArr[soundNum]->Play();
		}
		bPressedOrReleased[soundNum] = false;
	}
	else
	{
		bPressedOrReleased[soundNum] = true;
	}
}
