#pragma once
#include "ObjectBase.h"
class Stage : public ObjectBase
{
public:
	Stage();
	virtual ~Stage();
	void Initialize()override;
	void Process()override;
	void Render()override;
};
