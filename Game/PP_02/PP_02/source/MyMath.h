#pragma once
#include "Vector3D.h"
#include <math.h>
//計算関連関数をまとめたクラス
class MyMath
{
	//円周率
	static constexpr double PI = 3.14159265;
public:
	MyMath();
	~MyMath();
	//角度単位の変換
	//degree->rad
	template<typename T>
	static T DegToRad(T deg) { return deg * PI / 180.0; }
	//rad->degree
	template<typename T>
	static T RadToDeg(T rad) { return rad * 180.0 / PI; }
	//最短距離系
	//点と直線の最短距離
	static float DisPointAndLine(Vector3D& v1, Vector3D& v2s, Vector3D& v2e, Vector3D& mp, double& t);
	//点と線分の最短距離
	static float DisPointAndSegment(Vector3D& v1, Vector3D& v2s, Vector3D& v2e, Vector3D& mp, double& t);
	//直線と直線の最短距離
	static float DisLineAndLine(Vector3D& v1s, Vector3D& v1e, Vector3D& v1m, double& t1, Vector3D& v2s, Vector3D& v2e, Vector3D& v2m, double& t2);
	//線分と線分の最短距離
	static float DisSegAndSeg(Vector3D& v1s, Vector3D& v1e, Vector3D& v1m, double& t1, Vector3D& v2s, Vector3D& v2e, Vector3D& v2m, double& t2);
	//点とAABBの最短距離
	static float DisPointAndAABB(Vector3D v1, double w1, double h1, double d1, Vector3D v2);
	//当たり判定系
	//点と扇形の当たり判定
	static bool ColPointAndFan(Vector3D v1, Vector3D v2, float rad);
};
