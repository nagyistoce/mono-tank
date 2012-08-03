#include "sprite_bullet.h"

#include "graphic.h"

CSpriteBullet::CSpriteBullet()
{

}

CSpriteBullet::~CSpriteBullet()
{

}

CSpriteBullet *CSpriteBullet::create()
{
	CSpriteBullet *instance;

	instance = new CSpriteBullet;
	if (instance->initSpriteBullet())
	{
		instance->autorelease();
		return instance;
	}
	else
	{
		instance->release();
		return NULL;
	}
}

bool CSpriteBullet::initSpriteBullet()
{
	if (cocos2d::CCSprite::init())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CSpriteBullet::draw()
{
	glDisable(GL_COLOR_ARRAY);
	glDisable(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);

	glLineWidth(1.5f);
	glColor4ub(getColor().r, getColor().g, getColor().b, getOpacity());
	glVertexPointer(2, GL_FLOAT, 0, g_GpBulletVex);
	glDrawElements(GL_LINES, sizeof(g_GpBulletInx), GL_UNSIGNED_BYTE, g_GpBulletInx);

	glEnable(GL_COLOR_ARRAY);
	glEnable(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
}