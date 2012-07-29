#include "scene_game.h"

#define SCENE_GAME_LAYER_MAP_Z 0
#define SCENE_GAME_LAYER_OBJECT_Z 1
#define SCENE_GAME_LAYER_DIALOG_Z 2
#define SCENE_GAME_LAYER_TOUCH_Z 3
#define SCENE_GAME_LAYER_CONTROL_Z 4

CSceneGame::CSceneGame()
{
}

CSceneGame::~CSceneGame()
{
}

CSceneGame *CSceneGame::instance()
{
	CSceneGame *instance;

	instance = new CSceneGame;
	if (instance->initSceneGame())
	{
		return instance;
	}
	else
	{
		instance->release();
		return false;
	}
}

bool CSceneGame::initSceneGame()
{
	if (cocos2d::CCScene::init())
	{
		g_SceneGame = this;

		m_layerControl = CLayerGameControl::instance();
		addChild(m_layerControl, SCENE_GAME_LAYER_CONTROL_Z);
		m_layerControl->release();
		m_layerControl->setPositionInPixels(cocos2d::CCPointZero);

		m_layerTouch = CLayerGameTouch::instance();
		addChild(m_layerTouch, SCENE_GAME_LAYER_TOUCH_Z);
		m_layerTouch->release();
		m_layerTouch->setPositionInPixels(cocos2d::CCPointZero);

		m_layerDialog = CLayerDialog::instance();
		addChild(m_layerDialog, SCENE_GAME_LAYER_DIALOG_Z);
		m_layerDialog->release();
		m_layerDialog->setPositionInPixels(g_ScrrenCenter.x, g_ScrrenCenter.y);

		m_layerObject = CLayerGameObject::instance();
		addChild(m_layerObject, SCENE_GAME_LAYER_OBJECT_Z);
		m_layerObject->release();
		m_layerObject->setPositionInPixels(cocos2d::CCPointZero);

		m_layerMap = CLayerGameMap::instance();
		addChild(m_layerMap, SCENE_GAME_LAYER_MAP_Z);
		m_layerMap->release();
		m_layerMap->setPositionInPixels(cocos2d::CCPointZero);

		return true;
	}
	else
	{
		return false;
	}
}