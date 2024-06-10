#pragma once
#include <utility>
#include "AppFrame.h"
//ゲーム内のカメラ処理全般のクラス
class CameraComponent : public Component
{
public:
	CameraComponent(ObjectBase* owner,int updateowder = 100);
	virtual ~CameraComponent();
	void Update()override;
	//ゲッター
	Vector3D GetTerget() { return mTarget; }
	//セッター
	void SetTerget(Vector3D vec) { mTarget = vec; }
protected:
	//カメラ位置
	Vector3D mPos;
	//カメラ注視点
	Vector3D mTarget;
	//最短描画距離
	float mNear;
	//最長描画距離
	float mFar;
};

