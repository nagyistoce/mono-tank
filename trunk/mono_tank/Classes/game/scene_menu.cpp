#include "scene_menu.h"
#include "game_controller.h"

using namespace cocos2d;

CSceneMenu::CSceneMenu()
{
}

CSceneMenu::~CSceneMenu()
{
}

void CSceneMenu::onEnter()
{
	CCLayer::onEnter();
	
	m_pBtnStart = CCMenuItemImage::itemFromNormalImage(
										"btn-play-normal.png",
										"btn-play-selected.png",
										this,
										menu_selector(CSceneMenu::menuCallbackStart) );
	CCMenu* pMenu = CCMenu::menuWithItems(m_pBtnStart, NULL);
	pMenu->setPosition( ccp(WINDOW_WIDTH/2,WINDOW_HEIGHT/2) );
	this->addChild(pMenu, 1);
}

void CSceneMenu::onExit()
{
	CCLayer::onExit();
}

void CSceneMenu::menuCallbackStart(CCObject* pSender)
{
	DISPATCH_EVENT(eEvent_Btn_StartGame);
	
}