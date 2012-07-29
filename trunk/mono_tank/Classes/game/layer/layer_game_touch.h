#ifndef layer_game_touch_h
#define layer_game_touch_h

#include "head.h"

class CLayerGameTouch : public cocos2d::CCLayer
{
public:
	CLayerGameTouch();
	virtual ~CLayerGameTouch();

	static CLayerGameTouch *instance();

	virtual bool initLayerGameTouch();
	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	cocos2d::CCPoint getTouchPoint(cocos2d::CCTouch *Touch);
};

#endif