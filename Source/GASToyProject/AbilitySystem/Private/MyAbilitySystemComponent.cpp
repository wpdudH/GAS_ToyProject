// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAbilitySystemComponent.h"

UMyAbilitySystemComponent::UMyAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
}

void UMyAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}