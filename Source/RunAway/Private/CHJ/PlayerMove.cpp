// Fill out your copyright notice in the Description page of Project Settings.


#include "CHJ/PlayerMove.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;
	// ...
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
}

void UPlayerMove::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &UPlayerMove::Vertical);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &UPlayerMove::Horizontal);
}

void UPlayerMove::Horizontal(float v)
{
	//аб©Л
}

void UPlayerMove::Vertical(float v)
{
	//╬у╣з

}

