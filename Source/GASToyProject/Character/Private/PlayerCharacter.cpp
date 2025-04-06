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
	// ���������� ȣ���, ĳ���Ͱ� ��Ʈ�ѷ��� ���� Possess �Ǿ��� �� ����
	Super::PossessedBy(NewController);

	InitAbilitySystemComponent();
	GiveDefaultAbilities();
	InitDefaultAttributes();
}

void APlayerCharacter::OnRep_PlayerState()
{
	// Ŭ���̾�Ʈ������ ȣ���, �������� PlayerState�� Replicate �Ǿ��� �� Ŭ�� �� ĳ���Ͱ� �̰� �޴� ������ ȣ��

	Super::OnRep_PlayerState();

	InitAbilitySystemComponent();
}


void APlayerCharacter::InitAbilitySystemComponent()
{
	// PlayerState���κ��� ASC�� AttributeSet �ʱ�ȭ
	

	// GameMode�� ������ PlayerState�� ������
	AMyPlayerState* MyPlayerState = GetPlayerState<AMyPlayerState>();
	check(MyPlayerState);

	// �°� ĳ���� �ƴ��� üũ�ϰ� AbilitySystemComponet �ʱ�ȭ
	AbilitySystemComponent = CastChecked<UMyAbilitySystemComponent>(
		MyPlayerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(MyPlayerState, this);
	AttributeSet = MyPlayerState->GetAttributeSet();
}