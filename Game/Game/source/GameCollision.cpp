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
}

void GameCollision::CameraTerget()
{
	CameraComponent* camera = CameraComponent::GetInstance();
	GameXPad* pad = GameXPad::GetInstance();
	std::list<ObjectBase*> object_list = ObjectManager::GetInstance()->GetObjectList();
	//ロックオン用トリガが入力された
	if(pad->GetXLt())
	{
		//ロックオン状態なら解除
		if(mIsLock) { mIsLock = false; }
		//カメラ位置を代入
		Vector3D cam_s_dis = camera->GetPos();
		while(1)
		{
			//ロックオン状態なら抜け出す
			if(mIsLock) { break; }
			//カメラ注視点回転角(y軸の回転行列)
			Matrix3D rot_y = ::MGetRotY(mSearchRot);
			//カメラのロックオンに使う線分、カメラの位置からの差分値
			Vector3D add = Vector3D(cam_s_dis._x, cam_s_dis._y, cam_s_dis._z + 2000);
			//カメラ位置と差分の加算しそこに回転値を入れる
			Vector3D cam_e_dis = (cam_s_dis + add) * rot_y;
			//線分と線分の最短距離を求める際に使う変数。入れるだけでいいので実際、値は使っていない
			Vector3D v1m = Vector3D(0.0, 0.0, 0.0);
			Vector3D v2m = Vector3D(0.0, 0.0, 0.0);
			double t1 = 0.0;
			double t2 = 0.0;
			//オブジェクトの数だけ回す
			for(auto&& obj : object_list)
			{
				//プレイヤーは候補に入れない
				if(obj->GetPos() == Player::GetInstance()->GetPos()) { continue; }
				//敵の位置取得
				Vector3D em_s_dis = obj->GetPos();
				//敵を線分と見立てた際のもう一つの頂点値
				Vector3D add = Vector3D(0.0, 100.0, 0.0);
				//頂点を加算し線分として扱う
				Vector3D em_e_dis = obj->GetPos() + add;
				//線分と線分の最短距離を求める
				float len = MyMath::DisSegAndSeg(cam_s_dis, cam_e_dis, v1m, t1, em_s_dis, em_e_dis, v2m, t2);
				//最短距離が敵のカメラ用半径よりも大きいとき
				if(len <= 5000) 
				{ 
					//ロックオンの値を決める
					mCamTarget = em_s_dis;
					//ロックオンしている状態に
					mIsLock = true; 
					//for文から抜け出す
					break;
				}
				
				//else { mSearchRot += 0.05; }
			}
			//if(mSearchRot >= 0.3) { break; }
		}
		
	}
	//if(mIsLock) { CameraComponent::cameraInstance->SetTarget(mCamTarget); }
	//else{ mSearchRot = CameraComponent::GetInstance()->GetDir()._y; }
}
