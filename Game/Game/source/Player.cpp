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
	mPos = Vector3D(0, 500, 0);
	//����������
	mRotation = Vector3D(MyMath::DegToRad(90), 0, 0);
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
	//�v���C���[�ɃR���|�[�l���g�o�^
	mManager->AddDraw(draw);
	//�v���C���[�ɃJ�����R���|�[�l���g�ǉ�
	CameraComponent* camera = new CameraComponent(this);
	//�}�l�[�W���[�Ƀv���C���[�o�^
	mManager->Spawn(this);
}

Player::~Player()
{

}

void Player::Initialize()
{
	chara::Initialize();
}

void Player::Process()
{
	chara::Process();

}

void Player::Render()
{
	chara::Render();
}
