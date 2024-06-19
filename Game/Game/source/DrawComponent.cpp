#include "DrawComponent.h"
#include "ModeGame.h"
DrawComponent::DrawComponent(ObjectBase* owner, int updateowder) :Component(owner, updateowder)
{
	mOwner = owner;
	mHandle = 0;
	mPass = "";
	mPos = Vector3D(0.0, 0.0, 0.0);
}

DrawComponent::~DrawComponent()
{
}

void DrawComponent::LoadPass(const char* pass)
{
	mPass = pass;
	mHandle = MV1LoadModel((const TCHAR*)(mPass));
}

void DrawComponent::Update()
{
	Component::Update();
	//mPos = mOwner->GetPos();
	MV1SetPosition(mHandle, mPos.dxl());
	MV1SetRotationXYZ(mHandle, mOwner->GetRotation().dxl());
	MV1DrawModel(mHandle);
}


