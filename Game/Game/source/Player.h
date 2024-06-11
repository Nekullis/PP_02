#pragma once
#include "Character.h"
class Player : public Character
{
	using chara = Character;
public:
	//�X�e�[�^�X
	enum class STATUS
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
protected:
	//�X�e�[�^�X
	STATUS _status;
	class ObjectManager* mManager;
	//�A�j���[�V�����֘A
	int mAnimHandle;
	int mAnimAttachIndex;
	float mAnimPlayTime;
	float mAnimTotalTime;


	
};

