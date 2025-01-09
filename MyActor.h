// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HELLO_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	void Move();
	int Step();
	int GetStepCount() const;
	bool IsEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	int StepCount;
	float TotalDistance;
	FVector2d StartPos;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
