#include "ModeTitle.h"
#include "AppFrame.h"
#include "ApplicationGlobal.h"

bool ModeTitle::Initialize()
{
	if (!base::Initialize()) { return false; }
	mHandle = _global.mResManager.LoadGraph("res/Graph/Title/DivienGame_Title.png");
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
	DrawGraph(0, 0, mHandle, false);
	return true;
}
