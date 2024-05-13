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
	chara::Initialize();
}

void Player::Process()
{
	chara::Process();
}

void Player::Render()
{
	chara::Render();
	//‰æ‘œ•`‰æ
	DrawGraph(_vPos._x, _vPos._y, mCg, TRUE);
}
