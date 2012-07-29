#ifndef layer_map_h
#define layer_map_h

#include "head.h"

class CLayerGameMap : public cocos2d::CCLayer
{
public:

public:
	CLayerGameMap();
	~CLayerGameMap();

	static CLayerGameMap *instance();

	bool initLayerGameMap();
};

#endif