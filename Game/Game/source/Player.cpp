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
	//�ҋ@��Ԃ�
	mAnimation= ANIMATION::WAIT;
	//�ʒu������
	mPos = Vector3D(0, 100, 0);
	//����������
	mRotation = Vector3D(0, 0, 0);
	Initialize();
	RegisterAnimation();
	//�}�l�[�W���[�Ƀv���C���[�o�^
	mManager->Spawn(this);
}

Player::~Player()
{
	MV1DetachAnim(mAnimHandle, mAnimAttachIndex);
}

void Player::Initialize()
{
	chara::Initialize();
	//���͏����̃R���|�[�l���g������
	InputComponent* input = new InputComponent(this);
	//�v���C���[���x������
	input->SetForwardSpeed(20);
	//�v���C���[�`��p�R���|�[�l���g�ǉ�
	DrawComponent* draw = new DrawComponent(this);
	//�p�X�����Ă���
	const char* pass = "res/Model/Character/Player/Player.mv1";
	//�Z�b�^�[�Ńp�X��o�^
	draw->LoadPass(pass);
	//�A�j���[�V�����p�Ƀ��f���n���h���擾
	mAnimHandle = draw->GetHandle();
	//�v���C���[�ɕ`��p�R���|�[�l���g�o�^
	mManager->AddDraw(draw);
	//�v���C���[�ɃJ�����R���|�[�l���g�ǉ�
	CameraComponent* camera = new CameraComponent(this);
}

void Player::RegisterAnimation()
{
	//������Ԃ̃A�j���[�V�����Z�b�g
	mAnimAttachIndex = MV1AttachAnim(mAnimHandle, 0, -1, false);
	//�Đ����ԏ�����
	mAnimPlayTime = 0;
	//���Đ����Ԏ擾
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
	//�A�j���[�V������1�t���[���O�ƈႤ�̂Ȃ�
	if (mAnimation != oldAnimation)
	{
		int old_attach_index = mAnimAttachIndex;
		//�A�j���[�V�����̃f�^�b�`
		MV1DetachAnim(mAnimHandle, mAnimAttachIndex);
		//�A�j���[�V�����ɂ���ăA�^�b�`����ԍ���ύX����
		switch (mAnimation)
		{
		//�ҋ@
		case ANIMATION::WAIT:
			mAnimAttachIndex = MV1AttachAnim(mAnimHandle, 0, -1, false);
			break;
		//���s
		case ANIMATION::WALK:
			mAnimAttachIndex = MV1AttachAnim(mAnimHandle, 7, -1, false);
			break;
		}
		//�Đ����ԃ��Z�b�g
		mAnimPlayTime = 0;
		//���Đ����ԃZ�b�g
		mAnimTotalTime = MV1GetAttachAnimTotalTime(mAnimHandle, mAnimAttachIndex);
	}
	//�A�j���[�V�����J�E���g���Z
	mAnimPlayTime += 1.0f;
	//���Đ����Ԃɓ��B�����烊�Z�b�g
	if(mAnimPlayTime >= mAnimTotalTime) { mAnimPlayTime = 0.0f; }
	//���Đ����Ԃ��Z�b�g
	MV1SetAttachAnimTime(mAnimHandle, mAnimAttachIndex, mAnimPlayTime);
	oldAnimation = mAnimation;
}

void Player::Render()
{
	chara::Render();
	
}
