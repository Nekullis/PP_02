#include "Stage.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
Stage* Stage::stageInstance = nullptr;
Stage::Stage(ModeBase* game):ObjectBase(game)
{
	stageInstance = this;
	mPos = Vector3D(0, -10, 0);
	mRotation = Vector3D(0, 0, 0);
	mManager = ObjectManager::GetInstance();
	//�X�e�[�W�`��p�R���|�[�l���g������
	DrawComponent* draw = new DrawComponent(this);
	//�p�X�����Ă���
	const char* pass = "res/Model/Stage/StageModel.mv1";
	//�Z�b�^�[�Ńp�X��o�^
	draw->LoadPass(pass);
	mManager->AddDraw(draw);
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
