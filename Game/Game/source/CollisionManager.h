#pragma once
#include "CollisionComponent.h"
//衝突判定を行う際のマネージャー
class CollisionManager
{
public:
	static CollisionManager* colMaInstance;
	CollisionManager();
	~CollisionManager();
	void Update();
	//追加
	void AddCollision(CollisionComponent* col);
	//削除
	void Delete();
	//ゲッター
	static CollisionManager* GetInstance() { return colMaInstance; }
protected:
	std::list<CollisionComponent*> mCollisionList;
};

