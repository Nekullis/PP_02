#include "EnemyMob.h"
#include "DrawComponent.h"
#include "ObjectManager.h"
#include "AIComponent.h"

EnemyMob::EnemyMob(ModeBase* game) :Enemy(game)
{
	mManager = ObjectManager::GetInstance();
	//体力設定
	_hp = 50;
	Initialize();
	//マネージャーにプレイヤー登録
	mManager->Spawn(this);
}

EnemyMob::~EnemyMob()
{

}

void EnemyMob::Initialize()
{
	//描画用コンポーネント初期化
	DrawComponent* draw = new DrawComponent(this);
	//パスを入れておく
	const char* pass = "res/Model/Character/Enemy/enemy.mv1";
	//セッターでパスを登録
	draw->LoadPass(pass);
	//プレイヤーに描画用コンポーネント登録
	mManager->AddDraw(draw);

}

void EnemyMob::Process()
{
	Enemy::Process();
}

void EnemyMob::Render()
{
	Enemy::Render();
}
