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
	mPos = Vector3D(0, 100, 0);
	//向き初期化
	mRotation = Vector3D(0, 0, 0);
	Initialize();
	RegisterAnimation();
	//マネージャーにプレイヤー登録
	mManager->Spawn(this);
}

Player::~Player()
{
	
}

void Player::RegisterAnimation()
{
	//初期状態のアニメーションセット
	mAnimAttachIndex = MV1AttachAnim(mAnimHandle, 0, -1, false);
	//再生時間初期化
	mAnimPlayTime = 0;
	//総再生時間取得
	mAnimTotalTime = MV1GetAttachAnimTotalTime(mAnimHandle, mAnimAttachIndex);
}

void Player::Initialize()
{
	chara::Initialize();
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
	//アニメーション用にモデルハンドル取得
	mAnimHandle = draw->GetHandle();
	//プレイヤーにコンポーネント登録
	mManager->AddDraw(draw);
	//プレイヤーにカメラコンポーネント追加
	CameraComponent* camera = new CameraComponent(this);
}

void Player::Process()
{
	chara::Process();
	mAnimPlayTime += 1.0f;
	if(mAnimPlayTime >= mAnimTotalTime) { mAnimPlayTime = 0.0f; }
	MV1SetAttachAnimTime(mAnimHandle, mAnimAttachIndex, mAnimPlayTime);
}

void Player::Render()
{
	chara::Render();
	
}
