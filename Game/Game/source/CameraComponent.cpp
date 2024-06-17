#include "CameraComponent.h"

CameraComponent* CameraComponent::cameraInstance = nullptr;
CameraComponent::CameraComponent(ObjectBase* owner, int updateowder) : Component(owner, updateowder)
{
	cameraInstance = this;
	//�����_������
	mTarget = { 0 };
	//�ʒu������
	mPos = { 0 };
	mDir = Vector3D(0, mOwner->GetRotation()._y, 0);
	//�ŒZ�`�拗��������
	mNear = 20;
	//�Œ��`�拗��������
	mFar = 50000;
	//�Q�[���p�b�h�̎擾
	mPad = GameXPad::GetInstance();
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::Update()
{
	Component::Update();
	//�ʒu�ݒ�
	Vector3D pos;
	//�p�b�h���͂Ŋp�x����
	if (mPad->GetXRx() < 0) { mDir._y -= 0.05; }
	if (mPad->GetXRx() > 0) { mDir._y += 0.05; }
	/*if (mPad->GetXRy() < 0) { mDir._x -= 0.05; }
	if (mPad->GetXRy() > 0) { mDir._x += 0.05; }*/
	//�J�����ʒu���v���[���[�ʒu�ɋ��^���W�n����ω��������W�n�𑫂������W�ɂ���
	pos = mOwner->GetPos() + MyMath::ConvertToCartesian(mDir, 700);
	//�㓪����菭�����߂̈ʒu�ɂ���
	pos._y += 300;
	mPos = pos;
	//�����_�ݒ�
	Vector3D target = Vector3D(mOwner->GetPos());
	//�J�����`�ʂ̍ŒZ�����A�Œ�������ݒ肷��
	SetCameraNearFar(mNear, mFar);
	//�J�����̈ʒu�ƒ����_�𔽉f����
	SetCameraPositionAndTarget_UpVecY(pos.dxl(), target.dxl());
}




