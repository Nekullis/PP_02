#pragma once
#include "CollisionComponent.h"
//�Փ˔�����s���ۂ̃}�l�[�W���[
class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
	void Update();
	//�ǉ�
	void AddCollision(CollisionComponent* col);
	//�폜
	void Delete();
protected:
	std::list<CollisionComponent*> mCollisionList;
};

