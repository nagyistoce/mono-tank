#ifndef handle_h
#define handle_h

#include "head.h"

class CSceneGame;

extern cocos2d::CCSize g_ScrrenSize;
extern cocos2d::CCPoint g_ScrrenCenter;

extern CSceneGame *g_SceneGame;

/*graphic data
*/
const GLfloat g_PlayerVertex[] = {-25.0f, -0.0f, 25.0f, -0.0f, 0.0f, 50.0f};
const GLubyte g_PlayerIndex[] = {0, 1, 1, 2, 2, 0};

const GLfloat g_CtrlRightVertex[] = {0.0f, -15.0f, 30.0f, 0.0f, 0.0f, 15.0f};
const GLubyte g_CtrlRightIndexNormal[] = {0, 1, 1, 2, 2, 0};
const GLubyte g_CtrlRightIndexSelected[] = {0, 1, 2};

void AppSetup();

#endif