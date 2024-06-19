#include "CapsuleColComponent.h"
#include "CollisionManager.h"
CapsuleColComponent* CapsuleColComponent::capInstance = nullptr;
CapsuleColComponent::CapsuleColComponent(ObjectBase* owner, int updateowder) :CollisionComponent(owner, updateowder)
{
	capInstance = this;
	//ƒ^ƒCƒv‰Šú‰»
	mType = COLLISIONTYPE::CAPSULE;
	//ü•ª‚Ì’·‚³‰Šú‰»
	mLineSeg = 0.0;
}

CapsuleColComponent::~CapsuleColComponent()
{
}

void CapsuleColComponent::Update()
{
	CollisionComponent::Update();
}
