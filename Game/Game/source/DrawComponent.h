#pragma once
#include "AppFrame.h"
class DrawComponent :public Component
{
public:
	DrawComponent(class ObjectBase* owner, int updateowder = 300);
	virtual ~DrawComponent();
	//�X�V
	void Update()override;
	//�Q�b�^�[
	int GetHandle() const { return mHandle; }
	Vector3D GetPos() { return mPos; }
	//�Z�b�^�[
	void LoadPass(const char* pass);
	void SetPos(Vector3D pos) { mPos = pos; }
protected:
	int mHandle;
	const char* mPass;
	Vector3D mPos;
};

