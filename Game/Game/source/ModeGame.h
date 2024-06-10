#pragma once
#include "AppFrame.h"
#include "ObjectManager.h"
class ModeGame : public ModeBase
{
public:
	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();
	void Register();
	//ÉQÉbÉ^Å[
	ObjectManager* GetManager() { return mManager; }
protected:
	ObjectManager* mManager;
};

