#pragma once
#include "AppFrame.h"
class ModeSound : public ModeBase
{
public:
	bool Initialize()override;
	bool Terminate()override;
	bool Process()override;
	bool Render()override;
};

