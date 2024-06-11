#include "Player.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
#include "CameraComponent.h"
#include "AppFrame.h"
#include "InputComponent.h"]
Player::Player(ModeBase* game):chara(game)
{
	mManager = ObjectManager::GetInstance();
	//�ҋ@��Ԃ�
	_status = STATUS::WAIT;
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
	//�v���C���[�ɃR���|�[�l���g�o�^
	mManager->AddDraw(draw);
	//�v���C���[�ɃJ�����R���|�[�l���g�ǉ�
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
