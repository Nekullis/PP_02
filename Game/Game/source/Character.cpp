#include "Character.h"

Character::Character(ModeBase* game):base(game)
{
	_hp = 0;
	mAttachNum = 0;
	Initialize();
}

Character::~Character()
{
}

void Character::RegisterAnimation()
{
	//������Ԃ̃A�j���[�V�����Z�b�g
	mAnimAttachIndex = MV1AttachAnim(mAnimHandle, mAttachNum, -1, false);
	//�Đ����ԏ�����
	mAnimPlayTime = 0;
	//���Đ����Ԏ擾
	mAnimTotalTime = MV1GetAttachAnimTotalTime(mAnimHandle, mAnimAttachIndex);
}

void Character::Initialize()
{
	
}

void Character::Process()
{
	base::Process();
}

void Character::Render()
{
	base::Render();
}
