#pragma once
#include "AppFrame.h"
class Stage : public ObjectBase
{
public:
	Stage(ModeBase* game);
	virtual ~Stage();
	void Initialize()override;
	void Process()override;
	void Render()override;
protected:
	int mHandle;
	class ObjectManager* mManager;
};

