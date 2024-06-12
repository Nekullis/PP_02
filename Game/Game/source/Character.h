#pragma once
#include "AppFrame.h"
class Character : public ObjectBase
{
	using base = ObjectBase;
	//�L�����N�^�[�S�ʂ̐e�N���X
public:
	enum class ANIMATION
	{
		WAIT,
		WALK
	};
	Character(ModeBase* game);
	virtual ~Character();
	virtual void RegisterAnimation();
	void Initialize()override;
	void Process()override;
	void Render()override;
	//�Q�b�^�[
	int GetHP() const { return _hp; }
	//�Z�b�^�[
protected:
	//�̗�
	int _hp;
	//�A�j���[�V�����֘A
	int mAnimHandle;
	int mAnimAttachIndex;
	int mAttachNum;
	float mAnimPlayTime;
	float mAnimTotalTime;
};

