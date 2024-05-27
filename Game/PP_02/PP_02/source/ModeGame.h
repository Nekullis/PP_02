#pragma once
#include "ModeBase.h"
#include "ObjectManager.h"
class ModeGame : public ModeBase
{
public:
	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();
	//���������̓o�^�֘A�S��
	void Register();
protected:
	ObjectManager* mManager;
};

