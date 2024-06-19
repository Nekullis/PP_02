#pragma once
#include "CollisionComponent.h"
//カプセル型の衝突判定用コンポーネント
class CapsuleColComponent :public CollisionComponent
{
public:
	static CapsuleColComponent* capInstance;
	CapsuleColComponent(class ObjectBase* owner, int updateowder = 200);
	virtual ~CapsuleColComponent();
	void Update()override;
	//ゲッター
	static CapsuleColComponent* GetInstance() { return capInstance; }
	float GetSeg() { return mLineSeg; }
	//セッター
	void SetSeg(float seg) { mLineSeg = seg; }
protected:
	float mLineSeg;
};

