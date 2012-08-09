#ifndef game_define_h
#define game_define_h

typedef unsigned char byte;

#define WINDOW_WIDTH	320
#define WINDOW_HEIGHT	480

#define GRID_VERTICAL	12
#define GRID_HORIZON	20

#define GRID_OBJ_SIDE		5
#define GRID_OBJ_TILE		(GRID_OBJ_SIDE*GRID_OBJ_SIDE)

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

	const byte ARRAY_NONE[GRID_OBJ_TILE] =
	{
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	};

	const byte ARRAY_TANK[GRID_OBJ_TILE] =
	{
		0,0,1,0,0,
		0,1,1,1,0,
		0,0,1,0,0,
		0,1,1,1,0,
		0,0,0,0,0
	};

	const byte ARRAY_BARRIER[GRID_OBJ_TILE] =
	{
		1,0,0,0,0,
		1,0,0,0,0,
		1,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	};

enum eObj_Type
{
	eObj_Invalid = 0,
	eObj_Tank,
	eObj_Barrier,

	eObj_Num
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

