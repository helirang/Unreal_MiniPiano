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

	//staccatoAudio �� harmonyAudioArr ����
	void AudioMake();
	//staccatoAudio �� harmonyAudioArr�� SoundWarehouse�� ����ִ� �Ҹ��� ����
	void AudioSetting();
	//soundNum�� �ش�Ǵ� �Ҹ� ��� 0'��' ~ 7'��' �� ����
	void PlaySound(int soundNum);

public:
	//�ǱⰡ �۵��ϴ� ��Ʈ�ѷ� �κ�, �Ҹ� ���, ���׸��� ��ȯ �� ��� �۵��� Ʈ���� ������ �Ѵ�.
	virtual void PlayInstrument(int soundNum);
	//������� ȭ����� ����
	UFUNCTION(BlueprintCallable, Category = "Mode")
	void ModeChange();
	//��ϵ� �Ǻ��� �ڵ����� On Off
	UFUNCTION(BlueprintCallable, Category = "AutoPlay")
	void StartAutoPlay(bool bOnOff);

protected:
	//harmony sound set [ ȭ�� ���� ���� ]
	TArray<UAudioComponent*> harmonyAudioArr;
	//staccato sound set [ ���� ���� ���� ]
	UPROPERTY(BlueprintReadOnly, Category = "Audio")
	UAudioComponent* staccatoAudio;
	//������ ���� â�� ���� Ŭ����
	UPROPERTY(EditAnywhere, Category = "Instrument")
	TSubclassOf<ASoundWarehouse> soundWarehouseClass;
	//���� ������ ���� â�� ����
	UPROPERTY(EditAnywhere, Category = "Instrument")
	ASoundWarehouse* currentSoundWarehouse;
	//�Ǻ� ��� ���� ������Ʈ
	UPROPERTY(BlueprintReadOnly, Category = "Recoder")
	USoundRecoder* sheetRecoder;
	//���� ������� ȭ�� ������� üũ
	bool bMode;
	//�ش� �Ǳ��� Ű�� press�ϴ°��� relese�ϴ� ���� üũ
	TArray<bool> bKeyPressOrRelese;
	//Recoder���� ������ ���ֿ� �Ǻ� �迭
	UPROPERTY(BlueprintReadWrite,Category = "Recoder")
	TArray<FString> sheetMusicArr;
	//�ڵ� ���� ��, ���� ���ֵǰ� �ִ� ���� �迭 ��ġ
	int sheetNum;
	//�ڵ� ���� ��, �Ǻ� ��� �ð� ��� ����
	bool bNext;
	//��� �ð� ����� ���Ǵ� float���� �ΰ�
	float waitTime;
	float timeCheck;
};
