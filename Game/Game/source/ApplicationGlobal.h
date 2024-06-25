#pragma once
#include "AppFrame.h"
class ApplicationGlobal
{
//クラス関係なくグローバルで使いたい物をまとめたクラス
public:
	ApplicationGlobal();
	virtual ~ApplicationGlobal();
	//初期化
	bool Init();
	class ResourceManager mResManager;
	//ロードできているか
	bool _isLoad;
};
extern ApplicationGlobal _global;