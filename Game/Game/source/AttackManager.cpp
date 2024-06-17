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
	//�R���e�i�Ɋi�[����
	mAttackList.emplace(num,state);
}

void AttackManager::AttackMotionChange(int num)
{
	//�C�e���[�^�őΉ��L�[��������
	auto itr = mAttackList.find(num);
	if (itr != mAttackList.end())
	{
		//�Ή��L�[������������Ή��v�f��������
		mState = itr->second;
		if (num != 0) { Player::GetInstance()->SetAnimation(mState->GetAttack().mAnimation); }
		//�J�E���g���Z�b�g
		mAttackCnt = 0;
	}
}

void AttackManager::Update()
{
	GameXPad* pad = GameXPad::GetInstance();
	//�{�^�����̓t���O
	bool push_flag = false;
	//�J�E���g�𑝂₷
	if (mNowNum != 0) { mAttackCnt++; }
	//�t���[���J�E���g�����͗P�\�t���[�����Ȃ��
	if (mAttackCnt >= mState->GetAttack().mPushStartFrame && mAttackCnt <= mState->GetAttack().mPushEndFrame)
	{
		//�{�^�����̓t���O��ture��
		push_flag = true;
	}
	//�U���{�^���������ꂽ��
	if (pad->GetXTrg(XINPUT_BUTTON_B))
	{
		//�{�^�����̓t���O��true�Ȃ�
		if (push_flag)
		{
			//���[�V�����ύX�t���O��true��
			mChangeFrag = true;
		}
	}
	//���[�V�����ύX�t���O��true�̎�
	if (mChangeFrag)
	{	
		//���[�V�������؂�ւ��t���[���J�E���g�ɓ��B����
		if (mAttackCnt >= mState->GetAttack().mMotionChangeFrame)
		{
			//�����̍U�����h���\�̎�
			if (mState->GetAttack().mIsDerivation)
			{
				//�U���ԍ������Z
				mNowNum++;
				AttackMotionChange(mNowNum);
			}
		}
	}
	//�U����
	if (mNowNum != 0)
	{
	}
	//�������͂����Ƀg�[�^���t���[���ɒB����
	if (mAttackCnt == mState->GetAttack().mMotionTotalFrame)
	{
		//�U���ԍ���0��
		mNowNum = 0;
		//�U�����[�V�����ύX
		AttackMotionChange(mNowNum);
		//�J�E���g���Z�b�g
		mAttackCnt = 0;
	}
}
