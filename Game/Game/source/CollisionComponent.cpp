#include "CollisionComponent.h"
#include "CollisionManager.h"

CollisionComponent::CollisionComponent(ObjectBase* owner, int updateowder) :Component(owner, updateowder)
{
	mManager = new CollisionManager();
	mType = COLLISIONTYPE::NONE;
	mPos = Vector3D(0, 0, 0);
	mRadius = 0;
	mManager->AddCollision(this);

}

CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::Update()
{
	mPos = mOwner->GetPos();
}
