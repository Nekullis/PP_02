#pragma once
#include "AppFrame.h"
class Weapon : public ObjectBase
{
public:
	Weapon(ModeBase* game);
	virtual ~Weapon();
	void Initialize()override;
	void Process()override;
	void Render()override;
	//ゲッター
	float GetRadius() { return mRadius; }
	//セッター
	void SetRadius(float radius) { mRadius = radius; }
protected:
	float mRadius;
	int mAnimHandle;
	class ObjectManager* mManager;
	class CapsuleColComponent* mCol;
	class DrawComponent* mDraw;
};

