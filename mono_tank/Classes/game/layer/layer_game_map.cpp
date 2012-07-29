#include "layer_game_map.h"

CLayerGameMap::CLayerGameMap()
{
}

CLayerGameMap::~CLayerGameMap()
{
}

CLayerGameMap *CLayerGameMap::instance()
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