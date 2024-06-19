#pragma once
#include "AppFrame.h"
class DrawComponent :public Component
{
public:
	DrawComponent(class ObjectBase* owner, int updateowder = 300);
	virtual ~DrawComponent();
	//更新
	void Update()override;
	//ゲッター
	int GetHandle() const { return mHandle; }
	Vector3D GetPos() { return mPos; }
	//セッター
	void LoadPass(const char* pass);
	void SetPos(Vector3D pos) { mPos = pos; }
protected:
	int mHandle;
	const char* mPass;
	Vector3D mPos;
};

