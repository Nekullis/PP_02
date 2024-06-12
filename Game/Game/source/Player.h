#pragma once
#include "Character.h"
class Player : public Character
{
	using chara = Character;
public:
	//ステータス
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
	//セッター
protected:
	//ステータス
	ANIMATION mAnimation;
	ANIMATION oldAnimation;
	class ObjectManager* mManager;
};

