#include "AttackManager.h"
#include "Player.h"
AttackManager::AttackManager()
{
	mState = new AttackState();
	mAttackCnt = 0;
	mNowNum = 0;
	mChangeFrag = false;
}

AttackManager::~AttackManager()
{
}

void AttackManager::AddAttack(int num ,AttackState* state)
{
	//コンテナに格納する
	mAttackList.emplace(num,state);
}

void AttackManager::AttackMotionChange(int num)
{
	//イテレータで対応キーを見つける
	auto itr = mAttackList.find(num);
	if (itr != mAttackList.end())
	{
		//対応キーが見つかったら対応要素を代入する
		mState = itr->second;
		if (num != 0) { Player::GetInstance()->SetAnimation(mState->GetAttack().mAnimation); }
		//カウントリセット
		mAttackCnt = 0;
	}
}

void AttackManager::Update()
{
	GameXPad* pad = GameXPad::GetInstance();
	//ボタン入力フラグ
	bool push_flag = false;
	//カウントを増やす
	if (mNowNum != 0) { mAttackCnt++; }
	//フレームカウントが入力猶予フレーム内ならば
	if (mAttackCnt >= mState->GetAttack().mPushStartFrame && mAttackCnt <= mState->GetAttack().mPushEndFrame)
	{
		//ボタン入力フラグをtureに
		push_flag = true;
	}
	//攻撃ボタンが押された時
	if (pad->GetXTrg(XINPUT_BUTTON_B))
	{
		//ボタン入力フラグがtrueなら
		if (push_flag)
		{
			//モーション変更フラグをtrueに
			mChangeFrag = true;
		}
	}
	//モーション変更フラグがtrueの時
	if (mChangeFrag)
	{	
		//モーションが切り替わるフレームカウントに到達した
		if (mAttackCnt >= mState->GetAttack().mMotionChangeFrame)
		{
			//かつその攻撃が派生可能の時
			if (mState->GetAttack().mIsDerivation)
			{
				//攻撃番号を加算
				mNowNum++;
				AttackMotionChange(mNowNum);
			}
		}
	}
	//攻撃時
	if (mNowNum != 0)
	{
	}
	//何も入力せずにトータルフレームに達した
	if (mAttackCnt == mState->GetAttack().mMotionTotalFrame)
	{
		//攻撃番号を0に
		mNowNum = 0;
		//攻撃モーション変更
		AttackMotionChange(mNowNum);
		//カウントリセット
		mAttackCnt = 0;
	}
}
