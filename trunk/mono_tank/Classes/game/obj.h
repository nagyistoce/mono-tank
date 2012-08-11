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
	virtual bool CheckCollision(const CObj& obj)const
	{
		for(int i=0; i<GRID_OBJ_TILE; i++)
		{
			if(eMapValue_None==m_byData[i])
			{
				continue;
			}
			int x1 = m_Pos.x+i/GRID_OBJ_SIDE;
			int y1 = m_Pos.y+i%GRID_OBJ_SIDE;

			for(int j=0; i<GRID_OBJ_TILE; j++)
			{
				if(eMapValue_None==obj.GetData(i))
				{
					continue;
				}

				int x2 = obj.GetPosition().x+j/GRID_OBJ_SIDE;
				int y2 = obj.GetPosition().y+j%GRID_OBJ_SIDE;
				if( x1==x2 && y1==y2 )
				{
					return true;
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
	PRIVATE_PROPERTY(bool,Active)
};


class CObj_Barrier : public CObj
{
public:
	CObj_Barrier()
	{
		m_byData = ARRAY_BARRIER;
	}
	~CObj_Barrier(){}
	virtual eObj_Type GetType() { return eObj_Barrier; }
};
#endif