#include "ModeGame.h"
#include "Player.h"
#include "MoveComponent.h"
#include "DrawComponent.h"
#include "Stage.h"
bool ModeGame::Initialize()
{
	if (!ModeBase::Initialize()) { return false; }
	//オブジェクトマネージャー初期化
	mManager = new ObjectManager();
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
	Player* player = new Player(this);
	Stage* stage = new Stage(this);
}

bool ModeGame::Process()
{
	ModeBase::Process();
	mManager->Process();
	return true;
}

bool ModeGame::Render()
{
	SetUseZBuffer3D(true);
	//SetWriteZBuffer3D(true);
	SetUseLighting(true);
	ChangeLightTypeDir(Vector3D(0,-1,0).dxl());
	ModeBase::Render();
	mManager->Render();
	return true;
}




