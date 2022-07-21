// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RunAwayPlayer.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FPlayerInputDelegate, class UInputComponent*);

UCLASS()
class RUNAWAY_API ARunAwayPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARunAwayPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnTriggerEnter( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep ,const FHitResult& SweepResult);
	/** Delegate for notification of end of overlap with a specific component */
public:
	UPROPERTY(EditAnywhere, Category = collison)
		class UBoxComponent* collision;


	UPROPERTY(EditAnywhere, Category=camera)
	class UCameraComponent* RunCamera;

	UPROPERTY(EditAnywhere, Category = camera)
		class USpringArmComponent* cameraboom;

	UPROPERTY(EditAnywhere, Category=mesh)
	class USkeletalMeshComponent* bodyMesh;

	UPROPERTY(EditAnywhere, Category = playermove)
	class UPlayerMove* playerMove;

	void DoorOpen();

	void DoorKey();

	//UPROPERTY()
	//class UTestEnemy* monster;

	UPROPERTY()
	class ATestDoor* Door;

	bool doorKey = false;

	FPlayerInputDelegate OnInputDelegate;
};
