#pragma once
#include "Character.h"
class Enemy : public Character
{
public:
	Enemy(ModeBase* game);
	virtual ~Enemy();
	void RegisterAnimation()override;
	void Initialize()override;
	void Process()override;
	void Render()override;
protected:
};

