#include "layer_game_touch.h"

#include "scene_game.h"
#include "layer_game_object.h"
#include "layer_dialog.h"

CLayerGameTouch::CLayerGameTouch()
{

}

CLayerGameTouch::~CLayerGameTouch()
{

}

CLayerGameTouch *CLayerGameTouch::create()
{
	CLayerGameTouch *instance;

	instance = new CLayerGameTouch();
	if (instance->initLayerGameTouch())
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

bool CLayerGameTouch::initLayerGameTouch()
{
	if (cocos2d::CCLayer::init())
	{
		setIsTouchEnabled(true);
		return true;
	}
	else
	{
		return false;
	}
}

void CLayerGameTouch::registerWithTouchDispatcher()
{
	cocos2d::CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, INT_MIN+1, true);
}

/*if layer return false stop passing touch event
*/

bool CLayerGameTouch::ccTouchBegan(cocos2d::CCTouch *Touch, cocos2d::CCEvent *Event)
{
	cocos2d::CCPoint point;

	point = getTouchPoint(Touch);
	if (false == g_SceneGame->m_layerDialog->touchBegan(point))
	{
		goto RET_;
	}
	if (false == g_SceneGame->m_layerObject->touchBegan(point))
	{
		goto RET_;
	}

RET_:
	return true;
}

void CLayerGameTouch::ccTouchMoved(cocos2d::CCTouch *Touch, cocos2d::CCEvent *Event)
{
	cocos2d::CCPoint point;

	point = getTouchPoint(Touch);
	if (false == g_SceneGame->m_layerDialog->touchMoved(point))
	{
		return;
	}
	if (false == g_SceneGame->m_layerObject->touchMoved(point))
	{
		return;
	}
}

void CLayerGameTouch::ccTouchEnded(cocos2d::CCTouch *Touch, cocos2d::CCEvent *Event)
{
	cocos2d::CCPoint point;

	point = getTouchPoint(Touch);
	if (false == g_SceneGame->m_layerDialog->touchEnded(point))
	{
		return;
	}
	if (false == g_SceneGame->m_layerObject->touchEnded(point))
	{
		return;
	}
}

void CLayerGameTouch::ccTouchCancelled(cocos2d::CCTouch *Touch, cocos2d::CCEvent *Event)
{
	cocos2d::CCPoint point;

	point = getTouchPoint(Touch);
}

cocos2d::CCPoint CLayerGameTouch::getTouchPoint(cocos2d::CCTouch *Touch)
{
	cocos2d::CCPoint point;

	point = convertTouchToNodeSpace(Touch);
	return point;
}
