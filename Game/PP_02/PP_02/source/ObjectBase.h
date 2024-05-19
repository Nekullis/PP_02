#pragma once
#include "DxLib.h"
#include "Vector3D.h"
#include <vector>
#include <string>
//オブジェクトの親クラス
//オブジェクトはこのクラス、またはこの派生クラスから生成
class ObjectBase
{
public:
	//状態
	enum class State
	{
		ACTIVE,
		PAUSE,
		DEAD
	};
	ObjectBase();
	virtual ~ObjectBase();
	virtual void Initialize();
	virtual void Process();
	virtual void Render();
	virtual void Debug();
	//コンポーネント追加
	void AddComponent(class Component* component);
	//コンポーネント削除
	void RemoveComponent(class Component* component);
	//ゲッター
	Vector3D GetPos() { return _vPos; }
	State GetState() const { return mState; }
	//セッター
	void SetPos(const Vector3D& pos) { _vPos = pos; }
protected:
	//位置
	Vector3D _vPos;
	//角度
	Vector3D _vDir;
	//状態
	State mState;
	//コンポーネント
	std::vector<class Component*> mComponents;
	class ModeGame* mGame;

};

