#include "ModeGame.h"
#include "Player.h"
#include "Component.h"
#include "MoveComponent.h"
#include "DrawComponent.h"
#include "Stage.h"
#include "Camera.h"
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
	//�I�u�W�F�N�g(�X�e�[�W)������
	Stage* stage = new Stage();
	//�I�u�W�F�N�g(�v���C���[)������
	Player* player = new Player();
	//�I�u�W�F�N�g(�J����)������
	Camera* camera = new Camera();
	//�X�e�[�W���}�l�[�W���[�ɓo�^����
	{
		//�X�e�[�W�`��p�R���|�[�l���g������
		DrawComponent* draw = new DrawComponent(stage);
		//�p�X�����Ă���
		std::string pass = "PP_02/resModel/Stage/TestModel.mv1";
		//�Z�b�^�[�Ńp�X��o�^
		draw->SetPass(pass);
		//�X�e�[�W�ɃR���|�[�l���g�o�^
		stage->AddComponent(draw);
		//�}�l�[�W���[�ɃX�e�[�W�o�^
		mManager->Spawn(stage);
	}
	//�v���C���[���}�l�[�W���[�ɓo�^����
	{
		//�v���C���[�`��p�R���|�[�l���g�ǉ�
		DrawComponent* draw = new DrawComponent(player);
		//�p�X�����Ă���
		std::string pass = "PP_02/res/Model/Character/Player/player.mv1";
		//�Z�b�^�[�Ńp�X��o�^
		draw->SetPass(pass);
		//�v���C���[�ɃR���|�[�l���g�o�^
		player->AddComponent(draw);
		//�}�l�[�W���[�Ƀv���C���[�o�^
		mManager->Spawn(player);
	}
	//�J�������}�l�[�W���[�ɓo�^����
	{
		Vector3D pos = Vector3D(player->GetPos()._x, player->GetPos()._y + 100, player->GetPos()._z - 100);
		Vector3D target = Vector3D(player->GetPos()._x, player->GetPos()._y, player->GetPos()._z + 300);
		camera->SetCamera(pos, target);
		//�J�����o�^
		mManager->Spawn(camera);
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


