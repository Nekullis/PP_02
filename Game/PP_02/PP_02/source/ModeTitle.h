#pragma once
#include "ModeBase.h"
//�^�C�g��
class ModeTitle : public ModeBase
{
	using base = ModeBase;
public:
	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();
};
