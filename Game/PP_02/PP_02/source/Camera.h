#pragma once
#include <utility>
#include "ObjectBase.h"
//ゲーム内のカメラ処理全般のクラス
class Camera : public ObjectBase
{
	using base = ObjectBase;
public:
	Camera();
	virtual ~Camera();
	void Process()override;
	//ゲッター
	Vector3D GetTerget() { return _vTarget; }
protected:
	//カメラ注視点
	Vector3D _vTarget;
};

