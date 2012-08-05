#ifndef game_controller_h
#define game_controller_h

#include "scene_game.h"
#include "game_define.h"


enum eEvent
{
	eEvent_Btn_begin = 0,
	eEvent_Btn_StartGame,
	eEvent_Btn_PauseGame,
	eEvent_Btn_ResumeGame,
	eEvent_Btn_end = 100,

	eEvent_Num
};


#define DISPATCH_EVENT(event) CGameController::instance()->dispatchEvent(event)

class CGameLogic;
class CGameView;

class CGameController : public cocos2d::CCScene
{


public:
	CGameController();
	~CGameController();

public:
	virtual void onEnter();
	virtual void onExit();

public:
	static CGameController* instance();

	void dispatchEvent(eEvent event);

	bool initGameController();
	void loop(float dt);
	
private:
	CGameView *m_pView;
	CGameLogic *m_pLogic;
};

#endif