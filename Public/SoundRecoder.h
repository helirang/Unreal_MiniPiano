// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SoundRecoder.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MINIPROJECT_PIANO_API USoundRecoder : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USoundRecoder();

protected:

public:	
	//녹음 On/Off
	UFUNCTION(BlueprintCallable, Category = "SheetMusic")
	void RecOnOff(bool bOnOffInput);
	//float값을 소수점 2자리로 제한할지 여부
	UFUNCTION(BlueprintCallable, Category = "SheetMusic")
	void FloatLimit(bool bOnOffInput);
	//기록된 악보 반환
	UFUNCTION(BlueprintCallable, Category = "SheetMusic")
	FString GetSheetMusic();
	//유저가 입력한 악보(기록된 악보 재사용 or 수정 등)를 연주용 악보로 변환한다.
	UFUNCTION(BlueprintCallable, Category = "PlaySheetMusic")
	TArray<FString> GetSheetMusicForPlay(FString musicArray);
	//입력(soundNum)에 따라 악보 기록
	void RecordSheetMusic(int soundNum);

protected:
	//녹음 중인지 여부
	bool bRecCheck;
	//float값을 소수점 2자리로로 제한할지 여부
	bool bFloorFloat;
	//첫 기록인지 여부, 첫 기록이면 첫음을 치기 전까지의 대기 시간은 기록하지 않는다.
	bool bIsFirst;
	//기록 악보
	FString SheetMusicRecStr;
	//연주용 악보
	TArray<FString> SheetMusicForPlayArray;
	//다음 음 연주 시까지 대기 시간 기록
	float recWaitTime;
	//대기 시간 기록 보조
	float timeCheck;
};
