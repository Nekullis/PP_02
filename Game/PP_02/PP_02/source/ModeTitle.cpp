#include "ModeTitle.h"

bool ModeTitle::Initialize()
{
	if (!base::Initialize()) { return false; }
	return true;
}

bool ModeTitle::Terminate()
{
	base::Terminate();
	return true;
}

bool ModeTitle::Process()
{
	base::Process();
	return true;
}

bool ModeTitle::Render()
{
	base::Render();
	return true;
}
