#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::Spawn(ObjectBase* obj)
{
	//�R���e�i�փI�u�W�F�N�g������
	_objectList.push_back(obj);
}

void ObjectManager::Destroy(ObjectBase* obj)
{
	//�R���e�i���̃I�u�W�F�N�g�̍폜
	_objectList.remove(obj);
	delete obj;
}

void ObjectManager::Process()
{
	//�ꎞ�I�ȃR���e�i�̍쐬
	std::list<ObjectBase*> temp_remove;
	for (auto&& object : _objectList)
	{
		//�I�u�W�F�N�g�̃v���Z�X
		object->Process();
		//�����t���O��true�ɂȂ����Ȃ炻�̃I�u�W�F�N�g���ꎞ�I�ȃR���e�i�ɓ����
		if (object->GetDeleteFlag()) { temp_remove.push_back(object);}
	}
	//�ꎞ�I�ȃR���e�i�̒��g���폜����
	for (auto&& object : temp_remove)
	{
		Destroy(object);
	}
}

void ObjectManager::Render()
{
	//�o�^����Ă���I�u�W�F�N�g�̕`��
	for (auto&& object : _objectList)
	{
		object->Render();
	}
}
