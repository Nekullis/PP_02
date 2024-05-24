#include "AIState.h"
#include "AIComponent.h"

AIState::AIState(AIComponent* owner) : mOwner(owner)
{

}

AIState::~AIState()
{

}

void AIState::Update()
{

}

void AIState::OnEnter()
{

}

void AIState::OnExit()
{

}

const char* AIState::GetName()
{
	return 0;
}
