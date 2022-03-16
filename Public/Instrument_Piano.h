// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Instrument.h"
#include "Instrument_Piano.generated.h"

class APiano;
/**
 * 
 */
UCLASS()
class MINIPROJECT_PIANO_API AInstrument_Piano : public AInstrument
{
	GENERATED_BODY()
private:
	void ChangeKeyboardMetarial(int soundNum);
public:
	virtual void PlayInstrument(int soundNum) override;
	virtual void BeginPlay() override;
private:
	TArray<APiano*> keyboardArr;
};
