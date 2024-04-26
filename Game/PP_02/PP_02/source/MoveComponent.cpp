#include "MoveComponent.h"
#include "ObjectBase.h"
#include <Math.h>
MoveComponent::MoveComponent(class ObjectBase* owner, int updateowder) :Component(owner, updateowder)
{
	mPad = new GameXPad();
}

MoveComponent::~MoveComponent()
{

}

void MoveComponent::Update()
{
	Component::Update();
	mPad->Input();
	Vector3D vec = Vector3D(0, 0, 0);
	//キーに対応した数値を入れる
	//if(mPad->GetXKey(XINPUT_BUTTON_A)) { vec._x + 10; }
	//if(mPad->GetXKey(XINPUT_BUTTON_B)) { vec._y + 10; }
	//if(mPad->GetXKey(XINPUT_BUTTON_X)) { vec._x - 10; }
	//if(mPad->GetXKey(XINPUT_BUTTON_Y)) { vec._y - 10; }
	//位置情報の更新
	mOwner->SetPos(vec);
}
