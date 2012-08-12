#ifndef obj_tank_h
#define obj_tank_h

#include "obj.h"

class CObj_Tank : public CObj
{
	AUTO_OBJ_CLASS(Tank)

public:
	virtual bool CheckCollision(const CObj& obj)const;
	
	PRIVATE_PROPERTY(bool,Invincible);
	PRIVATE_PROPERTY(bool,Live);
};

#endif