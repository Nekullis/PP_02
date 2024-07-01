#include "ModeSound.h"
#include "ApplicationGlobal.h"
#include "AppFrame.h"

bool ModeSound::Initialize()
{
	if (!ModeBase::Initialize()) { return false; }
	//	 非同期読み込み設定
	SetUseASyncLoadFlag(TRUE);
	//	 音データファイルを読み込む
		//BGM
	//_global.mSndServer.Add("BGM_Title", new SoundItemBGM("res/Sound/BGM/Title.mp3"));
	//_global.mSndServer.Add("BGM_Clear", new SoundItemBGM("res/Sound/BGM/Clear.mp3"));
	//_global.mSndServer.Add("BGM_GameOver", new SoundItemBGM("res/Sound/BGM/GameOver.mp3"));
	//_global.mSndServer.Add("BGM_Quest01", new SoundItemBGM("res/Sound/BGM/Quest01.mp3"));
	//_global.mSndServer.Add("BGM_Quest02", new SoundItemBGM("res/Sound/BGM/Quest02.mp3"));
	//_global.mSndServer.Add("BGM_Quest03", new SoundItemBGM("res/Sound/BGM/Quest03.mp3"));
	//_global.mSndServer.Add("BGM_Boss", new SoundItemBGM("res/Sound/BGM/Boss.mp3"));
	//_global.mSndServer.Add("BGM_RastBoss", new SoundItemBGM("res/Sound/BGM/RastBoss.mp3"));
	////SE
	//_global.mSndServer.Add("SE_Attack01", new SoundItemSE("res/Sound/SE/SE_Attack01.mp3"));
	//_global.mSndServer.Add("SE_Attack02", new SoundItemSE("res/Sound/SE/SE_Attack02.mp3"));
	//_global.mSndServer.Add("SE_Attack03", new SoundItemSE("res/Sound/SE/SE_Attack03.mp3"));
	//_global.mSndServer.Add("SE_Run", new SoundItemSE("res/Sound/SE/SE_Run.mp3"));
	//_global.mSndServer.Add("SE_Divine", new SoundItemSE("res/Sound/SE/SE_Divine.mp3"));
	//_global.mSndServer.Add("SE_Laser", new SoundItemSE("res/Sound/SE/SE_Beam.mp3"));
	//_global.mSndServer.Add("SE_Skill", new SoundItemSE("res/Sound/SE/SE_Divine.mp3"));
	//_global.mSndServer.Add("SE_Explosion", new SoundItemSE("res/Sound/SE/SE_Explosion.mp3"));
	//_global.mSndServer.Add("SE_Hammer", new SoundItemSE("res/Sound/SE/SE_hammer.mp3"));
	//_global.mSndServer.Add("SE_Slash", new SoundItemSE("res/Sound/SE/SE_Slash.mp3"));
	//_global.mSndServer.Add("SE_Breath", new SoundItemSE("res/Sound/SE/SE_Breath.mp3"));
	//_global.mSndServer.Add("SE_Circle", new SoundItemSE("res/Sound/SE/SE_Circle.mp3"));
	//_global.mSndServer.Add("SE_Sonic", new SoundItemSE("res/Sound/SE/SE_Sonic.mp3"));
	//_global.mSndServer.Add("SE_DashAttack", new SoundItemSE("res/Sound/SE/SE_DashAttack.mp3"));
	//_global.mSndServer.Add("SE_Vacuum", new SoundItemSE("res/Sound/SE/SE_Vacuum.mp3"));
	//_global.mSndServer.Add("SE_UI_Decision", new SoundItemSE("res/Sound/SE/SE_UI_Decision.mp3"));
	//_global.mSndServer.Add("SE_Damage", new SoundItemSE("res/Sound/SE/SE_Damage.mp3"));
	//_global.mSndServer.Add("SE_Damage_Crab", new SoundItemSE("res/Sound/SE/SE_Damage_Crab.mp3"));
	//_global.mSndServer.Add("SE_Slot_Start", new SoundItemSE("res/Sound/SE/SE_Slot_Start.mp3"));
	//_global.mSndServer.Add("SE_Slot_Finish", new SoundItemSE("res/Sound/SE/SE_Slot_Finish.mp3"));
	//_global.mSndServer.Add("SE_Page", new SoundItemSE("res/Sound/SE/SE_Page.mp3"));
	//
	//	 同期読み込み設定
	SetUseASyncLoadFlag(FALSE);
	return true;
}

bool ModeSound::Terminate()
{
	ModeBase::Terminate();
	return true;
}

bool ModeSound::Process()
{
	ModeBase::Process();
	//_global.mSndServer.Update();
	return true;
}

bool ModeSound::Render()
{
	ModeBase::Render();
	return true;
}
