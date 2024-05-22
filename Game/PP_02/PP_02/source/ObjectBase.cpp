#include "ObjectBase.h"
#include <algorithm>
#include "Component.h"
ObjectBase::ObjectBase()
{
	//位置
	mPos = { 0 };
	//角度
	mRotation = 0;
	//スケール
	mScale = 0;

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
	//条件に合うコンポーネントを探す
	auto itr = std::find(mComponents.begin(), mComponents.end(), component);
	//探したコンポーネントの消去
	if (itr != mComponents.end()) { mComponents.erase(itr); }
}
