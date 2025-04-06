// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "MyAbilitySystemComponent.h"
#include "MyAttributeSet.h"
#include "MyPlayerState.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}


void APlayerCharacter::PossessedBy(AController* NewController)
{
	// 서버에서만 호출됨, 캐릭터가 컨트롤러에 의해 Possess 되었을 때 성립
	Super::PossessedBy(NewController);

	InitAbilitySystemComponent();
	GiveDefaultAbilities();
	InitDefaultAttributes();
}

void APlayerCharacter::OnRep_PlayerState()
{
	// 클라이언트에서만 호출됨, 서버에서 PlayerState가 Replicate 되었을 때 클라 쪽 캐릭터가 이걸 받는 시점에 호출

	Super::OnRep_PlayerState();

	InitAbilitySystemComponent();
}


void APlayerCharacter::InitAbilitySystemComponent()
{
	// PlayerState으로부터 ASC와 AttributeSet 초기화
	

	// GameMode에 설정된 PlayerState를 가져옴
	AMyPlayerState* MyPlayerState = GetPlayerState<AMyPlayerState>();
	check(MyPlayerState);

	// 맞게 캐스팅 됐는지 체크하고 AbilitySystemComponet 초기화
	AbilitySystemComponent = CastChecked<UMyAbilitySystemComponent>(
		MyPlayerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(MyPlayerState, this);
	AttributeSet = MyPlayerState->GetAttributeSet();
}