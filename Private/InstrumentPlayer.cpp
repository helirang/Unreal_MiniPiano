// Fill out your copyright notice in the Description page of Project Settings.

#include "InstrumentPlayer.h"
#include "Components/InputComponent.h"
#include "Instrument.h"
#include "Engine/World.h"

static int32 DebugInstrumentPlayer= 0;
FAutoConsoleVariableRef CVARDebugInstrumentPlaye(
	TEXT("MainGame.DebugInstrumentPlayer"),
	DebugInstrumentPlayer,
	TEXT("Debug InstrumentPlayer"),
	ECVF_Cheat);

// Sets default values
AInstrumentPlayer::AInstrumentPlayer()
{
}

// Called when the game starts or when spawned
void AInstrumentPlayer::BeginPlay()
{
	Super::BeginPlay();
	currentInstrument = GetWorld()->SpawnActor<AInstrument>(instrumentClass, FVector::ZeroVector, FRotator::ZeroRotator);
	currentInstrument->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	if (DebugInstrumentPlayer) {
		if(!currentInstrument)
		UE_LOG(LogTemp, Warning,TEXT("none instrument"));
	}
}

AInstrument* AInstrumentPlayer::GetInstrument()
{
	return currentInstrument;
}

// Called to bind functionality to input
void AInstrumentPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("On_0", IE_Pressed, this, &AInstrumentPlayer::Key0);
	PlayerInputComponent->BindAction("On_1", IE_Pressed, this, &AInstrumentPlayer::Key1);
	PlayerInputComponent->BindAction("On_2", IE_Pressed, this, &AInstrumentPlayer::Key2);
	PlayerInputComponent->BindAction("On_3", IE_Pressed, this, &AInstrumentPlayer::Key3);
	PlayerInputComponent->BindAction("On_4", IE_Pressed, this, &AInstrumentPlayer::Key4);
	PlayerInputComponent->BindAction("On_5", IE_Pressed, this, &AInstrumentPlayer::Key5);
	PlayerInputComponent->BindAction("On_6", IE_Pressed, this, &AInstrumentPlayer::Key6);
	PlayerInputComponent->BindAction("On_7", IE_Pressed, this, &AInstrumentPlayer::Key7);
	PlayerInputComponent->BindAction("On_Tab", IE_Pressed, this, &AInstrumentPlayer::ModeChange);

	PlayerInputComponent->BindAction("On_0", IE_Released, this, &AInstrumentPlayer::Key0);
	PlayerInputComponent->BindAction("On_1", IE_Released, this, &AInstrumentPlayer::Key1);
	PlayerInputComponent->BindAction("On_2", IE_Released, this, &AInstrumentPlayer::Key2);
	PlayerInputComponent->BindAction("On_3", IE_Released, this, &AInstrumentPlayer::Key3);
	PlayerInputComponent->BindAction("On_4", IE_Released, this, &AInstrumentPlayer::Key4);
	PlayerInputComponent->BindAction("On_5", IE_Released, this, &AInstrumentPlayer::Key5);
	PlayerInputComponent->BindAction("On_6", IE_Released, this, &AInstrumentPlayer::Key6);
	PlayerInputComponent->BindAction("On_7", IE_Released, this, &AInstrumentPlayer::Key7);
}

void AInstrumentPlayer::Key0()
{
	currentInstrument->PlayInstrument(0);
}

void AInstrumentPlayer::Key1()
{
	currentInstrument->PlayInstrument(1);
}

void AInstrumentPlayer::Key2()
{
	currentInstrument->PlayInstrument(2);
}

void AInstrumentPlayer::Key3()
{
	currentInstrument->PlayInstrument(3);
}

void AInstrumentPlayer::Key4()
{
	currentInstrument->PlayInstrument(4);
}

void AInstrumentPlayer::Key5()
{
	currentInstrument->PlayInstrument(5);
}

void AInstrumentPlayer::Key6()
{
	currentInstrument->PlayInstrument(6);
}

void AInstrumentPlayer::Key7()
{
	currentInstrument->PlayInstrument(7);
}

void AInstrumentPlayer::ModeChange()
{
	currentInstrument->ModeChange();
}