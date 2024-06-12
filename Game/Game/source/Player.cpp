#include "Player.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
#include "CameraComponent.h"
#include "AppFrame.h"
#include "InputComponent.h"
Player::Player(ModeBase* game):chara(game)
{
	mManager = ObjectManager::GetInstance();
	_hp = 100;
	//待機状態に
	mAnimation= ANIMATION::WAIT;
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
	MV1DetachAnim(mAnimHandle, mAnimAttachIndex);
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
	//プレイヤーに描画用コンポーネント登録
	mManager->AddDraw(draw);
	//プレイヤーにカメラコンポーネント追加
	CameraComponent* camera = new CameraComponent(this);
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

void Player::Process()
{
	chara::Process();
	if (GameXPad::GetInstance()->IsInputStick())
	{
		mAnimation = ANIMATION::WALK;
	}
	else
	{
		mAnimation = ANIMATION::WAIT;
	}
	//アニメーションが1フレーム前と違うのなら
	if (mAnimation != oldAnimation)
	{
		int old_attach_index = mAnimAttachIndex;
		//アニメーションのデタッチ
		MV1DetachAnim(mAnimHandle, mAnimAttachIndex);
		//アニメーションによってアタッチする番号を変更する
		switch (mAnimation)
		{
		//待機
		case ANIMATION::WAIT:
			mAnimAttachIndex = MV1AttachAnim(mAnimHandle, 0, -1, false);
			break;
		//歩行
		case ANIMATION::WALK:
			mAnimAttachIndex = MV1AttachAnim(mAnimHandle, 7, -1, false);
			break;
		}
		//再生時間リセット
		mAnimPlayTime = 0;
		//総再生時間セット
		mAnimTotalTime = MV1GetAttachAnimTotalTime(mAnimHandle, mAnimAttachIndex);
	}
	//アニメーションカウント加算
	mAnimPlayTime += 1.0f;
	//総再生時間に到達したらリセット
	if(mAnimPlayTime >= mAnimTotalTime) { mAnimPlayTime = 0.0f; }
	//現再生時間をセット
	MV1SetAttachAnimTime(mAnimHandle, mAnimAttachIndex, mAnimPlayTime);
	oldAnimation = mAnimation;
}

void Player::Render()
{
	chara::Render();
	
}
