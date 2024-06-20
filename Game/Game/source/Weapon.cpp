#include "Weapon.h"
#include "CapsuleColComponent.h"
#include "DrawComponent.h"
#include "ObjectManager.h"

Weapon::Weapon(ModeBase* game) :ObjectBase(game)
{
	mManager = ObjectManager::GetInstance();
	Initialize();
	
	mManager->Spawn(this);
}

Weapon::~Weapon()
{
}

void Weapon::Initialize()
{
	ObjectBase::Initialize();
	mDraw = new DrawComponent(this);
	//�p�X�����Ă���
	const char* pass = "res/Model/JointWeapon/Axe.mv1";
	mDraw->LoadPass(pass);
	//�A�j���[�V�����p�Ƀ��f���n���h���擾
	mAnimHandle = mDraw->GetHandle();
	//�v���C���[�ɕ`��p�R���|�[�l���g�o�^
	mManager->AddDraw(mDraw);
	mCol = new CapsuleColComponent(this);
	//���a�ݒ�
	float rad = 30.0;
	mCol->SetRadius(rad);
	//�����̒����ݒ�
	float line_seg = 170.0;
	mCol->SetSeg(line_seg);

}

void Weapon::Process()
{
}

void Weapon::Render()
{
}
