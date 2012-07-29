#include "layer_game_control.h"

#include "sprite_ctrl_right_normal.h"
#include "sprite_ctrl_right_selected.h"

CLayerGameControl::CLayerGameControl()
{

}

CLayerGameControl::~CLayerGameControl()
{

}

CLayerGameControl *CLayerGameControl::instance()
{
	CLayerGameControl *instance;

	instance = new CLayerGameControl();
	if (instance->initLayerGameControl())
	{
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
		m_itemRight = cocos2d::CCMenuItemSprite::itemFromNormalSprite(
			CSpriteCtrlRightNormal::instance(),
			CSpriteCtrlRightSelected::instance(),
			this,
			cocos2d::SEL_MenuHandler(&CLayerGameControl::callBackItemRight));
		m_itemRight->setPositionInPixels(g_ScrrenSize.width - 35.0f, 20.0f);

		m_menu = cocos2d::CCMenu::menuWithItems(m_itemRight, NULL);
		m_menu->setPositionInPixels(0.0f, 0.0f);

		addChild(m_menu);

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

void CLayerGameControl::callBackItemRight(CCObject *Object)
{
	printf("call back item right\n");
}