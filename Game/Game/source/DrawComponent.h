#pragma once
#include "AppFrame.h"
class DrawComponent :public Component
{
public:
	DrawComponent(class ObjectBase* owner, int updateowder = 100);
	virtual ~DrawComponent();
	//更新
	void Update()override;
	//ゲッター
	int GetHandle() const { return mHandle; }
	//セッター
	void LoadPass(const char* pass);
protected:
	int mHandle;
	const char* mPass;
};

