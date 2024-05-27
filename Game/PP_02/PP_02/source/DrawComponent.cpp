#include "DrawComponent.h"
#include "DxLib.h"

DrawComponent::DrawComponent(ObjectBase* owner, int updateowder) :Component(owner, updateowder)
{
	mPass = "";
	mHandle = MV1LoadModel((const TCHAR*)(mPass.c_str()));
}

DrawComponent::~DrawComponent()
{
}

void DrawComponent::Update(float deltatime)
{
	MV1DrawModel(mHandle);
}
