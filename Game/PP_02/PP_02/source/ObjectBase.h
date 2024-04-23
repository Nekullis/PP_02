#pragma once
#include "DxLib.h"
#include "Vector3D.h"
//�I�u�W�F�N�g�̐e�N���X
//�I�u�W�F�N�g�͂��̃N���X�A�܂��͂��̔h���N���X���琶��
class ObjectBase
{
public:
	ObjectBase();
	virtual ~ObjectBase();
	virtual void Initialize();
	virtual void Process();
	virtual void Render();
	//�Q�b�^�[
	bool GetDeleteFlag() const { return _deleteFlag; }
	Vector3D GetPos() { return _vPos; }
	//�Z�b�^�[
	void SetPos(const Vector3D& pos) { _vPos = pos; }
protected:
	//�ʒu
	Vector3D _vPos;
	//�p�x
	Vector3D _vDir;
	//�����\�肩
	bool _deleteFlag;
};

