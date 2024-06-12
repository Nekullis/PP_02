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
	void RegisterAnimation()override;
	void Initialize()override;
	void Process()override;
	void Render()override;
	//�Z�b�^�[
protected:
	//�X�e�[�^�X
	ANIMATION mAnimation;
	ANIMATION oldAnimation;
	class ObjectManager* mManager;
};

