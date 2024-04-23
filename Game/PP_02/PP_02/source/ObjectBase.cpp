#include "ObjectBase.h"

ObjectBase::ObjectBase()
{
	//à íu
	_vPos = { 0 };
	//äpìx
	_vDir = { 0 };
	//è¡ãéó\íËÇ©
	_deleteFlag = false;
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
}

void ObjectBase::Render()
{
}
