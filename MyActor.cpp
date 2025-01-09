// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

using namespace std;

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StartPos = FVector2D::ZeroVector;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < 10; i++)
	{
		Move();
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AMyActor::Move()
{
	StepCount++;

	FVector2D Prev = FVector2D(StartPos.X, StartPos.Y);
	FVector2D NewPos = FVector2D(StartPos);

	StartPos = FVector2D(StartPos.X + Step(), StartPos.Y + Step());

	FVector2D Temp = StartPos - Prev;

	TotalDistance += Temp.Length();

	UE_LOG(LogTemp, Log, TEXT("%s ---- Distance : %f"), *StartPos.ToString(), Temp.Length());

	if (GetStepCount() % 10 == 0)
	{
		if (IsEvent())
		{
			UE_LOG(LogTemp, Display, TEXT("랜덤 이벤트 발생 !!"));
		}
		else
		{
			UE_LOG(LogTemp, Display, TEXT("랜덤 이벤트 발생 안함 !!"));
		}
		UE_LOG(LogTemp, Warning, TEXT("%hs : %d"), "Step Count", GetStepCount());
		UE_LOG(LogTemp, Warning, TEXT("%hs : %f"), "Total Distance", TotalDistance);
	}
}

int AMyActor::Step()
{
	int step = FMath::RandRange(0, 1);
	return step;
}

int AMyActor::GetStepCount() const
{
	return StepCount;
}

bool AMyActor::IsEvent()
{
	int Temp = FMath::RandRange(0, 1);

	bool bResult = Temp == 0;
	return bResult;
}
