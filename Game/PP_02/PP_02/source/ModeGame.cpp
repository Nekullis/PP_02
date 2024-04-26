#include "ModeGame.h"
#include "Player.h"
#include "Component.h"
bool ModeGame::Initialize()
{
	mManager = new ObjectManager();

	if(!ModeBase::Initialize()) { return false; }
	Player* player = new Player();
	Component* component_1 = new Component(player, 10);
	player->AddComponent(component_1);
	Component* component_2 = new Component(player, 9);
	player->AddComponent(component_2);
	Component* component_3 = new Component(player, 11);
	player->AddComponent(component_3);
	mManager->Spawn(player);

	return true;
}

bool ModeGame::Terminate()
{
	ModeBase::Terminate();
	return true;
}

bool ModeGame::Process()
{
	ModeBase::Process();
	mManager->Process();
	return true;
}

bool ModeGame::Render()
{
	ModeBase::Render();
	mManager->Render();

	return true;
}
