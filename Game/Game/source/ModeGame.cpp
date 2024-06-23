#include "ModeGame.h"
#include "Player.h"
#include "Stage.h"
#include "EnemyMob.h"
#include "TargetMaker.h"
#include "ObjectManager.h"
#include "GameCollision.h"
#include "CollisionManager.h"
bool ModeGame::Initialize()
{
	if (!ModeBase::Initialize()) { return false; }
	//オブジェクトマネージャー初期化
	mObjManager = new ObjectManager();
	//コリジョン系統のクラス初期化
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
	//プレイヤー追加
	Player* player = new Player(this);
	//
	TargetMaker* maker = new TargetMaker(this);
	//敵追加
	EnemyMob* mob_l = new EnemyMob(this);
	mob_l->SetPos(Vector3D(-500, 100, 1000));
	//ステージ追加
	Stage* stage = new Stage(this);
}

bool ModeGame::Process()
{
	//各プロセスの更新
	ModeBase::Process();
	mColManager->Update();
	mObjManager->Process();
	mGameCol->Update();
	return true;
}

bool ModeGame::Render()
{
	//zバッファー有効化
	SetUseZBuffer3D(true);
	//zバッファー書き込み設定
	SetWriteZBuffer3D(true);
	//ライト有効化
	SetUseLighting(true);
	//ライトタイプをディレクショナルタイプに設定
	ChangeLightTypeDir(Vector3D(0,-1,1).dxl());
	ModeBase::Render();
	mObjManager->Render();
	return true;
}




