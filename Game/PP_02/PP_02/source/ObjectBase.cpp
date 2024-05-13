#include "ObjectBase.h"
#include <algorithm>
#include "Component.h"
ObjectBase::ObjectBase()
{
	//ˆÊ’u
	_vPos = { 0 };
	//Šp“x
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
	//ƒRƒ“ƒeƒi‚ÉŠi”[‚·‚é
	mComponents.push_back(component);
	//Ši”[‚µ‚½ƒRƒ“ƒ|[ƒlƒ“ƒg‚Ì•À‚Ñ‘Ö‚¦
	std::sort(mComponents.begin(), mComponents.end(), [](Component* a, Component* b) {return a->GetUpdateOwder() < b->GetUpdateOwder(); });
}

void ObjectBase::RemoveComponent(Component* component)
{

}
