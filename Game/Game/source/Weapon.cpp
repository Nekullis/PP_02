#include "Weapon.h"
#include "CapsuleColComponent.h"
#include "DrawComponent.h"
#include "ObjectManager.h"

Weapon::Weapon(ModeBase* game) :ObjectBase(game)
{
	mManager = ObjectManager::GetInstance();
	Initialize();
	
	mManager->Spawn(this);
}

Weapon::~Weapon()
{
}

void Weapon::Initialize()
{
	ObjectBase::Initialize();
	mDraw = new DrawComponent(this);
	//パスを入れておく
	const char* pass = "res/Model/JointWeapon/Axe.mv1";
	mDraw->LoadPass(pass);
	//アニメーション用にモデルハンドル取得
	mAnimHandle = mDraw->GetHandle();
	//プレイヤーに描画用コンポーネント登録
	mManager->AddDraw(mDraw);
	mCol = new CapsuleColComponent(this);
	//半径設定
	float rad = 30.0;
	mCol->SetRadius(rad);
	//線分の長さ設定
	float line_seg = 170.0;
	mCol->SetSeg(line_seg);

}

void Weapon::Process()
{
}

void Weapon::Render()
{
}
