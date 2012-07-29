#include "head.h"

#define SPRITE_DIALOG_TYPE_X 0
#define SPRITE_DIALOG_TYPE_Y 1
#define SPRITE_DIALOG_TYPE_XY 2

class CLayerDialog;

class CSpriteDialog : public cocos2d::CCSprite
{
public:
	CLayerDialog *m_layerHandle;

	int m_actionType;
	cocos2d::CCSize m_actionSize;

	bool m_flagTouchLock;

	bool m_flagRenderBackground;
	cocos2d::ccColor3B m_backgroundColor;

public:
	CSpriteDialog();
	virtual ~CSpriteDialog();

	virtual bool initSpriteDialog();
	virtual void draw();

	virtual void touchBegan(cocos2d::CCPoint Point);
	virtual void touchMoved(cocos2d::CCPoint Point);
	virtual void touchEnded(cocos2d::CCPoint Point);

	void actionOpen();
	void actionClose();

	virtual void actionOpenOver();
	virtual void actionCloseOver();

	void callBackActionOpenOver();
	void callBackActionCloseOver();
};