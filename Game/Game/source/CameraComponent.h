#pragma once
#include <utility>
#include "AppFrame.h"
//�Q�[�����̃J���������S�ʂ̃N���X
class CameraComponent : public Component
{
public:
	CameraComponent(ObjectBase* owner,int updateowder = 100);
	virtual ~CameraComponent();
	void Update()override;
	//�Q�b�^�[
	Vector3D GetTerget() { return mTarget; }
	//�Z�b�^�[
	void SetTerget(Vector3D vec) { mTarget = vec; }
protected:
	//�J�����ʒu
	Vector3D mPos;
	//�J���������_
	Vector3D mTarget;
	//�ŒZ�`�拗��
	float mNear;
	//�Œ��`�拗��
	float mFar;
};

