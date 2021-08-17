#include "MY_include.h"
int SelectStage = 1;
bool Stage_Easy_Open[MAX_STAGE];
bool Stage_Normal_Open[MAX_STAGE];
bool Stage_Hard_Open[MAX_STAGE];


cButton Stage_b_Back(10,10,175,100);

cStageMenu::cStageMenu(void)
{
}


cStageMenu::~cStageMenu(void)
{
}
void cStageMenu::InitState()
{
	
	m_StageMenu_BGImg.SetDC(g_Graphics.getGraphicsDC());
	m_StageMenu_BGImg.Load("./Image/State/Level_BG.bmp");
	m_InterFace.SetDC(g_Graphics.getGraphicsDC());
	m_InterFace.Load("./Image/Effect/InterFace01.bmp");

	
	Stage_b_Back.ButtonImgLoad("./Image/Button/b_Back.bmp","./Image/Button/b_Back_over.bmp");
	Stage_Easy_Open[0] = true;
	Stage_Normal_Open[0] = true;
	Stage_Hard_Open[0] = true;
	
	Stage_Easy_Open[1] = true;
	Stage_Normal_Open[1] = true;
	Stage_Hard_Open[1] = true;
}
void cStageMenu::Update(float fElapsedTime)
{
	Stage_b_Back.CheckOver(x,y);
}
void cStageMenu::Render()
{
	m_StageMenu_BGImg.Draw(0,0);
	m_InterFace.Draw(0,0,0,0,300,600,300,600,RGB(255,0,255));
	
	Stage_b_Back.Render();
	if(SelectLevel == EASY)
	{
		for(int i=0; i<3; i++)
		{
			sprintf(strTemp,"%d Stage",SelectStage + i);
			g_Graphics.DrawString(i * 300 + 100,100,strTemp);

			if(Stage_Easy_Open[SelectStage + i - 1] == true)
			{
				g_Graphics.DrawString(i * 300 + 100,300,"열림");
			}
			else if(Stage_Easy_Open[SelectStage + i - 1] == false)
			{
				g_Graphics.DrawString(i * 300 + 100,300,"닫힘");
			}
		}
	}
	else if(SelectLevel == NORMAL)
	{
		for(int i=0; i<3; i++)
		{
			sprintf(strTemp,"%d Stage",SelectStage + i);
			g_Graphics.DrawString(i * 300 + 100,100,strTemp);

			if(Stage_Normal_Open[SelectStage + i - 1] == true)
			{
				g_Graphics.DrawString(i * 300 + 100,300,"열림");
			}
			else if(Stage_Normal_Open[SelectStage + i - 1] == false)
			{
				g_Graphics.DrawString(i * 300 + 100,300,"닫힘");
			}
		}
	}
	else if(SelectLevel == HARD)
	{
		for(int i=0; i<3; i++)
		{
			sprintf(strTemp,"%d Stage",SelectStage + i);
			g_Graphics.DrawString(i * 300 + 100,100,strTemp);

			if(Stage_Hard_Open[SelectStage + i - 1] == true)
			{
				g_Graphics.DrawString(i * 300 + 100,300,"열림");
			}
			else if(Stage_Hard_Open[SelectStage + i - 1] == false)
			{
				g_Graphics.DrawString(i * 300 + 100,300,"닫힘");
			}
		}
	}


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
	
	g_Graphics.DrawString(300,500,"스테이지메뉴화면");
	sprintf(strTemp,"(%d,%d)",x,y);
	g_Graphics.DrawString(700,0,strTemp);



}
int cStageMenu::Destroy()
{
	m_InterFace.Destroy();
	m_StageMenu_BGImg.Destroy();
	return LEVELMENU;
}

LRESULT cStageMenu::MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch(iMessage)
	{
		case WM_LBUTTONDOWN:
			if(SelectStage > 1)
			SelectStage--;
			
			Stage_b_Back.CheckDown(x,y);
		break;

		case WM_RBUTTONDOWN:
			if(SelectStage < MAX_STAGE - 2)
			SelectStage++;
			
		break;
		
		case WM_LBUTTONUP:
			if(Stage_b_Back.CheckUp(x,y) == true)
			{
				g_Game.gotoPlay(LEVELMENU);
			}
			break;
		case WM_MOUSEMOVE:
			x = LOWORD(lParam);
			y = HIWORD(lParam);
		break;

		case WM_KEYDOWN:
			g_Game.gotoPlay(LIMITMENU);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return (DefWindowProc(hWnd,iMessage,wParam,lParam));
}