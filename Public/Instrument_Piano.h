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
	//건반의 메테리얼을 변경하는 함수
	void ChangeKeyboardMetarial(int soundNum);
public:
	//Instrument의 연주 기능을 오버라이딩하는 함수
	virtual void PlayInstrument(int soundNum) override;
	//BeginPlay에서 world에 생성되어있는 piano 건반들을 keyboardArr에 셋팅한다. @todo Instrument에서 건반을 생성하게 변경
	virtual void BeginPlay() override;
private:
	//메테리얼을 변경할 Piano 액터들의 배열
	TArray<APianoKeyboard*> keyboardArr;
};
