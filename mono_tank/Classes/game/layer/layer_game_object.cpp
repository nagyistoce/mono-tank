#include "layer_game_object.h"

#include "scene_game.h"
#include "layer_dialog.h"
#include "sprite_dlg_mission_start.h"

CLayerGameObject::CLayerGameObject()
{

}

CLayerGameObject::~CLayerGameObject()
{

}

CLayerGameObject *CLayerGameObject::instance()
{
	CLayerGameObject *instance;

	instance = new CLayerGameObject;
	if (instance->initLayerGameObject())
	{
		return instance;
	}
	else
	{
		instance->release();
		return NULL;
	}
}

bool CLayerGameObject::initLayerGameObject()
{
	CSpriteDlgMissionStart *dialog;

	if (cocos2d::CCLayer::init())
	{
		dialog = CSpriteDlgMissionStart::instance();
		g_SceneGame->m_layerDialog->runDialog(dialog);

		m_player = new CSpritePlayer;
		m_player->initSpritePlayer();
		addChild(m_player);
		m_player->release();
		m_player->setPositionInPixels(cocos2d::CCPointMake(g_ScrrenCenter.x, 50.0f));
		m_player->setRotation(30.0f);
		//m_player->setAnchorPoint(cocos2d::CCPointMake(0.5f, 0.0f));

		return true;
	}
	else
	{
		return false;
	}
}

bool CLayerGameObject::touchBegan(cocos2d::CCPoint Point)
{
	return true;
}

bool CLayerGameObject::touchMoved(cocos2d::CCPoint Point)
{
	return true;
}

bool CLayerGameObject::touchEnded(cocos2d::CCPoint Point)
{
	return true;
}