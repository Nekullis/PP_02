#include "InputComponent.h"
#include "Player.h"

InputComponent::InputComponent(ObjectBase* owner, int updateowder) :MoveComponent(owner, updateowder)
{
	//�R���g���[���[������
	mPad = new GameXPad();
}

InputComponent::~InputComponent()
{
}

void InputComponent::Update()
{
	mPad->Input();
	//�A�i���O�p�b�h�̒l��atan2�֐��Ŋp�x�𓾂�
	float dir = atan2(mPad->GetXLy(), mPad->GetXLx());
	//�A�i���O�p�b�h�������Ă���̂Ȃ�
	if(mPad->IsInputStick())
	{
		//�Q�ƃI�u�W�F�N�g�̈ʒu���擾
		Vector3D pos = mOwner->GetPos();;
		//�Z�b�^�[�œ������x����
		float speed = mForwardSpeed;
		pos._x += speed * cos(dir);
		pos._z += speed * sin(dir);
		mOwner->SetPos(pos);
		Vector3D rot = Vector3D(0, -(dir + 90 * DX_PI / 180), 0);
		mOwner->SetRotation(rot);
	}
	
}
