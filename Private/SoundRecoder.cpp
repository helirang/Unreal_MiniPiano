// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundRecoder.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
USoundRecoder::USoundRecoder()
{
	bRecCheck = false;
	recWaitTime = 0;
	bFloorFloat = true;
}

void USoundRecoder::RecOnOff(bool bOnOffInput)
{
	if (bOnOffInput)
	{
		bRecCheck = bOnOffInput;
		bIsFirst = true;
		SheetMusicRecStr.Empty();
	}
}

void USoundRecoder::FloatLimit(bool bOnOffInput)
{
	bFloorFloat = bOnOffInput;
}

FString USoundRecoder::GetSheetMusic()
{
	return SheetMusicRecStr;
}

TArray<FString> USoundRecoder::GetSheetMusicForPlay(FString musicArray)
{
	SheetMusicForPlayArray.Empty();
	musicArray.ParseIntoArray(SheetMusicForPlayArray, TEXT("/"));
	return SheetMusicForPlayArray;
}

void USoundRecoder::RecordSheetMusic(int soundNum)
{
	if (bRecCheck) 
	{
		if (bIsFirst) timeCheck = GetWorld()->GetTimeSeconds();
		recWaitTime = GetWorld()->GetTimeSeconds() - timeCheck;
		if (bFloorFloat) recWaitTime=FMath::FloorToFloat(recWaitTime * 100) / 100;
		if (bIsFirst) 
		{
			SheetMusicRecStr += FString::SanitizeFloat(recWaitTime);
			bIsFirst = false;
		}
		else
		{
			SheetMusicRecStr += "/" + FString::SanitizeFloat(recWaitTime);
		}
		SheetMusicRecStr += "/" + FString::FromInt(soundNum);
		timeCheck = GetWorld()->GetTimeSeconds();
	}
}