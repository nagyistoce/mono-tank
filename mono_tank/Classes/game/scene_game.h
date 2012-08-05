#ifndef scene_game_h
#define scene_game_h

#include "head.h"
#include "layer_game_map.h"
#include "layer_game_object.h"
#include "layer_dialog.h"
#include "layer_game_touch.h"
#include "layer_game_control.h"

#include "game_define.h"

class CGameLogic;
class CSceneGame : public cocos2d::CCLayer
{

public:
	CSceneGame();
	~CSceneGame();
public:
	
	virtual void onEnter();
	virtual void onExit();
	
public:
	static CSceneGame *create(const CGameLogic* pGameLogic);
	bool initSceneGame(const CGameLogic* pGameLogic);

private:
	void refresh(float dt);
	
public:
	CLayerGameMap *m_layerMap;
	CLayerGameObject *m_layerObject;
	CLayerDialog *m_layerDialog;
	CLayerGameTouch *m_layerTouch;
	CLayerGameControl *m_layerControl;

	const CGameLogic *m_pGameLogic;
	cocos2d::CCLabelTTF*	m_labelScore;
};

#endif