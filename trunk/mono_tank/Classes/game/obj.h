#ifndef obj_h
#define obj_h
#include <assert.h>

#include "game_define.h"
/*
00000
00000
00000
00000
00000
*/
class CObj
{
public:
	CObj()
	:m_byData(ARRAY_NONE)
	{
		
	}
	virtual ~CObj(){}
public:
	virtual eObj_Type GetType() { return eObj_Invalid; }
	virtual bool CheckCollision(int** Map, int w,int h)const
	{
		for(int i=0; i<GRID_OBJ_TILE; i++)
		{
			if(eMapValue_None!=m_byData[i])
			{
				int x = m_Pos.x+i/GRID_OBJ_SIDE;
				int y = m_Pos.y+i%GRID_OBJ_SIDE;
				if(x>=0 && x<w && y>=0 && y<h)
				{
					if(eMapValue_None!=Map[x][y])
					{
						return true;
					}
				}
			}
		}
		return false;
	}
public:
	byte GetData(int nIndex)const{ assert(nIndex>=0 && nIndex<GRID_OBJ_TILE ); return m_byData[nIndex]; }
	const MyPoint& GetPosition()const { return m_Pos; }
	void SetPosition(const MyPoint& pos){ m_Pos = pos; }
	void SetPosition(int x,int y){ m_Pos.x = x; m_Pos.y = y; }
protected:
	const byte* m_byData;
	MyPoint m_Pos;
};


class CObj_Barrier : public CObj
{
public:
	CObj_Barrier()
	{
		m_byData = ARRAY_TANK;
	}
	~CObj_Barrier(){}
	virtual eObj_Type GetType() { return eObj_Barrier; }
};
#endif