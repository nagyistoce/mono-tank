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
	m_nDistance = 0;
	m_nTick = 0;

	m_ObjMgr.reset();
	for(int i=0; i<GRID_HORIZON; i++)
	{
		m_ObjMgr.update();
	}

	m_pTank->SetActive(true);
	m_pTank->SetPosition(TANK_INIT_POS_X,TANK_INIT_POS_Y);

}
void CGameLogic::clearMap()
{
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

	clearMap();
	
	if( eState_Playing==m_eState )
	{
		if( 0==m_nTick%60 )
		{
			m_ObjMgr.update();
			m_nDistance+=1;

			for(int i=0; i<m_ObjMgr.GetObjCount(); i++)
			{
				const CObj* pObj = m_ObjMgr.GetObj(i);
				if( m_pTank->CheckCollision(*pObj) )
				{
					m_ObjMgr.GetObj(i)->SetActive(false);
				}
			}
		}
		for(int i=0; i<m_ObjMgr.GetObjCount(); i++)
		{
			const CObj* pObj = m_ObjMgr.GetObj(i);
			if( !pObj->GetActive() )
			{
				continue;
			}
			if( m_pTank->CheckCollision(*pObj) )
			{
				m_ObjMgr.GetObj(i)->SetActive(false);

			}

			for(int i=0; i<GRID_OBJ_TILE; i++)
			{
				eMapValue value = (eMapValue)pObj->GetData(i);
				if( eMapValue_None==value )
				{
					continue;
				}
				int x = pObj->GetPosition().x+i%GRID_OBJ_SIDE;
				int y = pObj->GetPosition().y+i/GRID_OBJ_SIDE;
				if( x<0 || x>=GRID_VERTICAL || y<0 || y>=GRID_HORIZON )
				{
					continue;
				}
				m_nMap[x][y] = value;
			}
		}

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


	}

	
	m_nTick+=1;

}
void CGameLogic::Move(const MyPoint& pt)
{
	if( m_pTank )
	{
		MyPoint p(m_pTank->GetPosition());
		m_pTank->SetPosition(p+pt);
	}
}
