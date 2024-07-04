#include "CapsuleColComponent.h"
#include "CollisionManager.h"
CapsuleColComponent* CapsuleColComponent::capInstance = nullptr;
CapsuleColComponent::CapsuleColComponent(ObjectBase* owner, int updateowder) :CollisionComponent(owner, updateowder)
{
	capInstance = this;
	//タイプ初期化
	mType = COLLISIONTYPE::CAPSULE;
}

CapsuleColComponent::~CapsuleColComponent()
{
}

void CapsuleColComponent::Update()
{
	CollisionComponent::Update();
}
