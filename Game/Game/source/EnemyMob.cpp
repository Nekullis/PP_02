#include "EnemyMob.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
#include "AIComponent.h"

EnemyMob::EnemyMob(ModeBase* game) :Enemy(game)
{
	mManager = ObjectManager::GetInstance();
	//体力設定
	_hp = 50;
	//待機状態に
	mAnimation = ANIMATION::WAIT;
	Initialize();
	mAttachNum = 6;
	RegisterAnimation();
	//マネージャーにプレイヤー登録
	mManager->Spawn(this);
}

EnemyMob::~EnemyMob()
{
	MV1DetachAnim(mAnimHandle, mAnimAttachIndex);
}

void EnemyMob::RegisterAnimation()
{
	Enemy::RegisterAnimation();
}

void EnemyMob::Initialize()
{
	//描画用コンポーネント初期化
	DrawComponent* draw = new DrawComponent(this);
	//パスを入れておく
	const char* pass = "res/Model/Character/Enemy/enemy.mv1";
	//セッターでパスを登録
	draw->LoadPass(pass);
	//アニメーション用にモデルハンドル取得
	mAnimHandle = draw->GetHandle();
	//プレイヤーに描画用コンポーネント登録
	mManager->AddDraw(draw);

}

void EnemyMob::Process()
{
	Enemy::Process();
	//アニメーションが1フレーム前と違うのなら
	if(mAnimation != oldAnimation)
	{
		int old_attach_index = mAnimAttachIndex;
		//アニメーションのデタッチ
		MV1DetachAnim(mAnimHandle, mAnimAttachIndex);
		//アニメーションによってアタッチする番号を変更する
		switch(mAnimation)
		{
			//待機
			case ANIMATION::WAIT:
				mAnimAttachIndex = MV1AttachAnim(mAnimHandle, 6, -1, false);
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

void EnemyMob::Render()
{
	Enemy::Render();
}
