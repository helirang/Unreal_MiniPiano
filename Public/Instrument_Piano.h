// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Instrument.h"
#include "Instrument_Piano.generated.h"

class APianoKeyboard;
/**
 * 
 */
UCLASS()
class MINIPROJECT_PIANO_API AInstrument_Piano : public AInstrument
{
	GENERATED_BODY()
private:
	//�ǹ��� ���׸����� �����ϴ� �Լ�
	void ChangeKeyboardMetarial(int soundNum);
public:
	//Instrument�� ���� ����� �������̵��ϴ� �Լ�
	virtual void PlayInstrument(int soundNum) override;
	//BeginPlay���� world�� �����Ǿ��ִ� piano �ǹݵ��� keyboardArr�� �����Ѵ�. @todo Instrument���� �ǹ��� �����ϰ� ����
	virtual void BeginPlay() override;
private:
	//���׸����� ������ Piano ���͵��� �迭
	TArray<APianoKeyboard*> keyboardArr;
};
