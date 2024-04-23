#pragma once
#include "DxLib.h"
#include "Vector3D.h"
//オブジェクトの親クラス
//オブジェクトはこのクラス、またはこの派生クラスから生成
class ObjectBase
{
public:
	ObjectBase();
	virtual ~ObjectBase();
	virtual void Initialize();
	virtual void Process();
	virtual void Render();
	//ゲッター
	bool GetDeleteFlag() const { return _deleteFlag; }
	Vector3D GetPos() { return _vPos; }
	//セッター
	void SetPos(const Vector3D& pos) { _vPos = pos; }
protected:
	//位置
	Vector3D _vPos;
	//角度
	Vector3D _vDir;
	//消去予定か
	bool _deleteFlag;
};

