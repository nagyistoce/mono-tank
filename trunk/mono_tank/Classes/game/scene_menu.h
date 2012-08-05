#ifndef scene_menu_h
#define scene_menu_h

#include "head.h"

#include "game_define.h"

class CSceneMenu : public cocos2d::CCLayer
{

public:
	CSceneMenu();
	~CSceneMenu();
public:
	virtual void onEnter();
	virtual void onExit();	

public:
	void menuCallbackStart(cocos2d::CCObject* pSender);

private:
	cocos2d::CCMenuItemImage *m_pBtnStart;
};

#endif