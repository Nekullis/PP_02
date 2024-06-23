#include "DamageEffect.h"
#include "DrawPolygonComponent.h"

DamageEffect::DamageEffect(ModeBase* game) :PolygonEffect(game)
{

	mUseFlag = true;
	mPlayTotalTime = 500;
	mNowPlayTime = GetNowCount();
	mColorAlpha = 255;
}

DamageEffect::~DamageEffect()
{
}

void DamageEffect::Start(int allpolynum)
{
	mParticleList.clear();
	for (int i = 0; i < allpolynum; i++)
	{
		PARTICLE particle;
		particle.Pos = mPos;
		particle.Velocity._x = (float)(rand() % 20 - 10);
		particle.Velocity._y = (float)(rand() % 20 - 10);
		particle.Velocity._z = (float)(rand() % 20 - 10);
		COLOR_U8 color = GetColorU8(255, rand() % 256, rand() % 256, mColorAlpha);
		particle.Color = color;
		mParticleList.push_back(particle);
	}
	
	mDrawPoly = new DrawPolygonComponent(this);
}

void DamageEffect::Process()
{
	if (!mUseFlag) { return; }
	int current_time = GetNowCount();
	int elapsed_time = current_time - mNowPlayTime;
	if (elapsed_time > mPlayTotalTime)
	{ 
		mUseFlag = false;
		return;
	}
	for (auto&& particle : mParticleList)
	{
		particle.Pos._x = particle.Velocity._x * 0.1;
		particle.Pos._y = particle.Velocity._y * 0.1;
		particle.Pos._z = particle.Velocity._z * 0.1;
	}
	int alpha = 255 * ((mPlayTotalTime - elapsed_time) / mPlayTotalTime);
	std::vector<VERTEX3D> vertices;
	std::vector<int> index;
	for (auto&& particle : mParticleList)
	{
		VERTEX3D vertex;
		for (int i = 0; i < 4; ++i)
		{
			vertex.pos = Vector3D(particle.Pos._x + (i == 1 || i == 2 ? 5 : -5), particle.Pos._y + (i >=  2 ? 5 : -5), particle.Pos._z).dxl();
			vertex.dif = particle.Color;
			vertices.push_back(vertex);
		}
	}
}

void DamageEffect::Render()
{
}
