#include "Camera.h"

Camera::Camera() : base()
{
	_vTarget = { 0 };
}

Camera::~Camera()
{
}

void Camera::Process()
{
	base::Process();
}
