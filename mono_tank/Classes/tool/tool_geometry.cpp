#include "tool_geometry.h"

float tgeoPointDistance(cocos2d::CCPoint PointA, cocos2d::CCPoint PointB)
{
	return sqrtf(pow(PointA.x - PointB.x, 2) + pow(PointA.y - PointB.y, 2));
}

bool tgeoPointInRect(cocos2d::CCRect Rect, cocos2d::CCPoint Point)
{
	if (Rect.origin.x <= Point.x && Point.x <= Rect.origin.x + Rect.size.width &&
		Rect.origin.y <= Point.y && Point.y < Rect.origin.y + Rect.size.height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void tgeoDrawLine(cocos2d::CCPoint Start, cocos2d::CCPoint End)
{
	GLfloat vertex[] = {Start.x, Start.y, End.x, End.y};
	GLubyte index[] = {0, 1};

	glDisable(GL_COLOR_ARRAY);
	glDisable(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);

	glVertexPointer(2, GL_FLOAT, 0, vertex);
	glDrawElements(GL_LINES, sizeof(index), GL_UNSIGNED_BYTE, index);

	glEnable(GL_COLOR_ARRAY);
	glEnable(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
}

void tgeoDrawRect(cocos2d::CCRect Rect)
{
	GLfloat vertex[] = {
		Rect.origin.x, Rect.origin.y,
		Rect.origin.x + Rect.size.width, Rect.origin.y,
		Rect.origin.x + Rect.size.width, Rect.origin.y + Rect.size.height,
		Rect.origin.x, Rect.origin.y + Rect.size.height};
	GLubyte index[] = {0, 1, 2, 2, 3, 0};

	glDisable(GL_COLOR_ARRAY);
	glDisable(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);

	glVertexPointer(2, GL_FLOAT, 0, vertex);
	glDrawElements(GL_TRIANGLES, sizeof(index), GL_UNSIGNED_BYTE, index);

	glEnable(GL_COLOR_ARRAY);
	glEnable(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
}