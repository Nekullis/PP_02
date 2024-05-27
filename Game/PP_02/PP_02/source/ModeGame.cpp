#include "ModeGame.h"
#include "Player.h"
#include "Component.h"
#include "MoveComponent.h"
#include "DrawComponent.h"
#include "Stage.h"
bool ModeGame::Initialize()
{
	//�I�u�W�F�N�g�}�l�[�W���[������
	mManager = new ObjectManager();
	if (!ModeBase::Initialize()) { return false; }
	//�o�^
	Register();
	return true;
}

bool ModeGame::Terminate()
{
	ModeBase::Terminate();
	return true;
}

void ModeGame::Register()
{
	//�X�e�[�W���}�l�[�W���[�ɓo�^����
	{
		//�I�u�W�F�N�g(�X�e�[�W)������
		Stage* stage = new Stage();
		//�X�e�[�W�`��p�R���|�[�l���g������
		DrawComponent* draw = new DrawComponent(stage);
		//�p�X�����Ă���
		std::string pass = "res/Model/Stage/TestModel.mv1";
		//�Z�b�^�[�Ńp�X��o�^
		draw->SetPass(pass);
		//�X�e�[�W�ɃR���|�[�l���g�o�^
		stage->AddComponent(draw);
		//�}�l�[�W���[�ɃX�e�[�W�o�^
		mManager->Spawn(stage);
	}
	//�v���C���[���}�l�[�W���[�ɓo�^����
	{
		//�I�u�W�F�N�g(�v���C���[)������
		Player* player = new Player();
		//�}�l�[�W���[�Ƀv���C���[�o�^
		mManager->Spawn(player);
	}
}

bool ModeGame::Process()
{
	ModeBase::Process();
	mManager->Process();
	return true;
}

bool ModeGame::Render()
{
	ModeBase::Render();
	mManager->Render();

	return true;
}


