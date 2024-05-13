#include "ObjectBase.h"
#include <algorithm>
#include "Component.h"
ObjectBase::ObjectBase()
{
	//位置
	_vPos = { 0 };
	//角度
	_vDir = { 0 };

	Initialize();
}

ObjectBase::~ObjectBase()
{

}

void ObjectBase::Initialize()
{

}

void ObjectBase::Process()
{
	for(auto&& comp : mComponents)
	{
		comp->Update();
	}
}

void ObjectBase::Render()
{
	
#if _DEBUG
	Debug();
#endif
}

void ObjectBase::Debug()
{

}

void ObjectBase::AddComponent(Component* component)
{
	//コンテナに格納する
	mComponents.push_back(component);
	//格納したコンポーネントの並び替え
	std::sort(mComponents.begin(), mComponents.end(), [](Component* a, Component* b) {return a->GetUpdateOwder() < b->GetUpdateOwder(); });
}

void ObjectBase::RemoveComponent(Component* component)
{

}
