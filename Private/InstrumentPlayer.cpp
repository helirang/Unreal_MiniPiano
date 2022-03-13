// Fill out your copyright notice in the Description page of Project Settings.

#include "InstrumentPlayer.h"
#include "Components/InputComponent.h"
#include "Instrument.h"

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
	if (DebugInstrumentPlayer) {
		if(!currentInstrument)
		UE_LOG(LogTemp, Warning,TEXT("none instrument"));
	}
}

void AInstrumentPlayer::testKey()
{
	currentInstrument->Key0();
}

// Called to bind functionality to input
void AInstrumentPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("On_0", IE_Pressed, this, &AInstrumentPlayer::testKey);
	PlayerInputComponent->BindAction("On_0", IE_Released, this, &AInstrumentPlayer::testKey);
	PlayerInputComponent->BindAction("On_1", IE_Pressed, this, &AInstrumentPlayer::Key1);
	PlayerInputComponent->BindAction("On_1", IE_Released, this, &AInstrumentPlayer::Key1);
	PlayerInputComponent->BindAction("On_2", IE_Pressed, this, &AInstrumentPlayer::Key2);
	PlayerInputComponent->BindAction("On_2", IE_Released, this, &AInstrumentPlayer::Key2);
	PlayerInputComponent->BindAction("On_3", IE_Pressed, this, &AInstrumentPlayer::Key3);
	PlayerInputComponent->BindAction("On_3", IE_Released, this, &AInstrumentPlayer::Key3);
	PlayerInputComponent->BindAction("On_4", IE_Pressed, this, &AInstrumentPlayer::Key4);
	PlayerInputComponent->BindAction("On_4", IE_Released, this, &AInstrumentPlayer::Key4);
	PlayerInputComponent->BindAction("On_5", IE_Pressed, this, &AInstrumentPlayer::Key5);
	PlayerInputComponent->BindAction("On_5", IE_Released, this, &AInstrumentPlayer::Key5);
	PlayerInputComponent->BindAction("On_6", IE_Pressed, this, &AInstrumentPlayer::Key6);
	PlayerInputComponent->BindAction("On_6", IE_Released, this, &AInstrumentPlayer::Key6);
	PlayerInputComponent->BindAction("On_7", IE_Pressed, this, &AInstrumentPlayer::Key7);
	PlayerInputComponent->BindAction("On_7", IE_Released, this, &AInstrumentPlayer::Key7);
	PlayerInputComponent->BindAction("On_8", IE_Pressed, this, &AInstrumentPlayer::Key8);
	PlayerInputComponent->BindAction("On_8", IE_Released, this, &AInstrumentPlayer::Key8);
	PlayerInputComponent->BindAction("On_9", IE_Pressed, this, &AInstrumentPlayer::Key9);
	PlayerInputComponent->BindAction("On_9", IE_Released, this, &AInstrumentPlayer::Key9);
	//PlayerInputComponent->BindAction("On_Enter", IE_Pressed, this, &AInstrumentPlayer::ModeChange);
}

void AInstrumentPlayer::Key0()
{

}

void AInstrumentPlayer::Key1()
{
}

void AInstrumentPlayer::Key2()
{
}

void AInstrumentPlayer::Key3()
{
}

void AInstrumentPlayer::Key4()
{
}

void AInstrumentPlayer::Key5()
{
}

void AInstrumentPlayer::Key6()
{
}

void AInstrumentPlayer::Key7()
{
}

void AInstrumentPlayer::Key8()
{
}

void AInstrumentPlayer::Key9()
{
}

void AInstrumentPlayer::ModeChange()
{

}

