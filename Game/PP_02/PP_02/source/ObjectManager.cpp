#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::Spawn(ObjectBase* obj)
{
	//コンテナへオブジェクトを入れる
	_objectList.push_back(obj);
}

void ObjectManager::Destroy(ObjectBase* obj)
{
	//コンテナ内のオブジェクトの削除
	_objectList.remove(obj);
	delete obj;
}

void ObjectManager::Process()
{
	//一時的なコンテナの作成
	std::list<ObjectBase*> temp_remove;
	for (auto&& object : _objectList)
	{
		//オブジェクトのプロセス
		object->Process();
		//消去フラグがtrueになったならそのオブジェクトを一時的なコンテナに入れる
		if (object->GetDeleteFlag()) { temp_remove.push_back(object);}
	}
	//一時的なコンテナの中身を削除する
	for (auto&& object : temp_remove)
	{
		Destroy(object);
	}
}

void ObjectManager::Render()
{
	//登録されているオブジェクトの描画
	for (auto&& object : _objectList)
	{
		object->Render();
	}
}
