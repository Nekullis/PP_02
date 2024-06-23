#include "Enemy.h"
#include "ObjectManager.h"

Enemy::Enemy(ModeBase* game) : Character(game)
{
	mIsTargetting = true;
	RegisterAnimation();
}

Enemy::~Enemy()
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
