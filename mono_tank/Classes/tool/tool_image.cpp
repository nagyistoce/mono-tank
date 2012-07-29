#include "tool_image.h"

cocos2d::CCSprite *timgCreateImage(std::string ImagePath)
{
	cocos2d::CCSprite *ret;

	ret = new cocos2d::CCSprite;
	ret->initWithFile(ImagePath.c_str());
	return ret;
}