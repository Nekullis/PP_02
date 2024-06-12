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
	void RegisterAnimation();
	void Initialize()override;
	void Process()override;
	void Render()override;
	//セッター
	void SetAnimation(ANIMATION animation) { mAnimation = animation; }
protected:
	//ステータス
	ANIMATION mAnimation;
	ANIMATION oldAnimation;
	class ObjectManager* mManager;
	//アニメーション関連
	int mAnimHandle;
	int mAnimAttachIndex;
	float mAnimPlayTime;
	float mAnimTotalTime;
	std::pair<int, int> mAnimBrend;


	
};

