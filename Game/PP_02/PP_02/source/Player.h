#pragma once
#include "Character.h"
class Player : public Character
{
	using chara = Character;
public:
	//�X�e�[�^�X
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
	//�X�e�[�^�X
	STATUS _status;
};

