#include "ObjectBase.h"

ObjectBase::ObjectBase()
{
	//�ʒu
	_vPos = { 0 };
	//�p�x
	_vDir = { 0 };
	//�����\�肩
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
