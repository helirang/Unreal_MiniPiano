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
	TArray<APianoKeyboard*> keyboardTempArr;
	for (TActorIterator<APianoKeyboard> It(currentworld); It; ++It)
	{
		keyboardTempArr.Add(*It);
	}
	keyboardArr.Init(nullptr, keyboardTempArr.Num());
	for (int i=0; i<keyboardTempArr.Num();i++)
	{
		keyboardArr[FCString::Atoi(*keyboardTempArr[i]->GetName()) - 10] = keyboardTempArr[i];
	}
}

void AInstrument_Piano::ChangeKeyboardMetarial(int soundNum)
{
	keyboardArr[soundNum]->ChangedMaterial();
}
