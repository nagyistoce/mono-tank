#ifndef obj_mananger_h
#define obj_mananger_h
#include <vector>
#include "game_define.h"

class CObj;

struct Generate
{
	int next,type,pos;
};

class CObjMananger
{
public:
	CObjMananger();	
	~CObjMananger();

public:
	void reset();
	void update();
	int GetObjCount()const{ return (int)m_vecObj.size(); }
	const CObj* GetObj(int index)const{ return m_vecObj[index]; }
	CObj* GetObj(int index){ return m_vecObj[index]; }
private:
	std::vector<CObj*> m_vecObj;
	static const Generate	m_ObjArray[];
	int m_nTickCount;
	int m_nNextTick;

	int m_nObjArrayCount;
	int m_nCurrentIndex;
};

#endif