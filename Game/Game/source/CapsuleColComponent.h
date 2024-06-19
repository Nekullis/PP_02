#pragma once
#include "CollisionComponent.h"
//�J�v�Z���^�̏Փ˔���p�R���|�[�l���g
class CapsuleColComponent :public CollisionComponent
{
public:
	static CapsuleColComponent* capInstance;
	CapsuleColComponent(class ObjectBase* owner, int updateowder = 200);
	virtual ~CapsuleColComponent();
	void Update()override;
	//�Q�b�^�[
	static CapsuleColComponent* GetInstance() { return capInstance; }
	float GetSeg() { return mLineSeg; }
	//�Z�b�^�[
	void SetSeg(float seg) { mLineSeg = seg; }
protected:
	float mLineSeg;
};

