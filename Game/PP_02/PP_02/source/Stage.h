#pragma once
#include "AppFrame.h"
class Stage : public ObjectBase
{
public:
	Stage();
	virtual ~Stage();
	void Initialize()override;
	void Process()override;
	void Render()override;
protected:
	int mHandle;
	class ObjectManager* mManager;
};

