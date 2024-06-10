#include "CameraComponent.h"

CameraComponent::CameraComponent(ObjectBase* owner, int updateowder) : Component(owner, updateowder)
{
	//�����_������
	mTarget = { 0 };
	//�ʒu������
	mPos = { 0 };
	//�ŒZ�`�拗��������
	mNear = 20;
	//�Œ��`�拗��������
	mFar = 50000;
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::Update()
{
	Component::Update();
	//�ʒu�ݒ�
	Vector3D pos = Vector3D(mOwner->GetPos()._x, mOwner->GetPos()._y + 300, mOwner->GetPos()._z - 700);
	//�����_�ݒ�
	Vector3D target = Vector3D(mOwner->GetPos()._x, mOwner->GetPos()._y + 200, mOwner->GetPos()._z );
	SetCameraNearFar(mNear, mFar);
	SetCameraPositionAndTarget_UpVecY(pos.dxl(), target.dxl());
}


