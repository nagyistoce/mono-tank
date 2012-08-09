#ifndef game_view_h
#define game_view_h

#include "head.h"
#include "game_define.h"

class CGameLogic;
class CGameView : public cocos2d::CCLayer
{

public:
	CGameView();
	~CGameView();
public:
	virtual void onEnter();
	virtual void onExit();
	
public:
	static CGameView *create(const CGameLogic* pGameLogic);
	bool initSceneGame(const CGameLogic* pGameLogic);
	
public:
	void refresh();
	void enterMenu();
	void enterPlay();
private:
	void replaceWithLayer(cocos2d::CCLayer* pLayer);

private:

	const CGameLogic *m_pGameLogic;
	cocos2d::CCSprite*		m_Map[GRID_VERTICAL*GRID_HORIZON];
	

	cocos2d::CCLayer*		m_layerCurrent;
};

#endif