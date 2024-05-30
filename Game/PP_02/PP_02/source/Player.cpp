#include "Player.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
#include "Camera.h"
Player::Player():chara()
{
	mManager = ObjectManager::GetInstance();
	_status = STATUS::WAIT;
	mPos = Vector3D(0, 0, -500);
	//プレイヤー描画用コンポーネント追加
	DrawComponent* draw = new DrawComponent(this);
	//パスを入れておく
	const char* pass = "res/Model/Character/Player/player.mv1";
	//セッターでパスを登録
	draw->SetPass(pass);
	//プレイヤーにコンポーネント登録
	this->AddComponent(draw);
	//マネージャーにプレイヤー登録
	mManager->Spawn(this);
	//カメラ初期化
	Camera* camera = new Camera();
	//位置設定
	Vector3D pos = Vector3D(mPos._x, mPos._y + 100, mPos._z - 100);
	//注視点設定
	Vector3D target = Vector3D(mPos._x, mPos._y, mPos._z + 300);
	//カメラ設定
	camera->SetCamera(pos, target);
	//カメラ登録
	mManager->Spawn(camera);
}

Player::~Player()
{

}

void Player::Initialize()
{
	chara::Initialize();
}

void Player::Process()
{
	chara::Process();
}

void Player::Render()
{
	chara::Render();
}
