// Fill out your copyright notice in the Description page of Project Settings.


#include "CHJ/PlayerMove.h"

#include "GameFramework/PawnMovementComponent.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;
	// ...

	isFry = false;
}


// Called when the game starts
void UPlayerMove::BeginPlay()
{
	Super::BeginPlay();

	
}

void UPlayerMove::InitializeComponent()
{
	Super::InitializeComponent();
	me = Cast<ARunAwayPlayer>(GetOwner());
	if(me)
	{
		me->OnInputDelegate.AddUObject(this, &UPlayerMove::SetupPlayerInputComponent);
	}
}


// Called every frame
void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	isFry = me->GetMovementComponent()->IsFalling();
}

void UPlayerMove::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if(isFry)
	{
		
	}
	else 
	{
		PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &UPlayerMove::Vertical);
		PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &UPlayerMove::Horizontal);
	}
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &UPlayerMove::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &UPlayerMove::LookUp);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed ,this, &UPlayerMove::Jump);
}

void UPlayerMove::Horizontal(float v)
{
	//аб©Л
	FVector dir = me->GetControlRotation().Quaternion().GetRightVector();

	me->AddMovementInput(dir, v);
}

void UPlayerMove::Vertical(float v)
{
	//╬у╣з
	//FVector dir = me->GetControlRotation().Quaternion().GetForwardVector();
	//FVector dir = FRotationMatrix(me->GetControlRotation()).GetScaledAxis(EAxis::X);
	FVector dir = me->GetControlRotation().Quaternion().GetForwardVector();

	me->AddMovementInput(dir, v);

}

void UPlayerMove::Turn(float v)
{
	me->AddControllerYawInput(v);
}

void UPlayerMove::LookUp(float v)
{
	me->AddControllerPitchInput(v);
}

void UPlayerMove::Jump()
{
	me->Jump();
}

