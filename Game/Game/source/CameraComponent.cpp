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
	mFar = 50000;
	//ゲームパッドの取得
	mPad = GameXPad::GetInstance();
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::Update()
{
	Component::Update();
	//位置設定
	Vector3D pos = Vector3D(mOwner->GetPos()._x, mOwner->GetPos()._y + 300, mOwner->GetPos()._z - 700);
	//注視点設定
	Vector3D target = Vector3D(mOwner->GetPos()._x, mOwner->GetPos()._y + 200, mOwner->GetPos()._z );

	SetCameraNearFar(mNear, mFar);
	SetCameraPositionAndTarget_UpVecY(pos.dxl(), target.dxl());
}


