#ifndef layer_game_control_h
#define layer_game_control_h

#include "head.h"

class CLayerGameControl : public cocos2d::CCLayer
{
public:
	cocos2d::CCMenu *m_menu;
	cocos2d::CCMenuItemSprite *m_itemRight;

public:
	CLayerGameControl();
	virtual ~CLayerGameControl();

	static CLayerGameControl *instance();

	bool initLayerGameControl();

	virtual void draw();

	void callBackItemRight(CCObject *Object);
};

#endif