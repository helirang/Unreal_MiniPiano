// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InstrumentPlayer.generated.h"

class AInstrument;

UCLASS()
class MINIPROJECT_PIANO_API AInstrumentPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AInstrumentPlayer();

protected:
	virtual void BeginPlay() override;
	
	// �Ǳ� ���� Ű�� ���ε��� �Լ���
	void Key0();
	void Key1();
	void Key2();
	void Key3();
	void Key4();
	void Key5();
	void Key6();
	void Key7();
	void ModeChange();

public:	
	UFUNCTION(BlueprintCallable)
	AInstrument* GetInstrument();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	//������ �Ǳ� class
	UPROPERTY(EditAnywhere, Category = "Instrument")
	TSubclassOf<AInstrument> instrumentClass;
	//���� ������ �Ǳ� actor
	UPROPERTY(EditAnywhere, Category = "Instrument")
	AInstrument* currentInstrument;
};
