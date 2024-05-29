#include "Stage.h"
#include "DxLib.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
Stage::Stage():ObjectBase()
{
	mManager = ObjectManager::GetInstance();
	//ステージ描画用コンポーネント初期化
	DrawComponent* draw = new DrawComponent(this);
	//パスを入れておく
	const char* pass = "res/Model/Stage/TestModel.mv1";
	//セッターでパスを登録
	draw->SetPass(pass);
	//ステージにコンポーネント登録
	this->AddComponent(draw);
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
