#pragma once
#include <utility>
#include "AppFrame.h"
//�Q�[�����̃J���������S�ʂ̃N���X
class Camera : public ObjectBase
{
	using base = ObjectBase;
public:
	Camera();
	virtual ~Camera();
	void Process()override;
	void SetCamera(Vector3D pos, Vector3D target);
	//�Q�b�^�[
	Vector3D GetTerget() { return mTarget; }
	//�Z�b�^�[
	void SetTerget(Vector3D vec) { mTarget = vec; }
protected:
	//�J���������_
	Vector3D mTarget;
	//�ŒZ�`�拗��
	float mNear;
	//�Œ��`�拗��
	float mFar;
};

