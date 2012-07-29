#ifndef tool_geometry_h
#define tool_geometry_h

#include "tool.h"

float tgeoPointDistance(cocos2d::CCPoint PointA, cocos2d::CCPoint PointB);
bool tgeoPointInRect(cocos2d::CCRect Rect, cocos2d::CCPoint Point);

void tgeoDrawLine(cocos2d::CCPoint Start, cocos2d::CCPoint End);
void tgeoDrawRect(cocos2d::CCRect Rect);

#endif