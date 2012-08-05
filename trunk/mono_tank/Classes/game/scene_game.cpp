#include "scene_game.h"

#include "graphic.h"
#include "game_logic.h"

#define SCENE_GAME_LAYER_MAP_Z 0
#define SCENE_GAME_LAYER_OBJECT_Z 1
#define SCENE_GAME_LAYER_DIALOG_Z 2
#define SCENE_GAME_LAYER_TOUCH_Z 3
#define SCENE_GAME_LAYER_CONTROL_Z 4

using namespace cocos2d;

CSceneGame::CSceneGame()
{
}

CSceneGame::~CSceneGame()
{
}

CSceneGame *CSceneGame::create(const CGameLogic* pGameLogic)
{
	CSceneGame *instance;

	instance = new CSceneGame;
	if (instance->initSceneGame(pGameLogic))
	{
		instance->autorelease();
		return instance;
	}
	else
	{
		instance->release();
		return false;
	}
}

bool CSceneGame::initSceneGame(const CGameLogic* pGameLogic)
{
	//if (cocos2d::CCScene::init())
	{
		g_SceneGame = this;

		

		m_pGameLogic = pGameLogic;

		return true;
	}
	//else
	{
		return false;
	}
}

/*
void CSceneGame::RenderRect(cocos2d::CCPoint point, cocos2d::CCSize size,cocos2d::ccColor4B color)
{
	point.y -= WINDOW_HEIGHT;

	float _Top, _Bottom, _Left, _Right;
	GLfloat _VertexArray[8];
	GLubyte _IndexArray[] = {0, 1, 2, 2, 3, 0};

	_Top = point.y + size.height;
	_Bottom = point.y - size.height;
	_Left = point.x - size.width;
	_Right = point.x + size.width;

	_VertexArray[0] = _Left; _VertexArray[1] = _Bottom;
	_VertexArray[2] = _Right; _VertexArray[3] = _Bottom;
	_VertexArray[4] = _Right; _VertexArray[5] = _Top;
	_VertexArray[6] = _Left; _VertexArray[7] = _Top;

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	glColor4ub(color.r, color.g, color.b, color.a);
	glVertexPointer(2, GL_FLOAT, 0, _VertexArray);
	glDrawElements(GL_TRIANGLES, sizeof _IndexArray, GL_UNSIGNED_BYTE, _IndexArray);

	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
}
*/

void CSceneGame::onEnter()
{
	m_layerControl = CLayerGameControl::create();
		addChild(m_layerControl, SCENE_GAME_LAYER_CONTROL_Z);
		m_layerControl->setPositionInPixels(cocos2d::CCPointZero);

		m_layerTouch = CLayerGameTouch::create();
		addChild(m_layerTouch, SCENE_GAME_LAYER_TOUCH_Z);
		m_layerTouch->setPositionInPixels(cocos2d::CCPointZero);

		//m_layerDialog = CLayerDialog::create();
		//addChild(m_layerDialog, SCENE_GAME_LAYER_DIALOG_Z);
		//m_layerDialog->setPositionInPixels(g_ScrrenCenter.x, g_ScrrenCenter.y);

		//m_layerObject = CLayerGameObject::create();
		//addChild(m_layerObject, SCENE_GAME_LAYER_OBJECT_Z);
		//m_layerObject->setPositionInPixels(cocos2d::CCPointZero);

		//m_layerMap = CLayerGameMap::create();
		//addChild(m_layerMap, SCENE_GAME_LAYER_MAP_Z);
		//m_layerMap->setPositionInPixels(cocos2d::CCPointZero);

	m_labelScore = CCLabelTTF::labelWithString("", "Arial", 24);
	m_labelScore->setAnchorPoint(ccp(0,1));
	m_labelScore->setPositionInPixels(ccp(0,WINDOW_HEIGHT));
	addChild(m_labelScore,SCENE_GAME_LAYER_CONTROL_Z);

	schedule(schedule_selector(CSceneGame::refresh));
	CCLayer::onEnter();

}

void CSceneGame::onExit()
{
	CCLayer::onExit();
}

void CSceneGame::refresh(float dt)
{
	char szScore[64] = {0};
	sprintf(szScore,"Score:%d",m_pGameLogic->getScore());
	m_labelScore->setString(szScore);
	
	CCLayer::update(dt);
}
