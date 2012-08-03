#ifndef layer_game_object_h
#define layer_game_object_h

#include "head.h"

class CSpriteTank;
class CSpriteBullet;

class CLayerGameObject : public cocos2d::CCLayer
{
public:
	CSpriteTank *m_tank;
	CSpriteBullet *m_bullet;

public:
	CLayerGameObject();
	~CLayerGameObject();

	static CLayerGameObject *create();

	bool initLayerGameObject();

	bool touchBegan(cocos2d::CCPoint Point);
	bool touchMoved(cocos2d::CCPoint Point);
	bool touchEnded(cocos2d::CCPoint Point);
};

#endif