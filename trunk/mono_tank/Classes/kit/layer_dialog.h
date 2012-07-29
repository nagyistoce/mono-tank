#ifndef layer_dialog_h
#define layer_dialog_h

#include "head.h"

class CSpriteDialog;

class CLayerDialog : public cocos2d::CCLayer
{
public:
	CSpriteDialog *m_spriteHandle;

public:
	CLayerDialog();
	~CLayerDialog();

	static CLayerDialog *instance();

	bool initLayerDialog();

	bool touchBegan(cocos2d::CCPoint Point);
	bool touchMoved(cocos2d::CCPoint Point);
	bool touchEnded(cocos2d::CCPoint Point);

	void runDialog(CSpriteDialog *Dialog);
	void stopDialog(void);
};

#endif