#ifndef sprite_tank_h
#define sprite_tank_h

#include "head.h"

class CSpriteTank : public cocos2d::CCSprite
{
public:
	CSpriteTank();
	virtual ~CSpriteTank();

	static CSpriteTank *create();

	bool initSpriteTank();
	virtual void draw();
};

#endif