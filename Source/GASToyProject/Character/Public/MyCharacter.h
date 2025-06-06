// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "MyCharacter.generated.h"

class UGameplayAbility;
class UMyAbilitySystemComponent;
class UMyAttributeSet;
class UGameplayEffect;

UCLASS()
class GASTOYPROJECT_API AMyCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// 
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual UMyAttributeSet* GetAttributeSet() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void GiveDefaultAbilities();
	void InitDefaultAttributes() const;

	UPROPERTY()
	TObjectPtr<UMyAttributeSet> AttributeSet;

	UPROPERTY()
	TObjectPtr<UMyAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	TSubclassOf<UGameplayEffect> DefaultAttributeEffect;
};
