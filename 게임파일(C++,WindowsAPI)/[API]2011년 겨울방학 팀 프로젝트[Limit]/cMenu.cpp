#include "MY_include.h"

cButton Menu_b_Start(200,450,350,100);
cButton Menu_b_HowToPlay(600,450,350,100);
cButton Menu_b_Option(200,600,350,100);
cButton Menu_b_Exit(600,600,350,100);

bool SoundPlayed = false;
cMenu::cMenu()
{
	if(SoundPlayed == false)
	{
		SoundPlayed = true;
		m_MainBGM.SoundLoad("./Sound/Menu_BGM.mp3",true);
		m_MainBGM.PLAYSound();
	}
}
cMenu::~cMenu()
{

}
void cMenu::InitState()
{
	m_Menu_BGImg.SetDC(g_Graphics.getGraphicsDC());
	m_Menu_BGImg.Load("./Image/State/Menu_main.bmp");

	Menu_b_Start.ButtonImgLoad("./Image/Button/b_GameStart.bmp","./Image/Button/b_GameStart_over.bmp");
	Menu_b_HowToPlay.ButtonImgLoad("./Image/Button/b_HowToPlay.bmp","./Image/Button/b_HowToPlay_over.bmp");
	Menu_b_Option.ButtonImgLoad("./Image/Button/b_Option.bmp","./Image/Button/b_Option_over.bmp");
	Menu_b_Exit.ButtonImgLoad("./Image/Button/b_Exit.bmp","./Image/Button/b_Exit_over.bmp");
	
}
void cMenu::Update(float fElapsedTime)
{
	Menu_b_Start.CheckOver(x,y);
	Menu_b_HowToPlay.CheckOver(x,y);
	Menu_b_Option.CheckOver(x,y);
	Menu_b_Exit.CheckOver(x,y);
}
void cMenu::Render()
{
	m_Menu_BGImg.Draw(0,0);
	Menu_b_Start.Render();
	Menu_b_HowToPlay.Render();
	Menu_b_Option.Render();
	Menu_b_Exit.Render();
	
	g_Graphics.DrawString(300,500,"게임메뉴화면");
	sprintf(strTemp,"(%d,%d)",x,y);
	g_Graphics.DrawString(700,0,strTemp);
	
}
int cMenu::Destroy()
{
	Menu_b_Start.Destroy();
	Menu_b_HowToPlay.Destroy();
	Menu_b_Option.Destroy();
	Menu_b_Exit.Destroy();
	m_Menu_BGImg.Destroy();
	//m_MainBGM.DeleteSound();
	return GAME;
}

LRESULT cMenu::MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch(iMessage)
	{
		case WM_LBUTTONDOWN:
			Menu_b_Start.CheckDown(x,y);
			Menu_b_HowToPlay.CheckDown(x,y);
			Menu_b_Option.CheckDown(x,y);
			Menu_b_Exit.CheckDown(x,y);
		break;
		case WM_LBUTTONUP:
			if(Menu_b_Start.CheckUp(x,y) == true)
			{
				//m_MainBGM.DeleteSound();
				g_Game.gotoPlay(LEVELMENU);
			}
			if(Menu_b_HowToPlay.CheckUp(x,y) == true)
			{
				//m_MainBGM.DeleteSound();
				//g_Game.gotoPlay(LOGO);
			}
			if(Menu_b_Option.CheckUp(x,y) == true)
			{
				//m_MainBGM.DeleteSound();
				//g_Game.gotoPlay(LEVELMENU);
			}
			if(Menu_b_Exit.CheckUp(x,y) == true)
			{
				//m_MainBGM.DeleteSound();
				exit(1);
				break;
			}
		
		

		case WM_MOUSEMOVE:
			x = LOWORD(lParam);
			y = HIWORD(lParam);
		break;

		case WM_KEYDOWN:
			break;

		case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	}
	return (DefWindowProc(hWnd,iMessage,wParam,lParam));
}

