#pragma once
#include <memory>
//AI�̏�Ԃ̋K��N���X
class AIState
{
public:
	AIState(class AIComponent* owner);
	virtual ~AIState();
	//�X�V
	virtual void Update();
	//�J�ڂɓ���ۂ̏���
	virtual void OnEnter();
	//�J�ڂ���o��ۂ̏���
	virtual void OnExit();
	//���O�擾
	const char* GetName();
protected:
	//�g���R���|�[�l���g
	class AIComponent* mOwner;
};

