// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PianoKeyboard.generated.h"

class USkeletalMesh;

UCLASS()
class MINIPROJECT_PIANO_API APianoKeyboard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APianoKeyboard();
	//�ǾƳ� �ǹ��� ���� �ٲٴ� �Լ�. original <-> pressed
	void ChangedMaterial();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	//����ƽ�Ž�������Ʈ
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* meshComp;

public:
	//���� �ǹ��� ����
	bool bcheck;
	//������ ����ƽ �Ž��� �Ҵ��� ����
	UStaticMesh* staticMesh;

	//������ ���׸����
	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UMaterialInterface* original;
	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UMaterialInterface* pressed;
};
