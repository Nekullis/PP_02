#pragma once
#include "AppFrame.h"
class ApplicationGlobal
{
//�N���X�֌W�Ȃ��O���[�o���Ŏg�����������܂Ƃ߂��N���X
public:
	ApplicationGlobal();
	virtual ~ApplicationGlobal();
	//������
	bool Init();
	class ResourceManager* mResManager;
	//class SoundServer mSndServer;
	class GameXPad* mPad;
	//���[�h�ł��Ă��邩
	bool _isLoad;
};
extern ApplicationGlobal _global;