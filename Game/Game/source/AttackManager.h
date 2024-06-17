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
	//�R���e�i
	std::map<int,AttackState*> mAttackList;
	//�U�����
	AttackState* mState;
	//�J�E���g
	int mAttackCnt;
	//�U���ԍ�
	int mNowNum;
	//���[�V�����ύX�t���O
	bool mChangeFrag;
};

