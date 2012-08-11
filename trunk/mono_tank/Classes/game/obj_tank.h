#ifndef obj_tank_h
#define obj_tank_h

#include "obj.h"

class CObj_Tank : public CObj
{
public:
	CObj_Tank();
	virtual ~CObj_Tank();
public:
	virtual eObj_Type GetType() { return eObj_Tank; }
	virtual bool CheckCollision(const CObj& obj)const;
	
	PRIVATE_PROPERTY(bool,Invincible);
	PRIVATE_PROPERTY(bool,Live);
};

#endif