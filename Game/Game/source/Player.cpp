#include "Player.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
#include "CameraComponent.h"
#include "AppFrame.h"
#include "InputComponent.h"]
Player::Player(ModeBase* game):chara(game)
{
	mManager = ObjectManager::GetInstance();
	//待機状態に
	_status = STATUS::WAIT;
	//位置初期化
	mPos = Vector3D(0, 500, 0);
	//向き初期化
	mRotation = Vector3D(MyMath::DegToRad(90), 0, 0);
	//入力処理のコンポーネント初期化
	InputComponent* input = new InputComponent(this);
	//プレイヤー速度初期化
	input->SetForwardSpeed(20);
	//プレイヤー描画用コンポーネント追加
	DrawComponent* draw = new DrawComponent(this);
	//パスを入れておく
	const char* pass = "res/Model/Character/Player/Player.mv1";
	//セッターでパスを登録
	draw->LoadPass(pass);
	//プレイヤーにコンポーネント登録
	mManager->AddDraw(draw);
	//プレイヤーにカメラコンポーネント追加
	CameraComponent* camera = new CameraComponent(this);
	//マネージャーにプレイヤー登録
	mManager->Spawn(this);
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
