#ifndef layer_game_object_h
#define layer_game_object_h

#include "head.h"
#include "sprite_player.h"

class CLayerGameObject : public cocos2d::CCLayer
{
public:
	CSpritePlayer *m_player;

public:
	CLayerGameObject();
	~CLayerGameObject();

	static CLayerGameObject *instance();

	bool initLayerGameObject();

	bool touchBegan(cocos2d::CCPoint Point);
	bool touchMoved(cocos2d::CCPoint Point);
	bool touchEnded(cocos2d::CCPoint Point);
};

#endif