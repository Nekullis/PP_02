#pragma once
#include "AppFrame.h"
#include "ObjectManager.h"
#include "GameCollision.h"
#include "CollisionManager.h"
class ModeGame : public ModeBase
{
public:
	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();
	void Register();
	//�Q�b�^�[
	ObjectManager* GetManager() { return mObjManager; }
protected:
	ObjectManager* mObjManager;
	GameCollision* mGameCol;
	CollisionManager* mColManager;
};

