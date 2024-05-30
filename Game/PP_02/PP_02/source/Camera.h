#pragma once
#include <utility>
#include "AppFrame.h"
//ゲーム内のカメラ処理全般のクラス
class Camera : public ObjectBase
{
	using base = ObjectBase;
public:
	Camera();
	virtual ~Camera();
	void Process()override;
	void SetCamera(Vector3D pos, Vector3D target);
	//ゲッター
	Vector3D GetTerget() { return mTarget; }
	//セッター
	void SetTerget(Vector3D vec) { mTarget = vec; }
protected:
	//カメラ注視点
	Vector3D mTarget;
	//最短描画距離
	float mNear;
	//最長描画距離
	float mFar;
};

