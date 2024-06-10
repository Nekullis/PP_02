#include "Character.h"

Character::Character(ModeBase* game):base(game)
{
	_hp = 0;
	Initialize();
}

Character::~Character()
{
}

void Character::Initialize()
{
	
}

void Character::Process()
{
	base::Process();
}

void Character::Render()
{
	base::Render();
}
