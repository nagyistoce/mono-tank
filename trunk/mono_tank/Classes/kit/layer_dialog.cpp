#include "layer_dialog.h"

#include "sprite_dialog.h"

CLayerDialog::CLayerDialog()
{
}

CLayerDialog::~CLayerDialog()
{
}

CLayerDialog *CLayerDialog::create()
{
	CLayerDialog *instance;

	instance = new CLayerDialog;
	if (instance->initLayerDialog())
	{
		instance->autorelease();
		return instance;
	}
	else
	{
		instance->release();
		return NULL;
	}
}

bool CLayerDialog::initLayerDialog()
{
	if (cocos2d::CCLayer::init())
	{
		m_spriteHandle = NULL;
		return true;
	}
	else
	{
		return false;
	}
}

bool CLayerDialog::touchBegan(cocos2d::CCPoint Point)
{
	cocos2d::CCPoint localPoint;

	if (NULL != m_spriteHandle)
	{
		localPoint.x = Point.x - getPositionInPixels().x;
		localPoint.y = Point.y - getPositionInPixels().y;
		m_spriteHandle->touchBegan(localPoint);
		return false;
	}
	else
	{
		return true;
	}
}

bool CLayerDialog::touchMoved(cocos2d::CCPoint Point)
{
	cocos2d::CCPoint localPoint;

	if (NULL != m_spriteHandle)
	{
		localPoint.x = Point.x - getPositionInPixels().x;
		localPoint.y = Point.y - getPositionInPixels().y;
		m_spriteHandle->touchMoved(localPoint);
		return false;
	}
	else
	{
		return true;
	}
}

bool CLayerDialog::touchEnded(cocos2d::CCPoint Point)
{
	cocos2d::CCPoint localPoint;

	if (NULL != m_spriteHandle)
	{
		localPoint.x = Point.x - getPositionInPixels().x;
		localPoint.y = Point.y - getPositionInPixels().y;
		m_spriteHandle->touchEnded(localPoint);
		return false;
	}
	else
	{
		return true;
	}
}

void CLayerDialog::runDialog(CSpriteDialog *Dialog)
{
	addChild(Dialog);
	m_spriteHandle = Dialog;
	Dialog->m_layerHandle = this;
	Dialog->actionOpen();
}

void CLayerDialog::stopDialog()
{
	removeChild(m_spriteHandle, true);
	m_spriteHandle = NULL;
}