#include "MoveComponent.h"
#include "ObjectBase.h"
#include <Math.h>
#include "MyMath.h"
MoveComponent::MoveComponent(ObjectBase* owner, int updateowder) :Component(owner, updateowder)
{

}

MoveComponent::~MoveComponent()
{

}

void MoveComponent::Update(float deltatime)
{
	Component::Update(deltatime);
	if (!MyMath::NearZero(mAngularSpeed))
	{
		//ƒeƒXƒg
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltatime;
		mOwner->SetRotation(rot);
	}
	
}
