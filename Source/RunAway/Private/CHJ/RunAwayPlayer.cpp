// Fill out your copyright notice in the Description page of Project Settings.


#include "CHJ/RunAwayPlayer.h"
#include "Camera/CameraComponent.h"
#include "CHJ/PlayerMove.h"
#include "CHJ/TestDoor.h"
#include "CHJ/TestEnemy.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ARunAwayPlayer::ARunAwayPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//플레이어라고 선언
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	cameraboom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	cameraboom->SetupAttachment(GetCapsuleComponent());

	// BoxCollision  컴포넌트 등록
	collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));

	collision->SetCollisionProfileName(TEXT("BlockAll"));

	//카메라 컴포넌트
	RunCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("RunCamera"));
	//루트 컴포넌트 자식으로
	RunCamera->SetupAttachment(cameraboom);
	//바디메쉬 등록
	bodyMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(GetCapsuleComponent());

	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));

	Door = Cast<ATestDoor>(GetOwner());

	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh(TEXT("SkeletalMesh'/Game/RunAway/Develop/chj/Animation/Ch06_nonPBR.Ch06_nonPBR'"));

	if (tempMesh.Succeeded())
	{
		bodyMesh->SetSkeletalMesh(tempMesh.Object);
	}
}

// Called when the game starts or when spawned
void ARunAwayPlayer::BeginPlay()
{
	Super::BeginPlay();

	collision->OnComponentBeginOverlap.AddDynamic(this, &ARunAwayPlayer::OnTriggerEnter);
}

// Called every frame
void ARunAwayPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARunAwayPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	OnInputDelegate.Broadcast(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("DoorOpen"), IE_Pressed, this, &ARunAwayPlayer::DoorOpen);
	PlayerInputComponent->BindAction(TEXT("DoorOpen"), IE_Released, this, &ARunAwayPlayer::DoorKey);
}

void ARunAwayPlayer::OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == Door)
	{
		UE_LOG(LogTemp, Log, TEXT("door"));
		if (doorKey)
		{
			Door->Open();
			UE_LOG(LogTemp, Log, TEXT("ooooo"));
		}
	}
}

void ARunAwayPlayer::DoorOpen()
{
	doorKey = true;

	UE_LOG(LogTemp, Log, TEXT("doorKey"));
}

void ARunAwayPlayer::DoorKey()
{
	doorKey = false;;
	UE_LOG(LogTemp, Log, TEXT("OPEN2"));
}

