// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundWarehouse.generated.h"

class USoundCue;

UCLASS()
class MINIPROJECT_PIANO_API ASoundWarehouse : public AActor
{
	GENERATED_BODY()
	
public:	
	ASoundWarehouse();

protected:


public:	
	//���� ����
	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundCue* staccatoSound;
	//ȭ�� ����
	UPROPERTY(EditAnywhere, Category = "Sound")
	TArray<USoundCue*> harmonySoundArr;
};
