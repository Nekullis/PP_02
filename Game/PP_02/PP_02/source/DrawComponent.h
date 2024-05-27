#pragma once
#include "Component.h"
class DrawComponent :public Component
{
public:
	DrawComponent(class ObjectBase* owner, int updateowder = 100);
	virtual ~DrawComponent();
	//�X�V
	void Update(float deltatime)override;
	//�Q�b�^�[
	int GetHandle() const { return mHandle; }
	//�Z�b�^�[
	void SetPass(std::string pass);
protected:
	int mHandle;
	std::string mPass;
};

