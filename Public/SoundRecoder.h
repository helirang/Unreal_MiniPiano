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
	//���� On/Off
	UFUNCTION(BlueprintCallable, Category = "SheetMusic")
	void RecOnOff(bool bOnOffInput);
	//float���� �Ҽ��� 2�ڸ��� �������� ����
	UFUNCTION(BlueprintCallable, Category = "SheetMusic")
	void FloatLimit(bool bOnOffInput);
	//��ϵ� �Ǻ� ��ȯ
	UFUNCTION(BlueprintCallable, Category = "SheetMusic")
	FString GetSheetMusic();
	//������ �Է��� �Ǻ�(��ϵ� �Ǻ� ���� or ���� ��)�� ���ֿ� �Ǻ��� ��ȯ�Ѵ�.
	UFUNCTION(BlueprintCallable, Category = "PlaySheetMusic")
	TArray<FString> GetSheetMusicForPlay(FString musicArray);
	//�Է�(soundNum)�� ���� �Ǻ� ���
	void RecordSheetMusic(int soundNum);

protected:
	//���� ������ ����
	bool bRecCheck;
	//float���� �Ҽ��� 2�ڸ��η� �������� ����
	bool bFloorFloat;
	//ù ������� ����, ù ����̸� ù���� ġ�� �������� ��� �ð��� ������� �ʴ´�.
	bool bIsFirst;
	//��� �Ǻ�
	FString SheetMusicRecStr;
	//���ֿ� �Ǻ�
	TArray<FString> SheetMusicForPlayArray;
	//���� �� ���� �ñ��� ��� �ð� ���
	float recWaitTime;
	//��� �ð� ��� ����
	float timeCheck;
};
