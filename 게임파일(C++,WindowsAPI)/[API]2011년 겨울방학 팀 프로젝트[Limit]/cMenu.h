#pragma once
#include "cState.h"
#include "fmodSound.h"
#include "sceneManager.h"

#include "cButton.h"
class cMenu : public cState
{
	/*cSceneManager m_Ani;
	cSceneManager m_Ani2;*/

	cGdiImage m_menu1;
/*
	cGdiImage m_Title1;
	cGdiImage m_Title2;
	cGdiImage m_Title3;
	cGdiImage m_Title4;
	cGdiImage m_Title5;
	cGdiImage m_Title6;
	cGdiImage m_Title7;
	cGdiImage m_Title9;*/

	cGdiImage m_Menu_BGImg;
	fSound	m_MainBGM;
	FILE * fp;

	int m_SongNumber[50];
	int m_SongNode[50];
	int m_SongPlayTime[50];
	int m_SongFileName[50];
	//fSound m_BS;
	int m_AniState;
	int m_Ani2State;
	int selectMenu;
	int count;

	
public:
	cMenu();
	~cMenu();

	void InitState();
	void Update(float fElapsedTime);
	void Render();
	int Destroy();

	LRESULT MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
	
};