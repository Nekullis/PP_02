#include "Camera.h"

Camera::Camera() : base()
{
	mTarget = { 0 };
	mNear = 20;
	mFar = 10000;
}

Camera::~Camera()
{
}

void Camera::SetCamera(Vector3D pos, Vector3D target)
{
	mPos = pos;
	mTarget = target;
}

void Camera::Process()
{
	base::Process();
	SetCameraNearFar(mNear, mFar);
	SetCameraPositionAndTarget_UpVecY(mPos.dxl(), mTarget.dxl());
}


