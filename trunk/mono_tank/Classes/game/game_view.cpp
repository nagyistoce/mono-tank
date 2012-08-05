#include "game_view.h"

#include "graphic.h"
#include "game_logic.h"
#include "scene_menu.h"
#include "scene_game.h"

using namespace cocos2d;

CGameView::CGameView()
{
	m_layerCurrent = 0;
}

CGameView::~CGameView()
{
}

CGameView *CGameView::create(const CGameLogic* pGameLogic)
{
	CGameView *instance;

	instance = new CGameView;
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

bool CGameView::initSceneGame(const CGameLogic* pGameLogic)
{
	m_pGameLogic = pGameLogic;

	return true;

}

void CGameView::onEnter()
{
	CCLayer::onEnter();
	
	CCLayerColor* bkg = CCLayerColor::layerWithColorWidthHeight(ccc4(166,166,166,255),WINDOW_WIDTH,WINDOW_HEIGHT);
	bkg->setAnchorPoint(ccp(0,1));
	bkg->setPositionInPixels(ccp(0,0));
	addChild(bkg);

	static const int OffsetX = WINDOW_WIDTH/GRID_VERTICAL;
	static const int OffsetY = WINDOW_HEIGHT/GRID_HORIZON;
	for(int i=0; i<GRID_VERTICAL*GRID_HORIZON; i++)
	{
		
		m_Map[i] = CCSprite::spriteWithFile("Rect.png");
		m_Map[i]->setPositionInPixels(ccp(i%GRID_VERTICAL*OffsetX,i/GRID_VERTICAL*OffsetY));
		/*
		m_Map[i] = CCLayerColor::layerWithColorWidthHeight(ccc4(0,0,0,255),OffsetX,OffsetY);
		*/
		m_Map[i]->setColor(ccc3(0,0,0));
		m_Map[i]->setAnchorPoint(ccp(0,1));
		m_Map[i]->setPositionInPixels(ccp(i%GRID_VERTICAL*OffsetX,WINDOW_HEIGHT-i/GRID_VERTICAL*OffsetY));
		m_Map[i]->setScaleX(OffsetX/m_Map[i]->getTextureRect().size.width);
		m_Map[i]->setScaleY(OffsetY/m_Map[i]->getTextureRect().size.height);
		addChild(m_Map[i]);
	}

	refresh();
}

void CGameView::replaceWithLayer(cocos2d::CCLayer* pLayer)
{
	if( m_layerCurrent )
	{
		removeChild( m_layerCurrent, true );
	}
	m_layerCurrent = pLayer;
	addChild(m_layerCurrent);
}
void CGameView::enterMenu()
{
	replaceWithLayer(new CSceneMenu());
}
void CGameView::enterPlay()
{
	replaceWithLayer(CSceneGame::create(m_pGameLogic));
}

void CGameView::onExit()
{
	CCLayer::onExit();
}

void CGameView::refresh()
{
	for(int i=0; i<GRID_VERTICAL*GRID_HORIZON; i++)
	{
		if( eMapValue_Rect==m_pGameLogic->getMapValue(i%GRID_VERTICAL,i/GRID_VERTICAL) )
		{
			m_Map[i]->setIsVisible(true);
		}
		else
		{
			m_Map[i]->setIsVisible(false);
		}
	}
	
}
