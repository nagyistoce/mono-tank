#include <vector>
#include "obj_mananger.h"

#include "obj.h"

#define FOR_EACH_BEGIN(obj)\
for(uint i=0; i<m_vecObj.size(); i++)\
{\
	CObj* obj = m_vecObj[i];

#define FOR_EACH_END	}

//tick,type,posX
const Generate CObjMananger::m_ObjArray[] = 
{
	{0,1,1},
	{0,1,-2},
	{4,1,0},
	{0,1,-1},
	{4,1,0},
	{0,1,-1},
	{1,3,1},
	{4,1,0},
	{0,1,-1},
	{4,1,0},
	{0,1,-1},
	{1,2,-2},
	{4,1,0},
	{0,1,-1},
	{4,1,0},
	{0,1,-1},
	{2,3,3},
	{4,1,0},
	{0,1,-1},
	{4,1,0},
	{0,1,-1},
	{4,1,0},
	{0,1,-1},
	{2,4,-5},
	{4,1,0},
	{0,1,-1},
	{4,1,0},
	{0,1,-1},
	{2,3,-6},
	{4,1,0},
	{0,1,-1},
	{4,1,0},
	{0,1,-1},
	{3,4,5},
	{4,1,0},
	{0,1,-1},
	{4,1,0},
	{0,1,-1},
	{4,1,0},
	{0,1,-1},
};

CObjMananger::CObjMananger()
{
	static int MaxObj = 20;
	for(int i=0; i<MaxObj; i++)
	{
		CObj* pObj = new CObj_Barrier_1();
		m_vecObj.push_back(pObj);
	}
	for(int i=0; i<MaxObj; i++)
	{
		CObj* pObj = new CObj_Barrier_2();
		m_vecObj.push_back(pObj);
	}
	for(int i=0; i<MaxObj; i++)
	{
		CObj* pObj = new CObj_Block_1();
		m_vecObj.push_back(pObj);
	}
	for(int i=0; i<MaxObj; i++)
	{
		CObj* pObj = new CObj_Block_2();
		m_vecObj.push_back(pObj);
	}
	for(int i=0; i<MaxObj; i++)
	{
		CObj* pObj = new CObj_Block_3();
		m_vecObj.push_back(pObj);
	}

	m_nObjArrayCount = sizeof(m_ObjArray)/sizeof(Generate);
}
CObjMananger::~CObjMananger()
{
	FOR_EACH_BEGIN(pObj)
		SAFE_DELETE(pObj);
	FOR_EACH_END

	m_vecObj.clear();
}

void CObjMananger::reset()
{
	FOR_EACH_BEGIN(pObj)
		(pObj)->SetActive(false);
	FOR_EACH_END

	m_nTickCount = 0;
	m_nNextTick = m_nTickCount;
	m_nCurrentIndex = 0;

	m_nNextTick = m_nTickCount+m_ObjArray[m_nCurrentIndex].next;
}

void CObjMananger::update()
{
	//move
	FOR_EACH_BEGIN(pObj)
		if( pObj->GetActive() )
		{
			pObj->SetPosition(pObj->GetPosition().x,pObj->GetPosition().y+1);
		}
	FOR_EACH_END

	//generate
	while(m_nTickCount==m_nNextTick)
	{
		FOR_EACH_BEGIN(pObj)
			if( !pObj->GetActive() && m_ObjArray[m_nCurrentIndex].type==pObj->GetType() )
			{
				pObj->SetActive(true);

				int x = m_ObjArray[m_nCurrentIndex].pos;
				x += x<0 ? GRID_VERTICAL : 0;
				int y = -GRID_OBJ_SIDE;
				
				pObj->SetPosition(x,y);

				break;
			}
		FOR_EACH_END
		
		//recycle
		m_nCurrentIndex++;
		if(m_nCurrentIndex>=m_nObjArrayCount)
		{
			m_nCurrentIndex = 0;
		}
		m_nNextTick = m_nTickCount+m_ObjArray[m_nCurrentIndex].next;
		
	}

	//clear objs which have been out of view
	FOR_EACH_BEGIN(pObj)
		if( pObj->GetActive() )
		{
			int j=0;
			for(; j<GRID_OBJ_TILE; j++)
			{
				if( eMapValue_None!=pObj->GetData(j) )
				{
					int y = pObj->GetPosition().y+j/GRID_OBJ_SIDE;
					if( y<GRID_HORIZON)
					{
						break;
					}
				}
			}
			if(j>=GRID_OBJ_TILE)
			{
				pObj->SetActive(false);
			}
		}
	FOR_EACH_END


	m_nTickCount++;
}

