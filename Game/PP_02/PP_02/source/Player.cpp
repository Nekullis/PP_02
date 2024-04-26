#include "Player.h"

Player::Player():chara()
{
	_status = STATUS::WAIT;
	//‰æ‘œ‚Ìƒ[ƒh
	mCg = LoadGraph(_T("res/key1.png"));
	

}

Player::~Player()
{
}

void Player::Initialize()
{
}

void Player::Process()
{
	_status = STATUS::WALK;

}

void Player::Render()
{
	DrawGraph(_vPos._x, _vPos._y, mCg, TRUE);
}
