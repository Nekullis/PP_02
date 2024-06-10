#include "DrawComponent.h"
#include "ModeGame.h"
DrawComponent::DrawComponent(ObjectBase* owner, int updateowder) :Component(owner, updateowder)
{
	mHandle = 0;
	mPass = "";
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
	MV1SetPosition(mHandle, mOwner->GetPos().dxl());
	MV1SetRotationXYZ(mHandle, mOwner->GetRotation().dxl());
	MV1DrawModel(mHandle);
}


