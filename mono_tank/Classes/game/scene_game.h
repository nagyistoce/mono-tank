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
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

public:
	static CSceneGame *create(const CGameLogic* pGameLogic);
	bool initSceneGame(const CGameLogic* pGameLogic);

private:
	void refresh(float dt);
	void menuCallbackPause(cocos2d::CCObject* pSender);

private:
	CLayerGameMap *m_layerMap;

	const CGameLogic *m_pGameLogic;
	cocos2d::CCLabelTTF*	m_labelScore;


};

#endif