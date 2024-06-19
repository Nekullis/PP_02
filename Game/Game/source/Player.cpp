#include "Player.h"
#include "AppFrame.h"
#include "ObjectManager.h"
#include "DrawComponent.h"
#include "CameraComponent.h"
#include "InputComponent.h"
#include "CapsuleColComponent.h"

Player* Player::plInstance = nullptr;
Player::Player(ModeBase* game):chara(game)
{
	plInstance = this;
	mManager = ObjectManager::GetInstance();
	_hp = 100;
	//待機状態に
	mAnimation= ANIMATION::WAIT;
	//位置初期化
	mPos = Vector3D(0, 100, 0);
	//向き初期化
	mRotation = Vector3D(0, 0, 0);
	Initialize();
	mAttachNum = 0;
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
	//衝突判定用コンポーネント追加
	CapsuleColComponent* collision = new CapsuleColComponent(this);
	//位置設定
	collision->SetPos(mPos);
	//半径設定
	float rad = 30.0;
	collision->SetRadius(rad);
	//線分の長さ設定
	float line_seg = 170.0;
	collision->SetSeg(line_seg);
}

void Player::RegisterAnimation()
{
	Character::RegisterAnimation();
}

void Player::Process()
{
	chara::Process();
	if (GameXPad::GetInstance()->IsInputStickLeft())
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
			//歩行
		case ANIMATION::FIRSTATTACK:
			mAnimAttachIndex = MV1AttachAnim(mAnimHandle, 2, -1, false);
			break;
			//歩行
		case ANIMATION::SECONDATTACK:
			mAnimAttachIndex = MV1AttachAnim(mAnimHandle, 3, -1, false);
			break;
			//歩行
		case ANIMATION::THIRDATTACK:
			mAnimAttachIndex = MV1AttachAnim(mAnimHandle, 4, -1, false);
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
