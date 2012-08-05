#ifndef game_logic_h
#define game_logic_h

#include "game_define.h"

class CGameLogic
{
public: 
	enum State
	{
		eState_None = 0,
		eState_Menu,
		eState_Start,
		eState_Playing,
		eState_Pause,
		eState_GameOver,
	};

public:
	CGameLogic();
	~CGameLogic();

public:
	void resetGame();
	void update(float dt);
	void start(){ m_eState = eState_Start; }
	void setPause(bool bPause){ m_eState= bPause ? eState_Pause : eState_Playing; }

public:
	int getScore()const { return m_nScore; }
	State getState()const { return m_eState; }
	eMapValue getMapValue(int i,int j)const{ return m_nMap[i][j]; }

private:

	State m_eState;
	int m_nScore;
	eMapValue m_nMap[GRID_VERTICAL][GRID_HORIZON];
	int m_nTick;
};

#endif