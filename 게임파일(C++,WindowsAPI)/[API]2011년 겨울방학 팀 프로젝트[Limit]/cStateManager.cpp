#include "My_include.h"

cStateManager::cStateManager()
{
 m_State = new cLogo;
 m_InnerState = INIT;
}

cStateManager::~cStateManager()
{
 if(m_State != NULL)
  delete m_State;
}

void cStateManager::setInnerState(int value)
{
	m_InnerState = value;
}
void cStateManager::gotoPlay(int value)
{
	returnValue = value;
	m_InnerState = GOTOPLAY;
}
void cStateManager::GameFC(float fElapsedTime)
{
 switch(m_InnerState)
 {
 case INIT:
  m_State->InitState();
  m_InnerState = LOOP;
  break;
 case LOOP:
  m_State->Update(fElapsedTime);
  m_State->Render();
  break;
 case DESTROY:
	  returnValue = m_State->Destroy();
	  delete m_State;
	  m_InnerState = INIT;
	  switch(returnValue)
	  {
	  case LOGO:
	   m_State = new cLogo;
	   break;
	  case MENU:
	   m_State = new cMenu;
	   break;
	  case GAME:
	   m_State = new cGame;
	   break;
	  case LEVELMENU:
	   m_State = new cLevelMenu;
	   break;
	  case STAGEMENU:
	   m_State = new cStageMenu;
	   break;
	  case LIMITMENU:
	   m_State = new cLimitMenu;
	   break;
	  }
	  break;
 case GOTOPLAY:

	  m_State->Destroy();
	  delete m_State;
	  m_InnerState = INIT;
	  switch(returnValue)
	  {
	  case LOGO:
	   m_State = new cLogo;
	   break;
	  case MENU:
	   m_State = new cMenu;
	   break;
	  case GAME:
	   m_State = new cGame;
	   break;
	  case LEVELMENU:
	   m_State = new cLevelMenu;
	   break;
	  case STAGEMENU:
	   m_State = new cStageMenu;
	   break;
	  case LIMITMENU:
	   m_State = new cLimitMenu;
	   break;
	  }
break;
 }


}