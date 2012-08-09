#include "obj_tank.h"
#include <memory.h>

CObj_Tank::CObj_Tank()
{
	m_byData = ARRAY_TANK;
}

CObj_Tank::~CObj_Tank()
{
}

bool CObj_Tank::CheckCollision(int** Map, int w,int h)const
{
	if( m_Invincible )
	{
		return false;
	}
	return CObj::CheckCollision(Map,w,h);
}