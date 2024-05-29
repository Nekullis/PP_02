#pragma once
#include "ObjectBase.h"
#include <list>
//�I�u�W�F�N�g�̓o�^�A�����ȂǂɊւ��N���X
class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	static ObjectManager* obInstance;
	void Process();
	void Render();
	//�o�^
	void Spawn(ObjectBase* obj);
	//����
	void Destroy(ObjectBase* obj);
	//�Q�b�^�[
	std::list<ObjectBase*> GetObjectList() { return _objectList; }
	static ObjectManager* GetInstance() { return obInstance; }
protected:
	std::list<ObjectBase*> _objectList;
};

