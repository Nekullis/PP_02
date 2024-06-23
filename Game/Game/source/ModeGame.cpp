#include "ModeGame.h"
#include "Player.h"
#include "Stage.h"
#include "EnemyMob.h"
#include "TargetMaker.h"
#include "ObjectManager.h"
#include "GameCollision.h"
#include "CollisionManager.h"
bool ModeGame::Initialize()
{
	if (!ModeBase::Initialize()) { return false; }
	//�I�u�W�F�N�g�}�l�[�W���[������
	mObjManager = new ObjectManager();
	//�R���W�����n���̃N���X������
	mGameCol = new GameCollision();
	mColManager = new CollisionManager();
	Register();
	return true;
}

bool ModeGame::Terminate()
{
	ModeBase::Terminate();
	delete mObjManager;
	delete mGameCol;
	delete mColManager;
	return true;
}

void ModeGame::Register()
{
	//�v���C���[�ǉ�
	Player* player = new Player(this);
	//
	TargetMaker* maker = new TargetMaker(this);
	//�G�ǉ�
	EnemyMob* mob_l = new EnemyMob(this);
	mob_l->SetPos(Vector3D(-500, 100, 1000));
	//�X�e�[�W�ǉ�
	Stage* stage = new Stage(this);
}

bool ModeGame::Process()
{
	//�e�v���Z�X�̍X�V
	ModeBase::Process();
	mColManager->Update();
	mObjManager->Process();
	mGameCol->Update();
	return true;
}

bool ModeGame::Render()
{
	//z�o�b�t�@�[�L����
	SetUseZBuffer3D(true);
	//z�o�b�t�@�[�������ݐݒ�
	SetWriteZBuffer3D(true);
	//���C�g�L����
	SetUseLighting(true);
	//���C�g�^�C�v���f�B���N�V���i���^�C�v�ɐݒ�
	ChangeLightTypeDir(Vector3D(0,-1,1).dxl());
	ModeBase::Render();
	mObjManager->Render();
	return true;
}




