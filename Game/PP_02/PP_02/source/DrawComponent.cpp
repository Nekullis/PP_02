#include "DrawComponent.h"
#include "ObjectBase.h"
#include "DxLib.h"

DrawComponent::DrawComponent(ObjectBase* owner, int updateowder) :Component(owner, updateowder)
{
	mHandle = 0;
	mPass = "";
}

DrawComponent::~DrawComponent()
{
}

void DrawComponent::SetPass(const char* pass)
{
	mPass = pass;
	mHandle = MV1LoadModel((const TCHAR*)(mPass));
}

void DrawComponent::Update()
{
	Component::Update();
	MV1SetPosition(mHandle, mOwner->GetPos().dxl());
	//MV1SetRotationXYZ(mHandle, Vector3D(mOwner->GetRotation(), 0, 0).dxl());
	MV1DrawModel(mHandle);
}


