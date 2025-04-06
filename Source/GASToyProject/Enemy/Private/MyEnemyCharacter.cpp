// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemyCharacter.h"
#include "MyAbilitySystemComponent.h"
#include "MyAttributeSet.h"

AMyEnemyCharacter::AMyEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UMyAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UMyAttributeSet>("AttributeSet");
}

void AMyEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	GiveDefaultAbilities();
	InitDefaultAttributes();
}
