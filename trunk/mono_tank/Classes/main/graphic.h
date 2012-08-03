#include "head.h"

/*graphic data
*/

#define GP_TANK_W 40
#define GP_TANK_H 40

const GLfloat g_GpTankVex[] = {
	-GP_TANK_W / 2.0f, 0.0f,
	GP_TANK_W / 2.0f, 0.0f,
	GP_TANK_W / 2.0f, GP_TANK_H / 2.0f,
	GP_TANK_W / 4.0f, GP_TANK_H / 2.0f,
	GP_TANK_W / 4.0f, GP_TANK_H,
	-GP_TANK_W / 4.0f, GP_TANK_H,
	-GP_TANK_W / 4.0f, GP_TANK_H / 2.0f,
	-GP_TANK_W / 2.0f, GP_TANK_H / 2.0f};
const GLubyte g_GpTankInx[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 0};

#define GP_BULLET_W 20
#define GP_BULLET_H 40

const GLfloat g_GpBulletVex[] = {
	-GP_BULLET_W / 2.0f, 0.0f,
	GP_BULLET_W / 2.0f, 0.0f,
	GP_BULLET_W / 2.0f, GP_BULLET_H * 0.6f,
	0.0f, GP_BULLET_H,
	-GP_BULLET_W / 2.0f, GP_BULLET_H * 0.6f,
};
const GLubyte g_GpBulletInx[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 0};