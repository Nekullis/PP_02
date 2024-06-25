#pragma once
#include "AppFrame.h"

class ModeGame : public ModeBase
{
public:
	static ModeGame* gameInstance;
	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();
	void Register();
	//ÉQÉbÉ^Å[
	static ModeGame* GetInstance() { return gameInstance; }
	class ObjectManager* GetManager() { return mObjManager; }
protected:
	class ObjectManager* mObjManager;
	class GameCollision* mGameCol;
	class CollisionManager* mColManager;
	class DamageEffect* mDamageEffect;
};

