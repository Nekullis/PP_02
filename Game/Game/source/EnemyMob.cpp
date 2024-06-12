#include "EnemyMob.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
#include "AIComponent.h"

EnemyMob::EnemyMob(ModeBase* game) :Enemy(game)
{
	mManager = ObjectManager::GetInstance();
	//�̗͐ݒ�
	_hp = 50;
	Initialize();
	//�}�l�[�W���[�Ƀv���C���[�o�^
	mManager->Spawn(this);
}

EnemyMob::~EnemyMob()
{

}

void EnemyMob::Initialize()
{
	//�`��p�R���|�[�l���g������
	DrawComponent* draw = new DrawComponent(this);
	//�p�X�����Ă���
	const char* pass = "res/Model/Character/Enemy/enemy.mv1";
	//�Z�b�^�[�Ńp�X��o�^
	draw->LoadPass(pass);
	//�v���C���[�ɕ`��p�R���|�[�l���g�o�^
	mManager->AddDraw(draw);

}

void EnemyMob::Process()
{
	Enemy::Process();
}

void EnemyMob::Render()
{
	Enemy::Render();
}
