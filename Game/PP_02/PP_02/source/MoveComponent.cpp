#include "MoveComponent.h"
#include "ObjectBase.h"
#include <Math.h>
MoveComponent::MoveComponent(ObjectBase* owner, int updateowder) :Component(owner, updateowder)
{

}

MoveComponent::~MoveComponent()
{

}

void MoveComponent::Update()
{
	Component::Update();
	
}
