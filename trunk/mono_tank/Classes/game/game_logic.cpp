#include "game_logic.h"
#include <stdlib.h>
#include <math.h>

CGameLogic::CGameLogic()
{
}

CGameLogic::~CGameLogic()
{
}

void CGameLogic::resetGame()
{
	m_nScore = 0;
	m_nTick = 0;

	for(int i=0; i<GRID_VERTICAL; i++)
	{
		for(int j=0; j<GRID_HORIZON; j++)
		{
			m_nMap[i][j] = eMapValue_None;
		}
	}
}

void CGameLogic::update(float dt)
{
	switch(m_eState)
	{
	case eState_Menu:
		{
		}
		break;
	case eState_Start:
		{
			resetGame();
			m_eState = eState_Playing;
			return;
		}
		break;
	case eState_Playing:
		{
		}
		break;
	case eState_Pause:
		{
			return;
		}
		break;
	case eState_GameOver:
		{
		}
		break;
	case eState_None:
	default:
		return;
		break;
	}

	m_nTick+=1;

	if( 0==m_nTick%60 )
	{
		for(int i=0; i<GRID_VERTICAL; i++)
		{
			for(int j=0; j<GRID_HORIZON; j++)
			{
				m_nMap[i][j] = eMapValue_None;
			}
		}
	
		if( eState_Playing==m_eState )
		{
			for(int i=0; i<10; i++)
			{
				m_nMap[rand()%GRID_VERTICAL][rand()%GRID_HORIZON] = eMapValue_Rect;
			}
		}

		m_nScore+=10;
	}

	
}