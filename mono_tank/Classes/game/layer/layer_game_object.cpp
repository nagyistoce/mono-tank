#include "layer_game_object.h"

#include "scene_game.h"
#include "layer_dialog.h"
#include "sprite_tank.h"
#include "sprite_bullet.h"
#include "sprite_dlg_mission_start.h"

CLayerGameObject::CLayerGameObject()
{

}

CLayerGameObject::~CLayerGameObject()
{

}

CLayerGameObject *CLayerGameObject::create()
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
		dialog = CSpriteDlgMissionStart::create();
		g_SceneGame->m_layerDialog->runDialog(dialog);

		m_tank = CSpriteTank::create();
		addChild(m_tank);
		m_tank->setPositionInPixels(g_ScrrenCenter);
		m_tank->setColor(cocos2d::ccBLACK);

		m_bullet = CSpriteBullet::create();
		addChild(m_bullet);
		m_bullet->setPositionInPixels(cocos2d::CCPointMake(g_ScrrenCenter.x, 150.0f));
		m_bullet->setColor(cocos2d::ccBLACK);

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