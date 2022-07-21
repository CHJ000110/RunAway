// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CHJ/RunAwayPlayer.h"
#include "PlayerMove.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNAWAY_API UPlayerMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
	//力老刚历 角青凳
	virtual void InitializeComponent() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	void Horizontal(float v);

	void Vertical(float v);
	void Turn(float v);
	void LookUp(float v);
	void Jump();
	void Crouch();
	void UnCrouch();
	bool isFry;

public:
	UPROPERTY()
	class ARunAwayPlayer* me;
};
