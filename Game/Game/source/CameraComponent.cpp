#include "CameraComponent.h"

CameraComponent* CameraComponent::cameraInstance = nullptr;
CameraComponent::CameraComponent(ObjectBase* owner, int updateowder) : Component(owner, updateowder)
{
	cameraInstance = this;
	//注視点初期化
	mTarget = { 0 };
	//位置初期化
	mPos = { 0 };
	mDir = Vector3D(0, mOwner->GetRotation()._y, 0);
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
	Vector3D pos;
	//パッド入力で角度を代入
	if (mPad->GetXRx() < 0) { mDir._y -= 0.05; }
	if (mPad->GetXRx() > 0) { mDir._y += 0.05; }
	/*if (mPad->GetXRy() < 0) { mDir._x -= 0.05; }
	if (mPad->GetXRy() > 0) { mDir._x += 0.05; }*/
	//カメラ位置をプレーヤー位置に球型座標系から変化した座標系を足した座標にする
	pos = mOwner->GetPos() + MyMath::ConvertToCartesian(mDir, 700);
	//後頭部より少し高めの位置にする
	pos._y += 300;
	mPos = pos;
	//注視点設定
	Vector3D target = Vector3D(mOwner->GetPos());
	//カメラ描写の最短距離、最長距離を設定する
	SetCameraNearFar(mNear, mFar);
	//カメラの位置と注視点を反映する
	SetCameraPositionAndTarget_UpVecY(pos.dxl(), target.dxl());
}




