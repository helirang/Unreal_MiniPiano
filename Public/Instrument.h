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

	//audio ����
	void AudioMake();
	//audio�� SoundWarehouse�� ����ִ� �Ҹ� set
	void AudioSetting();

public:
	void Key0();

protected:
	//harmony sound set [ ȭ�� ���� ���� ]
	TArray<UAudioComponent*> harmonyAudioArr;
	//staccato sound set [ ���� ���� ���� ]
	UPROPERTY(BlueprintReadOnly, Category = "Audio")
	UAudioComponent* staccatoAudio;
	//������ ���� â��
	UPROPERTY(EditAnywhere, Category = "Instrument")
	TSubclassOf<ASoundWarehouse> soundWarehouseClass;
	//���� ������ ���� â��
	UPROPERTY(EditAnywhere, Category = "Instrument")
	ASoundWarehouse* currentSoundWarehouse;
};
