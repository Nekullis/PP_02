#pragma once
#include "DxLib.h"
#include "ObjectBase.h"
#include <list>
//オブジェクトの登録、消去などに関わるクラス
class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void Process();
	void Render();
	//登録
	void Spawn(ObjectBase* obj);
	//消去
	void Destroy(ObjectBase* obj);
	//ゲッター
	std::list<ObjectBase*> GetObjectList() { return _objectList; }
protected:
	std::list<ObjectBase*> _objectList;
};

