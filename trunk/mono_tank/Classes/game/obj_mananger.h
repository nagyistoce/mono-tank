#ifndef generate_obj_h
#define generate_obj_h
#include <vector>
#include "game_define.h"

class CObj;

class CGenerateObjMananger
{
public:
	CGenerateObjMananger();	
	~CGenerateObjMananger();

public:
	void update(int nTick);

protected:
	std::vector<CObj*> m_vecObj;
};

#endif