#pragma once
#include "Component.h"
#include "GameXPad.h"
class MoveComponent : public Component
{
public:
	MoveComponent(class ObjectBase* owner, int updateowder = 100);
	virtual ~MoveComponent();
	//çXêV
	void Update()override;
protected:
	GameXPad* mPad;

};

