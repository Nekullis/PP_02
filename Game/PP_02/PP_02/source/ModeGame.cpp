#include "ModeGame.h"
#include "Player.h"
#include "Component.h"
#include "MoveComponent.h"
#include "DrawComponent.h"
#include "Stage.h"
bool ModeGame::Initialize()
{
	//オブジェクトマネージャー初期化
	mManager = new ObjectManager();
	if (!ModeBase::Initialize()) { return false; }
	//登録
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
	//ステージをマネージャーに登録する
	{
		//オブジェクト(ステージ)初期化
		Stage* stage = new Stage();
		//ステージ描画用コンポーネント初期化
		DrawComponent* draw = new DrawComponent(stage);
		//パスを入れておく
		std::string pass = "res/Model/Stage/TestModel.mv1";
		//セッターでパスを登録
		draw->SetPass(pass);
		//ステージにコンポーネント登録
		stage->AddComponent(draw);
		//マネージャーにステージ登録
		mManager->Spawn(stage);
	}
	//プレイヤーをマネージャーに登録する
	{
		//オブジェクト(プレイヤー)初期化
		Player* player = new Player();
		//マネージャーにプレイヤー登録
		mManager->Spawn(player);
	}
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
	mManager->Render();

	return true;
}


