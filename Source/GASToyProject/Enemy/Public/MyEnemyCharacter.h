// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "MyEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GASTOYPROJECT_API AMyEnemyCharacter : public AMyCharacter
{
	GENERATED_BODY()
	
public:
	AMyEnemyCharacter();

protected:
	virtual void BeginPlay() override;
};
