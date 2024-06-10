#include "CameraComponent.h"

CameraComponent::CameraComponent(ObjectBase* owner, int updateowder) : Component(owner, updateowder)
{
	//’Ž‹“_‰Šú‰»
	mTarget = { 0 };
	//ˆÊ’u‰Šú‰»
	mPos = { 0 };
	//Å’Z•`‰æ‹——£‰Šú‰»
	mNear = 20;
	//Å’·•`‰æ‹——£‰Šú‰»
	mFar = 50000;
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::Update()
{
	Component::Update();
	//ˆÊ’uÝ’è
	Vector3D pos = Vector3D(mOwner->GetPos()._x, mOwner->GetPos()._y + 300, mOwner->GetPos()._z - 700);
	//’Ž‹“_Ý’è
	Vector3D target = Vector3D(mOwner->GetPos()._x, mOwner->GetPos()._y + 200, mOwner->GetPos()._z );
	SetCameraNearFar(mNear, mFar);
	SetCameraPositionAndTarget_UpVecY(pos.dxl(), target.dxl());
}


