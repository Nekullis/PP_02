#include "Stage.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
Stage::Stage(ModeBase* game):ObjectBase(game)
{
	mPos = Vector3D(0, -10, 0);
	mRotation = Vector3D(0, 0, 0);
	mManager = ObjectManager::GetInstance();
	//ステージ描画用コンポーネント初期化
	DrawComponent* draw = new DrawComponent(this);
	//パスを入れておく
	const char* pass = "res/Model/Stage/StageModel.mv1";
	//セッターでパスを登録
	draw->LoadPass(pass);
	//ステージにコンポーネント登録
	//this->AddComponent(draw);
	mManager->AddDraw(draw);
	//マネージャーにステージ登録
	mManager->Spawn(this);
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	ObjectBase::Initialize();
}

void Stage::Process()
{
	ObjectBase::Process();
}

void Stage::Render()
{
	ObjectBase::Render();
}
