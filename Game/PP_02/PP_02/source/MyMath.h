#pragma once
#include "Vector3D.h"
#include <math.h>
//�v�Z�֘A�֐����܂Ƃ߂��N���X
class MyMath
{
	//�~����
	static constexpr double PI = 3.14159265;
public:
	MyMath();
	~MyMath();
	//�p�x�P�ʂ̕ϊ�
	//degree->rad
	template<typename T>
	static T DegToRad(T deg) { return deg * PI / 180.0; }
	//rad->degree
	template<typename T>
	static T RadToDeg(T rad) { return rad * 180.0 / PI; }
	//�����Ȓl�Ƃ̔�r
	static bool NearZero(double vol, double epsiron = 0.001);
	//�ŒZ�����n
	//�_�ƒ����̍ŒZ����
	static float DisPointAndLine(Vector3D& v1, Vector3D& v2s, Vector3D& v2e, Vector3D& mp, double& t);
	//�_�Ɛ����̍ŒZ����
	static float DisPointAndSegment(Vector3D& v1, Vector3D& v2s, Vector3D& v2e, Vector3D& mp, double& t);
	//�����ƒ����̍ŒZ����
	static float DisLineAndLine(Vector3D& v1s, Vector3D& v1e, Vector3D& v1m, double& t1, Vector3D& v2s, Vector3D& v2e, Vector3D& v2m, double& t2);
	//�����Ɛ����̍ŒZ����
	static float DisSegAndSeg(Vector3D& v1s, Vector3D& v1e, Vector3D& v1m, double& t1, Vector3D& v2s, Vector3D& v2e, Vector3D& v2m, double& t2);
	//�_��AABB�̍ŒZ����
	static float DisPointAndAABB(Vector3D v1, double w1, double h1, double d1, Vector3D v2);
	//�����蔻��n
	//�_�Ɛ�`�̓����蔻��
	static bool ColPointAndFan(Vector3D v1, Vector3D v2, float rad);
};
