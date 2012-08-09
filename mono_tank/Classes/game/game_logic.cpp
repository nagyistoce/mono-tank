#include <stdlib.h>
#include <math.h>

#include "game_logic.h"
#include "obj_tank.h"

CGameLogic::CGameLogic()
{
	m_pTank = new CObj_Tank();
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
			for(int i=0; i<GRID_OBJ_TILE; i++)
			{
				eMapValue value = (eMapValue)m_pTank->GetData(i);
				if( eMapValue_None==value )
				{
					continue;
				}
				int x = m_pTank->GetPosition().x+i%GRID_OBJ_SIDE;
				int y = m_pTank->GetPosition().y+i/GRID_OBJ_SIDE;
				if( x<0 || x>=GRID_VERTICAL || y<0 || y>=GRID_HORIZON )
				{
					continue;
				}
				m_nMap[x][y] = value;
			}
			/*
			for(int i=0; i<10; i++)
			{
				m_nMap[rand()%GRID_VERTICAL][rand()%GRID_HORIZON] = eMapValue_Rect;
			}
			*/
		}

		m_nScore+=10;
	}

	
}