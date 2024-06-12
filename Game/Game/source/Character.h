#pragma once
#include "AppFrame.h"
class Character : public ObjectBase
{
	using base = ObjectBase;
	//キャラクター全般の親クラス
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
	//ゲッター
	int GetHP() const { return _hp; }
	//セッター
protected:
	//体力
	int _hp;
	//アニメーション関連
	int mAnimHandle;
	int mAnimAttachIndex;
	int mAttachNum;
	float mAnimPlayTime;
	float mAnimTotalTime;
};

