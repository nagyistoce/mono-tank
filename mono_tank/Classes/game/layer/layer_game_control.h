#ifndef layer_game_control_h
#define layer_game_control_h

#include "head.h"

class CLayerGameControl : public cocos2d::CCLayer
{
public:

public:
	CLayerGameControl();
	virtual ~CLayerGameControl();

	static CLayerGameControl *create();

	bool initLayerGameControl();
	virtual void draw();
};

#endif