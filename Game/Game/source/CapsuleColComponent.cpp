#include "CapsuleColComponent.h"
#include "CollisionManager.h"
CapsuleColComponent* CapsuleColComponent::capInstance = nullptr;
CapsuleColComponent::CapsuleColComponent(ObjectBase* owner, int updateowder) :CollisionComponent(owner, updateowder)
{
	capInstance = this;
	//タイプ初期化
	mType = COLLISIONTYPE::CAPSULE;
	//線分の長さ初期化
	mLineSeg = 0.0;
}

CapsuleColComponent::~CapsuleColComponent()
{
}

void CapsuleColComponent::Update()
{
	CollisionComponent::Update();
}
