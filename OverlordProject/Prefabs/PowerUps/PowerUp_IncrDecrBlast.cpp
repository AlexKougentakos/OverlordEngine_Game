﻿#include "stdafx.h"
#include "PowerUp_IncrDecrBlast.h"
#include "Prefabs/BombermanCharacter.h"

PowerUp_IncreaseBlast::PowerUp_IncreaseBlast(GridComponent* pGridComponent)
	:BasePowerUp(pGridComponent)
{
	SetTexture(texturePath);

}

void PowerUp_IncreaseBlast::Update(const SceneContext&)
{

}

void PowerUp_IncreaseBlast::OnCollision(GameObject*, GameObject* other, PxTriggerAction action)
{
	if (action == PxTriggerAction::LEAVE) return;

	const auto player = dynamic_cast<BombermanCharacter*>(other);

	if (!player) return;

	PlayerStatIncrease increase{};
	increase.blastRadius = 1;

	player->ApplyPowerup(increase);
	
	MarkForRemoval();
}

