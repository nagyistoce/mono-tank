#include "layer_game_control.h"

CLayerGameControl::CLayerGameControl()
{

}

CLayerGameControl::~CLayerGameControl()
{

}

CLayerGameControl *CLayerGameControl::create()
{
	CLayerGameControl *instance;

	instance = new CLayerGameControl();
	if (instance->initLayerGameControl())
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

bool CLayerGameControl::initLayerGameControl()
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

void CLayerGameControl::draw()
{
	glColor4ub(255, 255, 255, 255);
	glLineWidth(2.0f);
	tgeoDrawLine(cocos2d::CCPointMake(0.0f, 50.0f), cocos2d::CCPointMake(g_ScrrenSize.width, 50.0f));
	tgeoDrawLine(cocos2d::CCPointMake(0.0f, 46.0f), cocos2d::CCPointMake(g_ScrrenSize.width, 46.0f));
}