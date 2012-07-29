#include "sprite_dlg_mission_start.h"

CSpriteDlgMissionStart::CSpriteDlgMissionStart()
{

}

CSpriteDlgMissionStart::~CSpriteDlgMissionStart()
{

}

CSpriteDlgMissionStart *CSpriteDlgMissionStart::instance()
{
	CSpriteDlgMissionStart *instance;

	instance = new CSpriteDlgMissionStart;
	if (instance->initSpriteGameDlgMissionStart())
	{
		return instance;
	}
	else
	{
		instance->release();
		return NULL;
	}
}

bool CSpriteDlgMissionStart::initSpriteGameDlgMissionStart()
{
	if (CSpriteDialog::initSpriteDialog())
	{
		m_labelMissionStart = cocos2d::CCLabelTTF::labelWithString("mission start", "consolas", 24);
		addChild(m_labelMissionStart);

		return true;
	}
	else
	{
		return false;
	}
}