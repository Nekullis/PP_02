#include "ModeGame.h"
#include "Player.h"
#include "Component.h"
#include "MoveComponent.h"
#include "DrawComponent.h"
#include "Stage.h"
#include "Camera.h"
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
	//オブジェクト(ステージ)初期化
	Stage* stage = new Stage();
	//オブジェクト(プレイヤー)初期化
	Player* player = new Player();
	//オブジェクト(カメラ)初期化
	Camera* camera = new Camera();
	//ステージをマネージャーに登録する
	{
		//ステージ描画用コンポーネント初期化
		DrawComponent* draw = new DrawComponent(stage);
		//パスを入れておく
		std::string pass = "PP_02/resModel/Stage/TestModel.mv1";
		//セッターでパスを登録
		draw->SetPass(pass);
		//ステージにコンポーネント登録
		stage->AddComponent(draw);
		//マネージャーにステージ登録
		mManager->Spawn(stage);
	}
	//プレイヤーをマネージャーに登録する
	{
		//プレイヤー描画用コンポーネント追加
		DrawComponent* draw = new DrawComponent(player);
		//パスを入れておく
		std::string pass = "PP_02/res/Model/Character/Player/player.mv1";
		//セッターでパスを登録
		draw->SetPass(pass);
		//プレイヤーにコンポーネント登録
		player->AddComponent(draw);
		//マネージャーにプレイヤー登録
		mManager->Spawn(player);
	}
	//カメラをマネージャーに登録する
	{
		Vector3D pos = Vector3D(player->GetPos()._x, player->GetPos()._y + 100, player->GetPos()._z - 100);
		Vector3D target = Vector3D(player->GetPos()._x, player->GetPos()._y, player->GetPos()._z + 300);
		camera->SetCamera(pos, target);
		//カメラ登録
		mManager->Spawn(camera);
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


