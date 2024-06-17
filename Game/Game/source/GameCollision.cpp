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
	//���b�N�I���p�g���K�����͂��ꂽ
	if(pad->GetXLt())
	{
		//���b�N�I����ԂȂ����
		if(mIsLock) { mIsLock = false; }
		//�J�����ʒu����
		Vector3D cam_s_dis = camera->GetPos();
		while(1)
		{
			//���b�N�I����ԂȂ甲���o��
			if(mIsLock) { break; }
			//�J���������_��]�p(y���̉�]�s��)
			Matrix3D rot_y = ::MGetRotY(mSearchRot);
			//�J�����̃��b�N�I���Ɏg�������A�J�����̈ʒu����̍����l
			Vector3D add = Vector3D(cam_s_dis._x, cam_s_dis._y, cam_s_dis._z + 2000);
			//�J�����ʒu�ƍ����̉��Z�������ɉ�]�l������
			Vector3D cam_e_dis = (cam_s_dis + add) * rot_y;
			//�����Ɛ����̍ŒZ���������߂�ۂɎg���ϐ��B����邾���ł����̂Ŏ��ہA�l�͎g���Ă��Ȃ�
			Vector3D v1m = Vector3D(0.0, 0.0, 0.0);
			Vector3D v2m = Vector3D(0.0, 0.0, 0.0);
			double t1 = 0.0;
			double t2 = 0.0;
			//�I�u�W�F�N�g�̐�������
			for(auto&& obj : object_list)
			{
				//�v���C���[�͌��ɓ���Ȃ�
				if(obj->GetPos() == Player::GetInstance()->GetPos()) { continue; }
				//�G�̈ʒu�擾
				Vector3D em_s_dis = obj->GetPos();
				//�G������ƌ����Ă��ۂ̂�����̒��_�l
				Vector3D add = Vector3D(0.0, 100.0, 0.0);
				//���_�����Z�������Ƃ��Ĉ���
				Vector3D em_e_dis = obj->GetPos() + add;
				//�����Ɛ����̍ŒZ���������߂�
				float len = MyMath::DisSegAndSeg(cam_s_dis, cam_e_dis, v1m, t1, em_s_dis, em_e_dis, v2m, t2);
				//�ŒZ�������G�̃J�����p���a�����傫���Ƃ�
				if(len <= 5000) 
				{ 
					//���b�N�I���̒l�����߂�
					mCamTarget = em_s_dis;
					//���b�N�I�����Ă����Ԃ�
					mIsLock = true; 
					//for�����甲���o��
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
