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
	//‰Šú‰»‚Ì“o˜^ŠÖ˜A‘S”Ê
	void Register();
protected:
	ObjectManager* mManager;
};

