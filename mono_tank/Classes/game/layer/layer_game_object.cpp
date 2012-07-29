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