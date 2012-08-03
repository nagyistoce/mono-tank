#ifndef scene_game_h
#define scene_game_h

#include "head.h"
#include "layer_game_map.h"
#include "layer_game_object.h"
#include "layer_dialog.h"
#include "layer_game_touch.h"
#include "layer_game_control.h"

class CSceneGame : public cocos2d::CCScene
{
public:
	CLayerGameMap *m_layerMap;
	CLayerGameObject *m_layerObject;
	CLayerDialog *m_layerDialog;
	CLayerGameTouch *m_layerTouch;
	CLayerGameControl *m_layerControl;

public:
	CSceneGame();
	~CSceneGame();

	static CSceneGame *create();

	bool initSceneGame();
};

#endif