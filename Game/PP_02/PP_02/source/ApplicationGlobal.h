#pragma once
class ApplicationGlobal
{
//クラス関係なくグローバルで使いたい物をまとめたクラス
public:
	ApplicationGlobal();
	virtual ~ApplicationGlobal();
	//初期化
	bool Init();
	//ロードできているか
	bool _isLoad;
};
extern ApplicationGlobal _global;