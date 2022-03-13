// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Instrument.generated.h"

class UAudioComponent;
class ASoundWarehouse;
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

	//audio 생성
	void AudioMake();
	//audio에 SoundWarehouse에 들어있는 소리 set
	void AudioSetting();

public:
	void Key0();

protected:
	//harmony sound set [ 화음 사운드 설정 ]
	TArray<UAudioComponent*> harmonyAudioArr;
	//staccato sound set [ 단음 사운드 설정 ]
	UPROPERTY(BlueprintReadOnly, Category = "Audio")
	UAudioComponent* staccatoAudio;
	//생성할 음원 창고
	UPROPERTY(EditAnywhere, Category = "Instrument")
	TSubclassOf<ASoundWarehouse> soundWarehouseClass;
	//현재 생성된 음원 창고
	UPROPERTY(EditAnywhere, Category = "Instrument")
	ASoundWarehouse* currentSoundWarehouse;
};
