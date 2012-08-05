#include "sprite_tank.h"

#include "graphic.h"

CSpriteTank::CSpriteTank()
{

}

CSpriteTank::~CSpriteTank()
{

}

CSpriteTank *CSpriteTank::create()
{
	CSpriteTank *instance;

	instance = new CSpriteTank;
	if (instance->initSpriteTank())
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

bool CSpriteTank::initSpriteTank()
{
	if (cocos2d::CCSprite::init())
	{
		setColor(cocos2d::ccYELLOW);
		setOpacity(255);
		return true;
	}
	else
	{
		return false;
	}
}

void CSpriteTank::draw()
{
	return;
	glDisable(GL_COLOR_ARRAY);
	glDisable(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);

	glLineWidth(1.5f);
	glColor4ub(getColor().r, getColor().g, getColor().b, getOpacity());
	glVertexPointer(2, GL_FLOAT, 0, g_GpTankVex);
	glDrawElements(GL_LINES, sizeof(g_GpTankInx), GL_UNSIGNED_BYTE, g_GpTankInx);

	glEnable(GL_COLOR_ARRAY);
	glEnable(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
}