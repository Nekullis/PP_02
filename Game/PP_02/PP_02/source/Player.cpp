#include "Player.h"

Player::Player():chara()
{
	_status = STATUS::WAIT;
}

Player::~Player()
{

}

void Player::Initialize()
{
	chara::Initialize();
}

void Player::Process()
{
	chara::Process();
}

void Player::Render()
{
	chara::Render();
}
