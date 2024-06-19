#include "CollisionManager.h"
#include "CapsuleColComponent.h"
#include <iostream>
CollisionManager* CollisionManager::colMaInstance = nullptr;
CollisionManager::CollisionManager()
{
	colMaInstance = this;
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
	float dist_captocap = 0.0;
	float seg = 170.0;;
	for (auto&& col : mCollisionList)
	{
		col->Update();
	}
	for (auto&& col_i : mCollisionList)
	{
		for (auto&& col_j : mCollisionList)
		{
			if (col_i == col_j) { continue; }
			if (col_i->GetType() == CollisionComponent::COLLISIONTYPE::CAPSULE && col_j->GetType() == CollisionComponent::COLLISIONTYPE::CAPSULE)
			{
				Vector3D pos_i_s = col_i->GetPos();
				Vector3D pos_i_e = col_i->GetPos() + Vector3D(0.0, seg, 0.0);
				Vector3D pos_j_s = col_j->GetPos();
				Vector3D pos_j_e = col_j->GetPos() + Vector3D(0.0, seg, 0.0);
				//線分と線分の最短距離を求める際に使う変数。入れるだけでいいので実際、値は使っていない
				Vector3D v1m = Vector3D(0.0, 0.0, 0.0);
				Vector3D v2m = Vector3D(0.0, 0.0, 0.0);
				double t1 = 0.0;
				double t2 = 0.0;
				dist_captocap = MyMath::DisSegAndSeg(pos_i_s, pos_i_e, v1m, t1, pos_j_s, pos_j_e, v2m, t2);
				float add_rad = col_i->GetRadius() + col_j->GetRadius();
				if (dist_captocap <= add_rad)
				{
					Vector3D v = pos_j_s - pos_i_s;
					double len = v.Length();
					len = add_rad - len;
					Vector3D norm = v.Normalize();
					Vector3D pos = norm.Scale(len);
					col_j->GetOwner()->SetPos(col_j->GetPos() + pos);

				}
			}
		}
	}
}