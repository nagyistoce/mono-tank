#include "game_controller.h"
#include "game_logic.h"
#include "game_view.h"

using namespace cocos2d;

CGameController* pCGameController = 0;
CGameController::CGameController()
{
}

CGameController::~CGameController()
{
}

CGameController *CGameController::instance()
{
	if( !pCGameController )
	{
		pCGameController = new CGameController();

		if (pCGameController->initGameController())
		{
			pCGameController->autorelease();
		}
		else
		{
			pCGameController->release();
		}
	}
	
	return pCGameController;
}

bool CGameController::initGameController()
{
	if (cocos2d::CCScene::init())
	{
		m_pLogic = new CGameLogic();
		assert(m_pLogic);

		m_pView = CGameView::create(m_pLogic);
		addChild(m_pView);

		return true;
	}
	return false;
}

void CGameController::onEnter()
{
	CCScene::onEnter();

	schedule(schedule_selector(CGameController::loop));
#ifdef _DEBUG
	m_pView->enterPlay();
	m_pLogic->start();
	m_pView->refresh();
#else
	//m_pView->enterMenu();
#endif

	
	
}

void CGameController::onExit()
{
	CCScene::onExit();
}

void CGameController::loop(float dt)
{
	m_pLogic->update(dt);
	m_pView->refresh();
}

void CGameController::dispatchEvent(eEvent event)
{
	switch(event)
	{
	case eEvent_Btn_StartGame:
		{
			m_pView->enterPlay();
			m_pLogic->start();
			m_pView->refresh();
		}
		break;
	case eEvent_Btn_PauseGame:
		{
			m_pLogic->setPause(true);
		}
		break;
	case eEvent_Btn_ResumeGame:
		{
			m_pLogic->setPause(false);
		}
		break;
	case eEvent_Control_Left:
		{
			m_pLogic->Move(MyPoint(-1,0));
		}
		break;
	case eEvent_Control_Right:
		{
			m_pLogic->Move(MyPoint(1,0));
		}
		break;
	}

	if(event>eEvent_Btn_begin && event<eEvent_Btn_end)
	{
		//play a button sound
	}
}
