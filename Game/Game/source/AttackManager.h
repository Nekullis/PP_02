#pragma once
#include "AttackState.h"
class AttackManager
{
public:
	AttackManager();
	virtual ~AttackManager();
	void AddAttack(int num ,AttackState* state);
	void AttackMotionChange(int num);
	void Update();
protected:
	//コンテナ
	std::map<int,AttackState*> mAttackList;
	//攻撃情報
	AttackState* mState;
	//カウント
	int mAttackCnt;
	//攻撃番号
	int mNowNum;
	//モーション変更フラグ
	bool mChangeFrag;
};

