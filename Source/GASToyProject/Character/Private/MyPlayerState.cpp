// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"
#include "MyAbilitySystemComponent.h"
#include "MyAttributeSet.h"

// Sets default values
AMyPlayerState::AMyPlayerState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UMyAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UMyAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AMyPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UMyAttributeSet* AMyPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

