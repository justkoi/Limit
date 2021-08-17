#pragma once

#include "cState.h"
#include "cGdiImage.h"
class cLevelMenu : public cState
{
public:
	cGdiImage	m_LevelMenu_BGImg;
	cGdiImage	m_Level_paperImg;
	cGdiImage	m_Level_rightImg;
	cGdiImage	m_Level_leftImg;
	cGdiImage	m_Level_BGImg;
	cLevelMenu();
	~cLevelMenu();
	
	void InitState();
	void Update(float fElapsedTime);
	void Render();
	int Destroy();

	LRESULT MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

