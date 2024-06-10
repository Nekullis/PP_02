#pragma once
#include "AppFrame.h"
class DrawComponent :public Component
{
public:
	DrawComponent(class ObjectBase* owner, int updateowder = 100);
	virtual ~DrawComponent();
	//�X�V
	void Update()override;
	//�Q�b�^�[
	int GetHandle() const { return mHandle; }
	//�Z�b�^�[
	void LoadPass(const char* pass);
protected:
	int mHandle;
	const char* mPass;
};

