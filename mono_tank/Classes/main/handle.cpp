#include "handle.h"
#include "game_controller.h"

cocos2d::CCSize g_ScrrenSize;
cocos2d::CCPoint g_ScrrenCenter;

CSceneGame *g_SceneGame;

void AppSetup()
{
	CGameController *sceneGame;

	cocos2d::CCLog("AppSetup");
	g_ScrrenSize = cocos2d::CCDirector::sharedDirector()->getWinSizeInPixels();
	g_ScrrenCenter = cocos2d::CCPointMake(g_ScrrenSize.width / 2.0f, g_ScrrenSize.height / 2.0f);

	sceneGame = CGameController::instance();
	cocos2d::CCDirector::sharedDirector()->runWithScene(sceneGame);
}