#include "CollisionManager.h"
#include "CapsuleColComponent.h"
CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::AddCollision(CollisionComponent* col)
{
	mCollisionList.push_back(col);
}

void CollisionManager::Delete()
{

}

void CollisionManager::Update()
{
	int type = 0;
	float dist_captocap = 0.0;
	for (auto&& col_i : mCollisionList)
	{
		col_i->Update();
		for (auto&& col_j : mCollisionList)
		{
			if (col_i == col_j) { continue; }
			if (col_i->GetType() == CollisionComponent::COLLISIONTYPE::CAPSULE && col_j->GetType() == CollisionComponent::COLLISIONTYPE::CAPSULE)
			{
				type = 1;
			}
			switch (type)
			{
			case 1:
				float seg = 170;
				Vector3D pos_i_s = col_i->GetPos();
				Vector3D pos_i_e = col_i->GetPos() + Vector3D(0, 0, seg);
				Vector3D pos_j_s = col_j->GetPos();
				Vector3D pos_j_e = col_j->GetPos() + Vector3D(0, 0, seg);
				//線分と線分の最短距離を求める際に使う変数。入れるだけでいいので実際、値は使っていない
				Vector3D v1m = Vector3D(0.0, 0.0, 0.0);
				Vector3D v2m = Vector3D(0.0, 0.0, 0.0);
				double t1 = 0.0;
				double t2 = 0.0;
				dist_captocap = MyMath::DisSegAndSeg(pos_i_s, pos_i_e, v1m, t1, pos_j_s, pos_j_e, v2m, t2);
				if (dist_captocap <= col_i->GetRadius()+ col_j->GetRadius())
				{
					Vector3D v = pos_j_s - pos_i_s;
					double len = v.Length();
					len = col_i->GetRadius() + col_j->GetRadius() - len;
					Vector3D norm = v.Normalize();
					Vector3D pos = norm.Scale(len);
					col_j->SetPos(pos);
				}
				break;
			}
			
		}
	}
}