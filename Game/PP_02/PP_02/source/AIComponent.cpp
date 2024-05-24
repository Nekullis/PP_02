#include "AIComponent.h"

AIComponent::AIComponent(ObjectBase* owner, int updateowder) :Component(owner, updateowder)
{
}

AIComponent::~AIComponent()
{
}

void AIComponent::Update(float deltatime)
{
	Component::Update(deltatime);
}
