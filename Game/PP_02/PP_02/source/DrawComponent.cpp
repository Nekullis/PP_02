#include "DrawComponent.h"
#include "DxLib.h"

DrawComponent::DrawComponent(ObjectBase* owner, int updateowder) :Component(owner, updateowder)
{

}

DrawComponent::~DrawComponent()
{
}

void DrawComponent::SetPass(std::string pass)
{
	mPass = pass;
	mHandle = MV1LoadModel((const TCHAR*)(mPass.c_str()));
}

void DrawComponent::Update(float deltatime)
{
	MV1DrawModel(mHandle);
}


