#include "sprite_dialog.h"

#include "layer_dialog.h"

#define SPRITE_DIALOG_ACTION_TIME 0.15f

CSpriteDialog::CSpriteDialog()
{
}

CSpriteDialog::~CSpriteDialog()
{
}

bool CSpriteDialog::initSpriteDialog()
{
	if (cocos2d::CCSprite::init())
	{
		m_actionType = SPRITE_DIALOG_TYPE_Y;
		m_actionSize = cocos2d::CCSizeMake(g_ScrrenSize.width, 100);

		m_flagTouchLock = false;

		m_flagRenderBackground = true;
		m_backgroundColor = cocos2d::ccBLACK;

		return true;
	}
	else
	{
		return false;
	}
}

void CSpriteDialog::draw()
{
	cocos2d::CCRect rect;

	if (m_flagRenderBackground)
	{
		rect.origin = cocos2d::CCPointMake(-m_actionSize.width / 2.0f, -m_actionSize.height / 2.0f);
		rect.size = m_actionSize;
		glColor4ub(m_backgroundColor.r, m_backgroundColor.g, m_backgroundColor.b, 200);
		tgeoDrawRect(rect);
	}
}

void CSpriteDialog::touchBegan(cocos2d::CCPoint Point)
{
	if (m_flagTouchLock)
	{
		return;
	}
}

void CSpriteDialog::touchMoved(cocos2d::CCPoint Point)
{
	if (m_flagTouchLock)
	{
		return;
	}
}

void CSpriteDialog::touchEnded(cocos2d::CCPoint Point)
{
	cocos2d::CCRect rect;

	if (m_flagTouchLock)
	{
		return;
	}

	rect.origin = cocos2d::CCPointMake(-m_actionSize.width / 2.0f, -m_actionSize.height / 2.0f);
	rect.size = m_actionSize;
	if (tgeoPointInRect(rect, Point))
	{
		actionClose();
	}
}

void CSpriteDialog::actionOpen()
{
	cocos2d::CCAction *seq;
	cocos2d::CCScaleTo *action;
	cocos2d::CCCallFunc *callBack;

	m_flagTouchLock = true;

	switch (m_actionType)
	{
	case SPRITE_DIALOG_TYPE_X:
		setScaleX(0.0f);
		setScaleY(1.0f);
		break;
	case SPRITE_DIALOG_TYPE_Y:
		setScaleX(1.0f);
		setScaleY(0.0f);
		break;
	case SPRITE_DIALOG_TYPE_XY:
		setScale(0.0f);
		break;
	default: assert(false);
	}
	action = cocos2d::CCScaleTo::actionWithDuration(SPRITE_DIALOG_ACTION_TIME, 1.0f, 1.0f);
	callBack = cocos2d::CCCallFunc::actionWithTarget(this, cocos2d::SEL_CallFunc(&CSpriteDialog::callBackActionOpenOver));
	seq = cocos2d::CCSequence::actions(action, callBack, NULL);
	runAction(seq);
}

void CSpriteDialog::actionClose()
{
	cocos2d::CCAction *seq;
	cocos2d::CCScaleTo *action;
	cocos2d::CCCallFunc *callBack;

	m_flagTouchLock = true;

	switch (m_actionType)
	{
	case SPRITE_DIALOG_TYPE_X: action = cocos2d::CCScaleTo::actionWithDuration(SPRITE_DIALOG_ACTION_TIME, 0.0f, 1.0f); break;
	case SPRITE_DIALOG_TYPE_Y: action = cocos2d::CCScaleTo::actionWithDuration(SPRITE_DIALOG_ACTION_TIME, 1.0f, 0.0f); break;
	case SPRITE_DIALOG_TYPE_XY: action = cocos2d::CCScaleTo::actionWithDuration(SPRITE_DIALOG_ACTION_TIME, 0.0f, 0.0f); break;
	default: assert(false);
	}
	callBack = cocos2d::CCCallFunc::actionWithTarget(this, cocos2d::SEL_CallFunc(&CSpriteDialog::callBackActionCloseOver));
	seq = cocos2d::CCSequence::actions(action, callBack, NULL);
	runAction(seq);
}

void CSpriteDialog::actionOpenOver()
{
}

void CSpriteDialog::actionCloseOver()
{
	m_layerHandle->stopDialog();
}

void CSpriteDialog::callBackActionOpenOver()
{
	m_flagTouchLock = false;
	actionOpenOver();
}

void CSpriteDialog::callBackActionCloseOver()
{
	m_flagTouchLock = false;
	actionCloseOver();
}