#pragma once
#include "ObjectBase.h"
class Character : public ObjectBase
{
	using base = ObjectBase;
	//�L�����N�^�[�S�ʂ̐e�N���X
public:
	Character();
	virtual ~Character();
	void Initialize()override;
	void Process()override;
	void Render()override;
	//�Q�b�^�[
	int GetHP() const { return _hp; }
protected:
	//�̗�
	int _hp;
};

