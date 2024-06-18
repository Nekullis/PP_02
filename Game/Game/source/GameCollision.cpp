#include "GameCollision.h"
#include "CameraComponent.h"
#include "ObjectManager.h"
#include "InputComponent.h"
#include "Player.h"

GameCollision* GameCollision::colInstance = nullptr;
GameCollision::GameCollision()
{
	colInstance = this;
	mIsLock = false;
	mSearchRot = 0;
	mCamTarget = Vector3D(0,0,0);
}

GameCollision::~GameCollision()
{
}

void GameCollision::Update()
{
	CameraTerget();
	ObjectCollision();
}

void GameCollision::CameraTerget()
{
	CameraComponent* camera = CameraComponent::GetInstance();
	GameXPad* pad = GameXPad::GetInstance();
	std::list<ObjectBase*> object_list = ObjectManager::GetInstance()->GetObjectList();
	//ロックオン用トリガが入力された
	if (pad->GetXLt())
	{
		//ロックオン状態なら解除
		if (mIsLock)
		{
			mIsLock = false;
		}
		//カメラ位置を代入
		Vector3D cam_s_dis = camera->GetPos();
		//カメラ注視点回転角(y軸の回転行列)
		Matrix3D rot_y = ::MGetRotY(mSearchRot);
		//カメラのロックオンに使う線分、カメラの位置からの差分値
		Vector3D add = Vector3D(0.0, 0.0, 2000.0);
		//カメラ位置と差分の加算しそこに回転値を入れる
		Vector3D cam_e_dis = cam_s_dis + add * rot_y;
		// 最も近い敵を探すための距離
		float closest_distance = FLT_MAX; 
		Vector3D closest_enemy_pos;
		//線分と線分の最短距離を求める際に使う変数。入れるだけでいいので実際、値は使っていない
		Vector3D v1m = Vector3D(0.0, 0.0, 0.0);
		Vector3D v2m = Vector3D(0.0, 0.0, 0.0);
		double t1 = 0.0;
		double t2 = 0.0;
		//オブジェクトの数だけ回す
		for (auto&& obj : object_list)
		{
			//プレイヤーは候補に入れない
			if (obj->GetPos() == Player::GetInstance()->GetPos()) { continue; }
			//敵の位置
			Vector3D enemy_pos = obj->GetPos();
			//敵の高さを考慮
			Vector3D enemy_top_pos = enemy_pos + Vector3D(0.0f, 100.0f, 0.0f); 
			//線分と線分の最短距離を求める
			float len = MyMath::DisSegAndSeg(cam_s_dis, cam_e_dis, v1m, t1, enemy_pos, enemy_top_pos, v2m, t2);
			//最短距離が今の最大値よりも小さく敵のカメラ用半径よりも大きいとき
			if(len < closest_distance && len <= 1500.0f)
			{
				//最短距離の更新
				closest_distance = len;
				//注視点の変更
				closest_enemy_pos = enemy_pos;
				//ロックオンをtrueに
				mIsLock = true;
			}
		}
		if(mIsLock)
		{
			//最も近い敵をターゲット
			mCamTarget = closest_enemy_pos; 
		}
	}
}

void GameCollision::ObjectCollision()
{
	std::list<ObjectBase*> object_list = ObjectManager::GetInstance()->GetObjectList();
	//最短距離初期化
	float dist_captocap = 0;
	for (auto&& obj_i : object_list)
	{
		for (auto&& obj_j : object_list)
		{
			if (obj_i == obj_j) { continue; }
			Vector3D pos_i = obj_i->GetPos();
			Vector3D pos_j = obj_j->GetPos();
			//線分と線分の最短距離を求める際に使う変数。入れるだけでいいので実際、値は使っていない
			Vector3D v1m = Vector3D(0.0, 0.0, 0.0);
			Vector3D v2m = Vector3D(0.0, 0.0, 0.0);
			double t1 = 0.0;
			double t2 = 0.0;
			dist_captocap = MyMath::DisSegAndSeg(pos_i, pos_i, v1m, t1, pos_j, pos_j, v2m, t2);
			if (dist_captocap <= 40)
			{
				Vector3D v = pos_j - pos_i;
				double len = v.Length();
				len = 40 - len;
				Vector3D norm = v.Normalize();
				Vector3D pos = norm.Scale(len);
				obj_j->SetPos(pos);
			}
		}
	}
}
