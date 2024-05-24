#pragma once
#include "Component.h"
class AIComponent : public Component
{
public:
	AIComponent(class ObjectBase* owner, int updateowder = 10);
	virtual ~AIComponent();
	//XV
	void Update(float deltatime) override;
};

