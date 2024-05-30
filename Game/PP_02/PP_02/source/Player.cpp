#include "Player.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
#include "Camera.h"
Player::Player():chara()
{
	mManager = ObjectManager::GetInstance();
	_status = STATUS::WAIT;
	mPos = Vector3D(0, 0, -500);
	//�v���C���[�`��p�R���|�[�l���g�ǉ�
	DrawComponent* draw = new DrawComponent(this);
	//�p�X�����Ă���
	const char* pass = "res/Model/Character/Player/player.mv1";
	//�Z�b�^�[�Ńp�X��o�^
	draw->SetPass(pass);
	//�v���C���[�ɃR���|�[�l���g�o�^
	this->AddComponent(draw);
	//�}�l�[�W���[�Ƀv���C���[�o�^
	mManager->Spawn(this);
	//�J����������
	Camera* camera = new Camera();
	//�ʒu�ݒ�
	Vector3D pos = Vector3D(mPos._x, mPos._y + 100, mPos._z - 100);
	//�����_�ݒ�
	Vector3D target = Vector3D(mPos._x, mPos._y, mPos._z + 300);
	//�J�����ݒ�
	camera->SetCamera(pos, target);
	//�J�����o�^
	mManager->Spawn(camera);
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
