#pragma once
class ApplicationGlobal
{
//�N���X�֌W�Ȃ��O���[�o���Ŏg�����������܂Ƃ߂��N���X
public:
	ApplicationGlobal();
	virtual ~ApplicationGlobal();
	//������
	bool Init();
	//���[�h�ł��Ă��邩
	bool _isLoad;
};
extern ApplicationGlobal _global;