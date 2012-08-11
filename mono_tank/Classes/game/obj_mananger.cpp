#include <vector>
#include "obj_mananger.h"

#include "obj.h"

CGenerateObjMananger::CGenerateObjMananger()
{
	static int MaxObj = 10;
	for(int i=0; i<MaxObj; i++)
	{
		CObj* pObj = new CObj_Barrier();
		m_vecObj.push_back(pObj);
	}
	
}
CGenerateObjMananger::~CGenerateObjMananger()
{
}

void CGenerateObjMananger::update(int nTick)
{
}

