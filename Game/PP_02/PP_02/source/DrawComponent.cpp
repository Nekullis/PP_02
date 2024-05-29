#include "DrawComponent.h"
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
	MV1DrawModel(mHandle);
}


