#include "MY_include.h"
int Gold = 0;
int DP = 0;
		int Buy_Infantry = 0;
		int Limit_Infantry = 50;
const	int Price_Infantry = 100;

		int Buy_Archer = 0;
		int Limit_Archer = 5;
const	int Price_Archer = 150;

		int Buy_Cavalry = 0;
		int Limit_Cavalry = 5;
const	int Price_Cavalry = 200;

		int Buy_Priest = 0;
		int Limit_Priest = 5;
const	int Price_Priest = 150;

		int Buy_Spearman = 0;
		int Limit_Spearman = 5;
const	int Price_Spearman = 150;


		int Buy_Spell_Lighting = 0;
		int Limit_Spell_Lighting = 5;
const	int Price_Spell_Lighting = 150;

int SelectKind = 0;
char* Message;


	const int offsetX = 30;
	const int offsetY = 50;
cButton Limit_b_Start(800,600,350,100);
cButton Limit_b_Back(10,10,175,100);
cLimitMenu::cLimitMenu(void)
{
}


cLimitMenu::~cLimitMenu(void)
{
}


void cLimitMenu::InitState()
{
	m_My_InfantryImg.SetDC(g_Graphics.getGraphicsDC());
	m_My_InfantryImg.Load("./Image/Unit/My_Infantry.bmp");

	m_My_ArcherImg.SetDC(g_Graphics.getGraphicsDC());
	m_My_ArcherImg.Load("./Image/Unit/My_Archer.bmp");

	m_My_CavalryImg.SetDC(g_Graphics.getGraphicsDC());
	m_My_CavalryImg.Load("./Image/Unit/My_Cavalry.bmp");

	m_My_PriestImg.SetDC(g_Graphics.getGraphicsDC());
	m_My_PriestImg.Load("./Image/Unit/My_Priest.bmp");

	m_My_SpearmanImg.SetDC(g_Graphics.getGraphicsDC());
	m_My_SpearmanImg.Load("./Image/Unit/My_Spearman.bmp");

	m_Limit_Bgimg.SetDC(g_Graphics.getGraphicsDC());
	m_Limit_Bgimg.Load("./Image/State/Level_BG.bmp");
	
	m_Limit_Paperimg.SetDC(g_Graphics.getGraphicsDC());
	m_Limit_Paperimg.Load("./Image/State/Level_paper.bmp");

	Limit_b_Start.ButtonImgLoad("./Image/Button/b_start.bmp","./Image/Button/b_start_over.bmp");
	Limit_b_Back.ButtonImgLoad("./Image/Button/b_Back.bmp","./Image/Button/b_Back_over.bmp");
	Message = "정보창입니다.";
	if(SelectLevel == EASY)
	{
		if(SelectStage == 1)
		{
			Gold = 600;
		}
		else if(SelectStage == 2)
		{
			Gold = 5000;
		}
	}
	else if(SelectLevel == NORMAL)
	{
		if(SelectStage == 1)
		{
			Gold = 3000;
		}
		else if(SelectStage == 2)
		{
			Gold = 3000;
		}
	}
	else if(SelectLevel == HARD)
	{
		if(SelectStage == 1)
		{
			Gold = 2500;
		}
		else if(SelectStage == 2)
		{
			Gold = 2500;
		}
	}
}
void cLimitMenu::Update(float fElapsedTime)
{
	Limit_b_Start.CheckOver(x,y);
	Limit_b_Back.CheckOver(x,y);
}
void cLimitMenu::Render()
{
	m_Limit_Bgimg.Draw(0,0);
	m_Limit_Paperimg.Draw(0,100,0,0,1200,500,1200,500,RGB(255,0,255));

	
	Limit_b_Start.Render();
	
	Limit_b_Back.Render();

	sprintf(strTemp,"골드 %d",Gold);
	g_Graphics.DrawString(260,40,strTemp);
	
	sprintf(strTemp,"Stage %d",SelectStage);
	g_Graphics.DrawString(460,40,strTemp);

	

	if(SelectLevel == EASY)
	{
		sprintf(strTemp,"난이도 Easy");
		g_Graphics.DrawString(660,40,strTemp);
	}
	else if(SelectLevel == NORMAL)
	{
		sprintf(strTemp,"난이도 Normal");
		g_Graphics.DrawString(660,40,strTemp);
	}
	else if(SelectLevel == HARD)
	{
		sprintf(strTemp,"난이도 Hard");
		g_Graphics.DrawString(660,40,strTemp);
	}
	//
	g_Graphics.DrawString(60,100 + offsetY,"군사");
	g_Graphics.DrawString(60,200 + offsetY,"마법");

	if(SelectKind == 0)
	{
		//보병
		g_Graphics.DrawString(260,100 + offsetY,"보병");
		m_My_InfantryImg.Draw(260,200 + offsetY);//,0,0,50,50,50,50,RGB(51,255,0));
		g_Graphics.DrawString(260,285 + offsetY,"비용");
		sprintf(strTemp,"%dGold",Price_Infantry);
		g_Graphics.DrawString(260,300 + offsetY,strTemp);
		sprintf(strTemp,"%d / %d",Buy_Infantry,Limit_Infantry);
		g_Graphics.DrawString(260,400 + offsetY,strTemp);
		g_Graphics.DrawString(260,450 + offsetY,"구매");

		//궁수
		g_Graphics.DrawString(360 + offsetX,100 + offsetY,"궁수");
		m_My_ArcherImg.Draw(360 + offsetX,200 + offsetY);//,0,0,50,50,50,50,RGB(51,255,0));
		g_Graphics.DrawString(360 + offsetX,285 + offsetY,"비용");
		sprintf(strTemp,"%dGold",Price_Archer);
		g_Graphics.DrawString(360 + offsetX,300 + offsetY,strTemp);
		sprintf(strTemp,"%d / %d",Buy_Archer,Limit_Archer);
		g_Graphics.DrawString(360 + offsetX,400 + offsetY,strTemp);
		g_Graphics.DrawString(360 + offsetX,450 + offsetY,"구매");

		//기병
		g_Graphics.DrawString(460 + (offsetX * 2),100 + offsetY,"기병");
		m_My_CavalryImg.Draw(460 + (offsetX * 2),200 + offsetY);//,0,0,50,50,50,50,RGB(51,255,0));
		g_Graphics.DrawString(460 + (offsetX * 2),285 + offsetY,"비용");
		sprintf(strTemp,"%dGold",Price_Cavalry);
		g_Graphics.DrawString(460 + (offsetX * 2),300 + offsetY,strTemp);
		sprintf(strTemp,"%d / %d",Buy_Cavalry,Limit_Cavalry);
		g_Graphics.DrawString(460 + (offsetX * 2),400 + offsetY,strTemp);
		g_Graphics.DrawString(460 + (offsetX * 2),450 + offsetY,"구매");

		//사제
		g_Graphics.DrawString(560 + (offsetX * 3),100 + offsetY,"사제");
		m_My_PriestImg.Draw(560 + (offsetX * 3),200 + offsetY);//,0,0,50,50,50,50,RGB(51,255,0));
		g_Graphics.DrawString(560 + (offsetX * 3),285 + offsetY,"비용");
		sprintf(strTemp,"%dGold",Price_Priest);
		g_Graphics.DrawString(560 + (offsetX * 3),300 + offsetY,strTemp);
		sprintf(strTemp,"%d / %d",Buy_Priest,Limit_Priest);
		g_Graphics.DrawString(560 + (offsetX * 3),400 + offsetY,strTemp);
		g_Graphics.DrawString(560 + (offsetX * 3),450 + offsetY,"구매");

		//창병
		g_Graphics.DrawString(660 + (offsetX * 4),100 + offsetY,"창병");
		m_My_SpearmanImg.Draw(660 + (offsetX * 4),200 + offsetY);//,0,0,50,50,50,50,RGB(51,255,0));
		g_Graphics.DrawString(660 + (offsetX * 4),285 + offsetY,"비용");
		sprintf(strTemp,"%dGold",Price_Spearman);
		g_Graphics.DrawString(660 + (offsetX * 4),300 + offsetY,strTemp);
		sprintf(strTemp,"%d / %d",Buy_Spearman,Limit_Spearman);
		g_Graphics.DrawString(660 + (offsetX * 4),400 + offsetY,strTemp);
		g_Graphics.DrawString(660 + (offsetX * 4),450 + offsetY,"구매");

	}
	else if(SelectKind == 1)
	{
		//스펠1 - 라이트닝 ( 낙뢰 )
		g_Graphics.DrawString(260,100 + offsetY,"낙뢰");
		m_My_InfantryImg.Draw(260,200 + offsetY);//,0,0,50,50,50,50,RGB(51,255,0));
		g_Graphics.DrawString(260,285 + offsetY,"비용");
		sprintf(strTemp,"%dGold",Price_Spell_Lighting);
		g_Graphics.DrawString(260,300 + offsetY,strTemp);
		sprintf(strTemp,"%d / %d",Buy_Spell_Lighting,Limit_Spell_Lighting);
		g_Graphics.DrawString(260,400 + offsetY,strTemp);
		g_Graphics.DrawString(260,450 + offsetY,"구매");
	}
	
	g_Graphics.DrawString(100,600 + offsetY,Message);

	g_Graphics.DrawString(300,500 + offsetY,"리미트메뉴화면");
	sprintf(strTemp,"(%d,%d)",x,y);
	g_Graphics.DrawString(700,0 + offsetY,strTemp);

	

}
int cLimitMenu::Destroy()
{
	m_My_InfantryImg.Destroy();
	m_My_ArcherImg.Destroy();
	m_My_CavalryImg.Destroy();
	m_My_PriestImg.Destroy();
	m_My_SpearmanImg.Destroy();
	m_Limit_Bgimg.Destroy();
	m_Limit_Paperimg.Destroy();
	Limit_b_Start.Destroy();
	Limit_b_Back.Destroy();
	return LEVELMENU;
}
LRESULT cLimitMenu::MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch(iMessage)
	{
		case WM_LBUTTONDOWN:
			Limit_b_Start.CheckDown(x,y);
			Limit_b_Back.CheckDown(x,y);

			if(x > 60 && x < 60 + 35 && y > 100 + offsetY && y < 100 + 15 + offsetY)
			{
				SelectKind = 0;
			}
			else if(x > 60 && x < 60 + 35 && y > 200 + offsetY && y < 200 + 15 + offsetY)
			{
				SelectKind = 1;
			}
			if(SelectKind == 0)
			{
				if(x > 260 && x < 260 + 35 && y > 450 + offsetY && y < 450 + 15 + offsetY)
				{
					if(Gold >= Price_Infantry)
					{
						if(Buy_Infantry < Limit_Infantry)
						{
							Gold -= Price_Infantry;
							Buy_Infantry++;
						}
						else
						{
							Message = "보병 구매 최대 한도에 도달하였습니다.";
						}
					}
					else
					{
						Message = "골드가 부족합니다.";
					}

				}
				else if(x > 360 + offsetX && x < 360 + 35 + offsetX && y > 450 + offsetY && y < 450 + 15 + offsetY)
				{
					if(Gold >= Price_Archer)
					{
						if(Buy_Archer < Limit_Archer)
						{
							Gold -= Price_Archer;
							Buy_Archer++;
						}
						else
						{
							Message = "궁수 구매 최대 한도에 도달하였습니다.";
						}
					}
					else
					{
						Message = "골드가 부족합니다.";
					}

				}
				else if(x > 460 + (offsetX * 2) && x < 460 + 35 + (offsetX * 2) && y > 450 + offsetY && y < 450 + 15 + offsetY)
				{
					if(Gold >= Price_Cavalry)
					{
						if(Buy_Cavalry < Limit_Cavalry)
						{
							Gold -= Price_Cavalry;
							Buy_Cavalry++;
						}
						else
						{
							Message = "기병 구매 최대 한도에 도달하였습니다.";
						}
					}
					else
					{
						Message = "골드가 부족합니다.";
					}
				}
				else if(x > 560 + (offsetX * 3) && x < 560 + 35 + (offsetX * 3) && y > 450 + offsetY && y < 450 + 15 + offsetY)
				{
					if(Gold >= Price_Priest)
					{
						if(Buy_Priest < Limit_Priest)
						{
							Gold -= Price_Priest;
							Buy_Priest++;
						}
						else
						{
							Message = "사제 구매 최대 한도에 도달하였습니다.";
						}
					}
					else
					{
						Message = "골드가 부족합니다.";
					}
				}
				else if(x > 660 + (offsetX * 4) && x < 660 + 35 + (offsetX * 4) && y > 450 + offsetY && y < 450 + 15 + offsetY)
				{
					if(Gold >= Price_Spearman)
					{
						if(Buy_Spearman < Limit_Spearman)
						{
							Gold -= Price_Spearman;
							Buy_Spearman++;
						}
						else
						{
							Message = "창병 구매 최대 한도에 도달하였습니다.";
						}
					}
					else
					{
						Message = "골드가 부족합니다.";
					}
				}
			}
			else if(SelectKind == 1)
			{
				if(x > 260 && x < 260 + 35 && y > 450 + offsetY && y < 450 + 15 + offsetY)
				{
					if(Gold >= Price_Spell_Lighting)
					{
						if(Buy_Spell_Lighting < Limit_Spell_Lighting)
						{
							Gold -= Price_Spell_Lighting;
							Buy_Spell_Lighting++;
						}
						else
						{
							Message = "낙뢰 구매 최대 한도에 도달하였습니다.";
						}
					}
					else
					{
						Message = "골드가 부족합니다.";
					}

				}
				}

			break;
		case WM_LBUTTONUP:
			if(Limit_b_Start.CheckUp(x,y) == true)
			{
				g_Game.gotoPlay(GAME);
			}
			if(Limit_b_Back.CheckUp(x,y) == true)
			{
				g_Game.gotoPlay(STAGEMENU);
			}
			break;
		case WM_MOUSEMOVE:
			x = LOWORD(lParam);
			y = HIWORD(lParam);
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return (DefWindowProc(hWnd,iMessage,wParam,lParam));
}