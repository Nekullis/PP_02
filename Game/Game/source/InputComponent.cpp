#include "InputComponent.h"
#include "Player.h"

InputComponent::InputComponent(ObjectBase* owner, int updateowder) :MoveComponent(owner, updateowder)
{
	//コントローラー初期化
	mPad = new GameXPad();
}

InputComponent::~InputComponent()
{
}

void InputComponent::Update()
{
	mPad->Input();
	//アナログパッドの値をatan2関数で角度を得る
	float dir = atan2(mPad->GetXLy(), mPad->GetXLx());
	//アナログパッドが動いているのなら
	if(mPad->IsInputStick())
	{
		//参照オブジェクトの位置を取得
		Vector3D pos = mOwner->GetPos();;
		//セッターで得た速度を代入
		float speed = mForwardSpeed;
		pos._x += speed * cos(dir);
		pos._z += speed * sin(dir);
		mOwner->SetPos(pos);
		Vector3D rot = Vector3D(0, -(dir + 90 * DX_PI / 180), 0);
		mOwner->SetRotation(rot);
	}
	
}
