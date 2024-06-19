#pragma once
#include "CollisionComponent.h"
//衝突判定を行う際のマネージャー
class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
	void Update();
	//追加
	void AddCollision(CollisionComponent* col);
	//削除
	void Delete();
protected:
	std::list<CollisionComponent*> mCollisionList;
};

