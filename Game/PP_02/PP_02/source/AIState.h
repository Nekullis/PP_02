#pragma once
#include <memory>
//AIの状態の規定クラス
class AIState
{
public:
	AIState(class AIComponent* owner);
	virtual ~AIState();
	//更新
	void Update();
	//遷移に入る際の処理
	void OnEnter();
	//遷移から出る際の処理
	void OnExit();
	//名前取得
	const char* GetName();
protected:
	//使うコンポーネント
	class AIComponent* mOwner;
};

