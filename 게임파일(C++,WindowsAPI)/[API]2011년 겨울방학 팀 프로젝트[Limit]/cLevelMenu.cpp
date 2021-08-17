#include "MY_include.h"

int SelectLevel = NORMAL;

cButton Level_b_Back(10,10,175,100);
cLevelMenu::cLevelMenu()
{
}

cLevelMenu::~cLevelMenu()
{
}

void cLevelMenu::InitState()
{
	m_LevelMenu_BGImg.SetDC(g_Graphics.getGraphicsDC());
	m_LevelMenu_BGImg.Load("./Image/State/main.bmp");


	m_Level_BGImg.SetDC(g_Graphics.getGraphicsDC());
	m_Level_BGImg.Load("./Image/State/Level_BG.bmp");

	m_Level_paperImg.SetDC(g_Graphics.getGraphicsDC());
	m_Level_paperImg.Load("./Image/State/Level_paper.bmp");

	m_Level_rightImg.SetDC(g_Graphics.getGraphicsDC());
	m_Level_rightImg.Load("./Image/State/Level_right.bmp");

	m_Level_leftImg.SetDC(g_Graphics.getGraphicsDC());
	m_Level_leftImg.Load("./Image/State/Level_left.bmp");


	Level_b_Back.ButtonImgLoad("./Image/Button/b_Back.bmp","./Image/Button/b_Back_over.bmp");

}

void cLevelMenu::Update(float fElapsedTime)
{
	Level_b_Back.CheckOver(x,y);
}

void cLevelMenu::Render()
{
	m_LevelMenu_BGImg.Draw(0,0);
	g_Graphics.DrawString(300,500,"난이도메뉴화면");
	sprintf(strTemp,"(%d,%d)",x,y);
	g_Graphics.DrawString(700,0,strTemp);

	m_Level_BGImg.Draw(0,0);
	m_Level_paperImg.Draw(80,50,0,0,1000,400,1200,500,RGB(255,0,255));
	m_Level_rightImg.Draw(0,0,0,0,1200,500,1200,500,RGB(255,0,255));
	m_Level_leftImg.Draw(0,0,0,0,1200,500,1200,500,RGB(255,0,255));


	Level_b_Back.Render();

	if(SelectLevel == EASY)
	{
		g_Graphics.DrawString(800,0,"선택된 난이도   : EASY");
	}
	else if(SelectLevel == NORMAL)
	{
		g_Graphics.DrawString(800,0,"선택된 난이도   : NORMAL");
	}
	else if(SelectLevel == HARD)
	{
		g_Graphics.DrawString(800,0,"선택된 난이도   : HARD");
	}
	sprintf(strTemp,"선택된 스테이지 : %d",SelectStage);
	g_Graphics.DrawString(800,15,strTemp);

}
int cLevelMenu::Destroy()
{
	m_LevelMenu_BGImg.Destroy();
	Level_b_Back.Destroy();
	return MENU;
}

LRESULT cLevelMenu::MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch(iMessage)
	{
	case WM_MOUSEMOVE:

		x = LOWORD(lParam);
		y = HIWORD(lParam);
		break;
	case WM_LBUTTONDOWN:
		Level_b_Back.CheckDown(x,y);
		break;
	case WM_LBUTTONUP:
		if(Level_b_Back.CheckUp(x,y) == true)
		{
			g_Game.gotoPlay(MENU);
		}
		break;



	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_E:
			SelectLevel = EASY;
			g_Game.gotoPlay(STAGEMENU);
			break;
		case VK_N:
			SelectLevel = NORMAL;
			g_Game.gotoPlay(STAGEMENU);
			break;
		case VK_H:
			SelectLevel = HARD;
			g_Game.gotoPlay(STAGEMENU);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd,iMessage,wParam,lParam));
}