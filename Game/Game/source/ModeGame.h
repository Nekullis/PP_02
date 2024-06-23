#pragma once
#include "AppFrame.h"

class ModeGame : public ModeBase
{
public:
	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();
	void Register();
	//ÉQÉbÉ^Å[
	class ObjectManager* GetManager() { return mObjManager; }
protected:
	class ObjectManager* mObjManager;
	class GameCollision* mGameCol;
	class CollisionManager* mColManager;
};

