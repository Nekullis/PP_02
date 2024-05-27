#pragma once
#include "Component.h"
class DrawComponent :public Component
{
public:
	DrawComponent(class ObjectBase* owner, int updateowder = 100);
	virtual ~DrawComponent();
	//更新
	void Update(float deltatime)override;
	//ゲッター
	int GetHandle() const { return mHandle; }
	//セッター
	void SetPass(std::string pass);
protected:
	int mHandle;
	std::string mPass;
};

