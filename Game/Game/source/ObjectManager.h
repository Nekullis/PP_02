#pragma once
#include "AppFrame.h" 
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
	void AddDraw(class DrawComponent* draw);
	//����
	void Destroy(ObjectBase* obj);
	//�Q�b�^�[
	std::list<ObjectBase*> GetObjectList() { return _objectList; }
	//std::list<class DrawComponent*> GetDrawList() { return _drawList; }
	static ObjectManager* GetInstance() { return obInstance; }

protected:
	std::list<ObjectBase*> _objectList;
	std::list<class DrawComponent*> _drawList;
};

