#include "layer_game_map.h"

CLayerGameMap::CLayerGameMap()
{
}

CLayerGameMap::~CLayerGameMap()
{
}

CLayerGameMap *CLayerGameMap::create()
{
	CLayerGameMap *instance;

	instance = new CLayerGameMap;
	if (instance->initLayerGameMap())
	{
		return instance;
	}
	else
	{
		instance->release();
		return NULL;
	}
}

bool CLayerGameMap::initLayerGameMap()
{
	if (cocos2d::CCLayer::init())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CLayerGameMap::draw()
{
	cocos2d::CCRect rect;

	rect.origin = cocos2d::CCPointZero;
	rect.size = g_ScrrenSize;

	glColor4ub(cocos2d::ccGRAY.r, cocos2d::ccGRAY.g, cocos2d::ccGRAY.b, 255);
	tgeoDrawRect(rect);
}