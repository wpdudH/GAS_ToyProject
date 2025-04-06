// Copyright Epic Games, Inc. All Rights Reserved.

#include "GASToyProjectGameMode.h"
#include "GASToyProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGASToyProjectGameMode::AGASToyProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
