#pragma once
#include "AppFrame.h"
class CollisionComponent : public Component
{
public:
	enum class COLLISIONTYPE
	{
		NONE,
		CIRCLE,
		AABB,
		CAPSULE
	};
	CollisionComponent(class ObjectBase* owner, int updateowder = 150);
	virtual ~CollisionComponent();
	virtual void Update()override;
	//ゲッター
	Vector3D GetPos() { return mPos; }
	float GetRadius() { return mRadius; }
	COLLISIONTYPE GetType() { return mType; }
	//セッター
	void SetPos(Vector3D pos) { mPos = pos; }
	void SetRadius(float radius) { mRadius = radius; }
protected:
	Vector3D mPos;
	class CollisionManager* mManager;
	COLLISIONTYPE mType;
	float mRadius;
};

