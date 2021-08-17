#pragma once

#include "cState.h"
class cLimitMenu : public cState
{
public:
	
	cGdiImage	m_My_InfantryImg;
	cGdiImage	m_My_ArcherImg;
	cGdiImage	m_My_CavalryImg;
	cGdiImage	m_My_PriestImg;
	cGdiImage	m_My_SpearmanImg;

	cGdiImage	m_Limit_Bgimg;
	cGdiImage	m_Limit_Paperimg;
	cLimitMenu(void);
	~cLimitMenu(void);

	void InitState();
	void Update(float fElapsedTime);
	void Render();
	int Destroy();

	LRESULT MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

