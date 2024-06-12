#include "Enemy.h"
#include "ObjectManager.h"

Enemy::Enemy(ModeBase* game) : Character(game)
{
	RegisterAnimation();
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
}

void Enemy::Process()
{
	
}

void Enemy::Render()
{
}

void Enemy::RegisterAnimation()
{
	Character::RegisterAnimation();
}
