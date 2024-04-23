#pragma once
#include "Character.h"
class Player : public Character
{
	using chara = Character;
public:
	//ステータス
	enum class STATUS
	{
		WAIT
	};
	Player();
	virtual ~Player();
	void Initialize()override;
	void Process()override;
	void Render()override;
protected:
	//ステータス
	STATUS _status;
};

