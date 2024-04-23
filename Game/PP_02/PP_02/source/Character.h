#pragma once
#include "ObjectBase.h"
class Character : public ObjectBase
{
	using base = ObjectBase;
	//キャラクター全般の親クラス
public:
	Character();
	virtual ~Character();
	void Initialize()override;
	void Process()override;
	void Render()override;
	//ゲッター
	int GetHP() const { return _hp; }
protected:
	//体力
	int _hp;
};

