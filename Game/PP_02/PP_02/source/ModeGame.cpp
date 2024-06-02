#include "ModeGame.h"
#include "Player.h"
#include "MoveComponent.h"
#include "DrawComponent.h"
#include "Stage.h"
#include "Camera.h"
bool ModeGame::Initialize()
{
	//オブジェクトマネージャー初期化
	mManager = new ObjectManager();
	if (!ModeBase::Initialize()) { return false; }
	Register();
	return true;
}

bool ModeGame::Terminate()
{
	ModeBase::Terminate();
	return true;
}

void ModeGame::Register()
{
	Player* player = new Player();
	Stage* stage = new Stage();
}

bool ModeGame::Process()
{
	ModeBase::Process();
	mManager->Process();
	return true;
}

bool ModeGame::Render()
{
	ModeBase::Render();
	SetUseLighting(TRUE);
	ChangeLightTypeDir(Vector3D(0.5,-1,0).dxl());
	return true;
}




