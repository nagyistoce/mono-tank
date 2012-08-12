#ifndef game_define_h
#define game_define_h

typedef unsigned char byte;
typedef unsigned int  uint;

#define SAFE_DELETE(p) if(p){ delete (p); p=0; }

#define WINDOW_WIDTH	320
#define WINDOW_HEIGHT	480

#define GRID_VERTICAL	16
#define GRID_HORIZON	24

#define GRID_OBJ_SIDE		5
#define GRID_OBJ_TILE		(GRID_OBJ_SIDE*GRID_OBJ_SIDE)

#define TANK_INIT_POS_X	(GRID_VERTICAL-GRID_OBJ_SIDE)/2
#define TANK_INIT_POS_Y	(GRID_HORIZON-GRID_OBJ_SIDE)

#define PRIVATE_PROPERTY(type,variblename)\
public:\
	type Get##variblename()const{ return m_##variblename; }\
	void Set##variblename(type variblename){ m_##variblename=variblename; }\
private:\
	type m_##variblename;

enum eMapValue
{
	eMapValue_None = 0,
	eMapValue_Rect,

	eMapValue_Num
};
enum eObj_Type
{
	eObj_Invalid = -1,
	eObj_Barrier_1,
	eObj_Barrier_2,
	eObj_Block_1,
	eObj_Block_2,
	eObj_Block_3,

	eObj_Tank,

	eObj_Num
};
const byte ARRAY[][GRID_OBJ_TILE] =
{
	{//Barrier_1
		1,0,0,0,0,
		1,0,0,0,0,
		1,0,0,0,0,
		0,0,0,1,0,
		0,0,0,0,0
	},

	{//Barrier_2
		1,0,0,0,0,
		1,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	},

	{//Block_1
		1,1,0,0,0,
		1,1,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	},

	{//Block_2
		1,1,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	},

	{//Block_3
		1,1,1,0,0,
		0,1,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	},

	{//tank
		0,0,1,0,0,
		0,1,1,1,0,
		0,0,1,0,0,
		0,1,1,1,0,
		0,0,0,0,0
	},
};


struct MyPoint
{
	int x,y;
	MyPoint()
	:x(0)
	,y(0)
	{
	}
	MyPoint(int _x,int _y)
	:x(_x)
	,y(_y)
	{
	}
	MyPoint& operator = (const MyPoint& p)
	{
		x = p.x;
		y = p.y;
		return *this;
	}
	bool operator == (const MyPoint& p)
	{
		return x == p.x && y == p.y;
	}
	MyPoint operator + (const MyPoint& p)
	{
		return MyPoint(x+p.x,y+p.y);
	}
	MyPoint operator - (const MyPoint& p)
	{
		return MyPoint(x-p.x,y-p.y);
	}
	MyPoint& operator += (const MyPoint& p)
	{
		x+=p.x;
		y+=p.y;
		return *this;
	}
	MyPoint& operator -= (const MyPoint& p)
	{
		x-=p.x;
		y-=p.y;
		return *this;
	}
};

#endif

