#ifndef sprite_bullet_h
#define sprite_bullet_h

#include "head.h"

class CSpriteBullet : public cocos2d::CCSprite
{
public:

public:
	CSpriteBullet();
	virtual ~CSpriteBullet();

	static CSpriteBullet *create();

	bool initSpriteBullet();
	virtual void draw();
};

#endif