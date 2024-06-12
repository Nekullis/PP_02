#pragma once
#include "Enemy.h"
class EnemyMob : public Enemy
{
public:
	EnemyMob(ModeBase* game);
	virtual ~EnemyMob();
	void Initialize()override;
	void Process()override;
	void Render()override;
};

