#include "handle.h"
#include "scene_game.h"

cocos2d::CCSize g_ScrrenSize;
cocos2d::CCPoint g_ScrrenCenter;

CSceneGame *g_SceneGame;

void AppSetup()
{
	CSceneGame *sceneGame;

	cocos2d::CCLog("AppSetup");
	g_ScrrenSize = cocos2d::CCDirector::sharedDirector()->getWinSizeInPixels();
	g_ScrrenCenter = cocos2d::CCPointMake(g_ScrrenSize.width / 2.0f, g_ScrrenSize.height / 2.0f);

	sceneGame = CSceneGame::instance();
	cocos2d::CCDirector::sharedDirector()->runWithScene(sceneGame);
	sceneGame->release();
}