#include "Stage.h"
#include "DxLib.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
Stage::Stage():ObjectBase()
{
	mManager = ObjectManager::GetInstance();
	//�X�e�[�W�`��p�R���|�[�l���g������
	DrawComponent* draw = new DrawComponent(this);
	//�p�X�����Ă���
	const char* pass = "res/Model/Stage/TestModel.mv1";
	//�Z�b�^�[�Ńp�X��o�^
	draw->SetPass(pass);
	//�X�e�[�W�ɃR���|�[�l���g�o�^
	this->AddComponent(draw);
	//�}�l�[�W���[�ɃX�e�[�W�o�^
	mManager->Spawn(this);
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	ObjectBase::Initialize();
}

void Stage::Process()
{
	ObjectBase::Process();
}

void Stage::Render()
{
	ObjectBase::Render();
}
