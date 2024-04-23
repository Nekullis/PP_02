#pragma once
#include <utility>
#include "ObjectBase.h"
//�Q�[�����̃J���������S�ʂ̃N���X
class Camera : public ObjectBase
{
	using base = ObjectBase;
public:
	Camera();
	virtual ~Camera();
	void Process()override;
	//�Q�b�^�[
	Vector3D GetTerget() { return _vTarget; }
protected:
	//�J���������_
	Vector3D _vTarget;
};

