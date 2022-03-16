// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Instrument.generated.h"

class UAudioComponent;
class ASoundWarehouse;
class USoundRecoder;
//class USoundWarehouse;

UCLASS()
class MINIPROJECT_PIANO_API AInstrument : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInstrument();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	virtual void Tick(float DeltaTime) override;

	//staccatoAudio 및 harmonyAudioArr 생성
	void AudioMake();
	//staccatoAudio 및 harmonyAudioArr에 SoundWarehouse에 들어있는 소리를 셋팅
	void AudioSetting();
	//soundNum에 해당되는 소리 재생 0'도' ~ 7'도' 한 음계
	void PlaySound(int soundNum);

public:
	//악기가 작동하는 컨트롤러 부분, 소리 재생, 메테리얼 변환 등 모든 작동에 트리거 역할을 한다.
	virtual void PlayInstrument(int soundNum);
	//단음모드 화음모드 변경
	UFUNCTION(BlueprintCallable, Category = "Mode")
	void ModeChange();
	//기록된 악보로 자동연주 On Off
	UFUNCTION(BlueprintCallable, Category = "AutoPlay")
	void StartAutoPlay(bool bOnOff);

protected:
	//harmony sound set [ 화음 사운드 설정 ]
	TArray<UAudioComponent*> harmonyAudioArr;
	//staccato sound set [ 단음 사운드 설정 ]
	UPROPERTY(BlueprintReadOnly, Category = "Audio")
	UAudioComponent* staccatoAudio;
	//생성할 음원 창고 액터 클래스
	UPROPERTY(EditAnywhere, Category = "Instrument")
	TSubclassOf<ASoundWarehouse> soundWarehouseClass;
	//현재 생성된 음원 창고 액터
	UPROPERTY(EditAnywhere, Category = "Instrument")
	ASoundWarehouse* currentSoundWarehouse;
	//악보 기록 액터 컴포넌트
	UPROPERTY(BlueprintReadOnly, Category = "Recoder")
	USoundRecoder* sheetRecoder;
	//단음 모드인지 화음 모드인지 체크
	bool bMode;
	//해당 악기의 키를 press하는건지 relese하는 건지 체크
	TArray<bool> bKeyPressOrRelese;
	//Recoder에서 추출한 연주용 악보 배열
	UPROPERTY(BlueprintReadWrite,Category = "Recoder")
	TArray<FString> sheetMusicArr;
	//자동 연주 시, 현재 연주되고 있는 음의 배열 위치
	int sheetNum;
	//자동 연주 시, 악보 대기 시간 경과 여부
	bool bNext;
	//대기 시간 경과에 사용되는 float변수 두개
	float waitTime;
	float timeCheck;
};
