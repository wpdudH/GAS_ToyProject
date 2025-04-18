// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "MyPlayerState.generated.h"

class UMyAbilitySystemComponent;
class UMyAttributeSet;

UCLASS()
class GASTOYPROJECT_API AMyPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPlayerState();
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UMyAttributeSet* GetAttributeSet() const;


protected:
	UPROPERTY()
	TObjectPtr<UMyAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UMyAttributeSet> AttributeSet;
};
