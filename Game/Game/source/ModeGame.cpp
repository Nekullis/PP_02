#include "ModeGame.h"
#include "Player.h"
#include "Stage.h"
#include "EnemyMob.h"
bool ModeGame::Initialize()
{
	if (!ModeBase::Initialize()) { return false; }
	//オブジェクトマネージャー初期化
	
	mObjManager = new ObjectManager();
	mGameCol = new GameCollision();
	mColManager = new CollisionManager();
	Register();
	
	return true;
}

bool ModeGame::Terminate()
{
	ModeBase::Terminate();
	delete mObjManager;
	delete mGameCol;
	delete mColManager;
	return true;
}

void ModeGame::Register()
{
	Player* player = new Player(this);
	EnemyMob* mob_l = new EnemyMob(this);
	//mob_l->SetPos(Vector3D(-500, 100, 1000));
	/*EnemyMob* mob_r = new EnemyMob(this);
	mob_r->SetPos(Vector3D(100, 100, 1000));*/
	Stage* stage = new Stage(this);
}

bool ModeGame::Process()
{
	ModeBase::Process();
	mColManager->Update();
	mObjManager->Process();
	mGameCol->Update();
	return true;
}

bool ModeGame::Render()
{
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseLighting(true);
	ChangeLightTypeDir(Vector3D(0,-1,1).dxl());
	ModeBase::Render();
	mObjManager->Render();
	return true;
}




