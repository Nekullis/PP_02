#include "CameraComponent.h"

CameraComponent::CameraComponent(ObjectBase* owner, int updateowder) : Component(owner, updateowder)
{
	//注視点初期化
	mTarget = { 0 };
	//位置初期化
	mPos = { 0 };
	//最短描画距離初期化
	mNear = 20;
	//最長描画距離初期化
	mFar = 10000;
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::Update()
{
	Component::Update();
	//位置設定
	Vector3D pos = Vector3D(mOwner->GetPos()._x, mOwner->GetPos()._y + 600, mOwner->GetPos()._z - 100);
	//注視点設定
	Vector3D target = Vector3D(mOwner->GetPos()._x, mOwner->GetPos()._y, mOwner->GetPos()._z + 200);
	SetCameraNearFar(mNear, mFar);
	SetCameraPositionAndTarget_UpVecY(pos.dxl(), target.dxl());
}


