// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "MyAbilitySystemComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AMyCharacter::GetAbilitySystemComponent() const
{

	return AbilitySystemComponent;
}

UMyAttributeSet* AMyCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void AMyCharacter::GiveDefaultAbilities()
{
	check(AbilitySystemComponent);

	// 현재 실행 주체가 서버인지 확인
	if (!HasAuthority()) return;

	for (TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec AbilitySpec(AbilityClass, 1);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}


void AMyCharacter::InitDefaultAttributes() const
{
	if (!AbilitySystemComponent || !DefaultAttributeEffect) { return; }

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1.f, EffectContext);

	if (SpecHandle.IsValid())
	{
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}