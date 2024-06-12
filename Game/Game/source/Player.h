#pragma once
#include "Character.h"
class Player : public Character
{
	using chara = Character;
public:
	//�X�e�[�^�X
	enum class ANIMATION
	{
		WAIT,
		WALK
	};
	Player(ModeBase* game);
	virtual ~Player();
	void RegisterAnimation();
	void Initialize()override;
	void Process()override;
	void Render()override;
	//�Z�b�^�[
	void SetAnimation(ANIMATION animation) { mAnimation = animation; }
protected:
	//�X�e�[�^�X
	ANIMATION mAnimation;
	ANIMATION oldAnimation;
	class ObjectManager* mManager;
	//�A�j���[�V�����֘A
	int mAnimHandle;
	int mAnimAttachIndex;
	float mAnimPlayTime;
	float mAnimTotalTime;
	std::pair<int, int> mAnimBrend;


	
};

