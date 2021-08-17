#pragma once
#include "cState.h"

class cStateManager
{
public:
 cState* m_State;
 int m_InnerState;
 int returnValue;
public:
 cStateManager();
 ~cStateManager();

 void GameFC(float fElapsedTime);
 void setInnerState(int value);
 void gotoPlay(int value);
};