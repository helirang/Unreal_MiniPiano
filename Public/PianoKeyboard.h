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
	//피아노 건반의 색을 바꾸는 함수. original <-> pressed
	void ChangedMaterial();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	//스태틱매쉬컴포넌트
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* meshComp;

public:
	//현재 건반의 상태
	bool bcheck;
	//생성한 스태틱 매쉬를 할당한 변수
	UStaticMesh* staticMesh;

	//변경할 메테리얼들
	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UMaterialInterface* original;
	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UMaterialInterface* pressed;
};
