#ifndef sprite_dlg_mission_start_h
#define sprite_dlg_mission_start_h

#include "head.h"
#include "sprite_dialog.h"

class CSpriteDlgMissionStart : public CSpriteDialog
{
public:
	cocos2d::CCLabelTTF *m_labelMissionStart;

public:
	CSpriteDlgMissionStart();
	virtual ~CSpriteDlgMissionStart();

	static CSpriteDlgMissionStart *instance();

	virtual bool initSpriteGameDlgMissionStart();
};

#endif