// Fill out your copyright notice in the Description page of Project Settings.

#include "Instrument_Piano.h"
#include "SoundWarehouse.h"
#include "PianoKeyboard.h"
#include "EngineUtils.h"

void AInstrument_Piano::PlayInstrument(int soundNum)
{
	Super::PlayInstrument(soundNum);
	ChangeKeyboardMetarial(soundNum);
}

void AInstrument_Piano::BeginPlay()
{
	Super::BeginPlay();

	UWorld* currentworld = GetWorld();
	for (TActorIterator<APianoKeyboard> It(currentworld); It; ++It)
	{
		keyboardArr.Add(*It);
	}
}

void AInstrument_Piano::ChangeKeyboardMetarial(int soundNum)
{
	keyboardArr[soundNum]->ChangedMaterial();
}
