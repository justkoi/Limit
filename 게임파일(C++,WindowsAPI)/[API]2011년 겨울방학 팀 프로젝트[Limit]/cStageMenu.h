#pragma once
#include "cState.h"
#include "cGdiImage.h"
class cStageMenu : public cState
{
public:
	cStageMenu(void);
	~cStageMenu(void);
	cGdiImage		m_InterFace;
	cGdiImage		m_StageMenu_BGImg;
	void InitState();
	void Update(float fElapsedTime);
	void Render();
	int Destroy();

	LRESULT MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

