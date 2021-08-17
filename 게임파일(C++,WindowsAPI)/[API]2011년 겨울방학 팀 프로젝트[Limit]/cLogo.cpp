#include "MY_include.h"
#include "fmodSound.h"
#include "Struct.h"
//#include <Windows.h>
//#include "cLogo.h"
//cStateManager g_Game;
//


fSound AttackSound01[MaxSound01];
fSound AttackSound02[MaxSound02];
MoveRoute Logo_MoveRoute;
const int SnowSpeed = 1;
WORD x;
WORD y;
Pos obj1Pos;
// 결국 버튼은 전역으로 선언 .

const int SnowRegenTime = 100; //리젠시간
const int RegenTime = 1000; //리젠시간
const int REBIRTHABLE = true;  //부활가능 불가능

const int MIN = 20; // My Infantry Num	//보병
const int EIN = 20; // Ey Infantry Num

const int MAR = 0;						//궁수
const int EAR = 0;

const int MCA = 0;						//기병
const int ECA = 0;

const int MPR = 0;						//사제
const int EPR = 0;

const int MSP = 0;						//창병
const int ESP = 0;
cLogo::cLogo()
{
	m_LogoBGM.SoundLoad("./Sound/Logo_BGM.mp3",true);
}
cLogo::~cLogo()
{
	
}
void cLogo::InitState()
{
	
	Logo_MoveRoute.X = 600;
	Logo_MoveRoute.Y = 300;
	Logo_MoveRoute.Range_Width = 100;
	Logo_MoveRoute.Range_Height = 100;
	for(int i=0; i<MaxSound01; i++)
	{
		AttackSound01[i].SoundLoad("./Sound/Attack01.mp3",false);
	}
	
	for(int i=0; i<MaxSound02; i++)
	{
		AttackSound02[i].SoundLoad("./Sound/Attack02.wav",false);
	}

	AlphaOn = false;
	m_LogoBGM.PLAYSound();
	m_Logo_BGImg.SetDC(g_Graphics.getGraphicsDC());
	m_Logo_BGImg.Load("./Image/State/Logo_main.bmp");
	/*m_Logo_Limit.SetDC(g_Graphics.getGraphicsDC());
	m_Logo_Limit.Load("./Image/State/main_Limit.bmp");*/

	m_ArrowImg.SetDC(g_Graphics.getGraphicsDC());
	m_ArrowImg.Load("./Image/Effect/Arrow.bmp");

	m_My_InfantryImg.SetDC(g_Graphics.getGraphicsDC());
	m_My_InfantryImg.Load("./Image/Unit/My_Infantry.bmp");

	m_Ey_InfantryImg.SetDC(g_Graphics.getGraphicsDC());
	m_Ey_InfantryImg.Load("./Image/Unit/Ey_Infantry.bmp");

	m_My_ArcherImg.SetDC(g_Graphics.getGraphicsDC());
	m_My_ArcherImg.Load("./Image/Unit/My_Archer.bmp");

	m_Ey_ArcherImg.SetDC(g_Graphics.getGraphicsDC());
	m_Ey_ArcherImg.Load("./Image/Unit/Ey_Archer.bmp");

	m_My_CavalryImg.SetDC(g_Graphics.getGraphicsDC());
	m_My_CavalryImg.Load("./Image/Unit/My_Cavalry.bmp");

	m_Ey_CavalryImg.SetDC(g_Graphics.getGraphicsDC());
	m_Ey_CavalryImg.Load("./Image/Unit/Ey_Cavalry.bmp");

	
	m_My_PriestImg.SetDC(g_Graphics.getGraphicsDC());
	m_My_PriestImg.Load("./Image/Unit/My_Priest.bmp");

	m_Ey_PriestImg.SetDC(g_Graphics.getGraphicsDC());
	m_Ey_PriestImg.Load("./Image/Unit/Ey_Priest.bmp");


	m_My_SpearmanImg.SetDC(g_Graphics.getGraphicsDC());
	m_My_SpearmanImg.Load("./Image/Unit/My_Spearman.bmp");

	m_Ey_SpearmanImg.SetDC(g_Graphics.getGraphicsDC());
	m_Ey_SpearmanImg.Load("./Image/Unit/Ey_Spearman.bmp");

	m_BlackGroundImg.SetDC(g_Graphics.getGraphicsDC());
	m_BlackGroundImg.Load("./Image/Effect/BlackGround.bmp");
	/*
	m_SnowImg.SetDC(g_Graphics.getGraphicsDC());
	m_SnowImg.Load("./Image/Effect/Snow.bmp");
*/

		m_My_Infantry = new cInfantry[MIN];
		m_Ey_Infantry = new cInfantry[EIN];

		m_My_Archer	  = new cArcher[MAR];
		m_Ey_Archer	  = new cArcher[EAR];

		m_My_Cavalry  = new cCavalry[MCA];
		m_Ey_Cavalry  = new cCavalry[ECA];

		m_My_Priest   = new cPriest[MPR];
		m_Ey_Priest   = new cPriest[EPR];

		m_My_Spearman = new cSpearman[MSP];
		m_Ey_Spearman = new cSpearman[ESP];

		for(int i=0;i<MIN;i++)
		{
			m_My_Infantry[i].setState_Live(NONE);
			m_My_Infantry[i].setPosX(rand()%(SCR_WIDTH/2));
			m_My_Infantry[i].setPosY(rand()%SCR_HEIGHT);
		}
		for(int i=0;i<EIN;i++)
		{
			m_Ey_Infantry[i].setState_Live(NONE);
			m_Ey_Infantry[i].setPosX(rand()%(SCR_WIDTH/2)+(SCR_WIDTH/2));
			m_Ey_Infantry[i].setPosY(rand()%SCR_HEIGHT);
		}
		for(int i=0;i<MAR;i++)
		{
			m_My_Archer[i].setState_Live(NONE);
			m_My_Archer[i].setPosY(550 + (rand()%20 - 10));
		}
		for(int i=0;i<EAR;i++)
		{
			m_Ey_Archer[i].setState_Live(NONE);
			m_Ey_Archer[i].setPosX(1300);
			m_Ey_Archer[i].setPosY(550 + (rand()%20 - 10));
		}
		for(int i=0;i<MCA;i++)
		{
			m_My_Cavalry[i].setState_Live(NONE);
			m_My_Cavalry[i].setPosX(-150);
			m_My_Cavalry[i].setPosY(550 + (rand()%20 - 10));
		}
		for(int i=0;i<ECA;i++)
		{
			m_Ey_Cavalry[i].setState_Live(NONE);
			m_Ey_Cavalry[i].setPosX(1300);
			m_Ey_Cavalry[i].setPosY(550 + (rand()%20 - 10));
		}
		for(int i=0;i<MPR;i++)
		{
			m_My_Priest[i].setState_Live(NONE);
			m_My_Priest[i].setPosX(-150);
			m_My_Priest[i].setPosY(550 + (rand()%20 - 10));
		}
		for(int i=0;i<EPR;i++)
		{
			m_Ey_Priest[i].setState_Live(NONE);
			m_Ey_Priest[i].setPosX(1300);
			m_Ey_Priest[i].setPosY(550 + (rand()%20 - 10));
		}

		for(int i=0;i<MSP;i++)
		{
			m_My_Spearman[i].setState_Live(NONE);
			m_My_Spearman[i].setPosX(-150);
			m_My_Spearman[i].setPosY(550 + (rand()%20 - 10));
		}
		for(int i=0;i<ESP;i++)
		{
			m_Ey_Spearman[i].setState_Live(NONE);
			m_Ey_Spearman[i].setPosX(1300);
			m_Ey_Spearman[i].setPosY(550 + (rand()%20 - 10));
		}

		for(int i=0;i<50;i++)
		{
			Snow[i].X = rand()%1200;
			Snow[i].Y = 0;
			Snow[i].XScale =  Snow[i].YScale = rand()%30 + 30;
			Snow[i].Width = 0;
			Snow[i].Live = false;
			Snow[i].Derection = 1;
			Snow[i].SnowSpeed = ( Snow[i].XScale / 100 ) * 3;

		}
	m_My_Infantry[0].setState_Live(LIVE);
	m_Ey_Infantry[0].setState_Live(LIVE);
	
	viewTime		= GetTickCount();
	startTime		= viewTime;

	obj1Pos.x		= 800;
	obj1Pos.y		= rand()%600;

	BlackAlpha = 0;
}
void cLogo::Update(float fElapsedTime){

	passTime = GetTickCount();

	for(int i=0; i<MaxSound01; i++)
	{
			AttackSound01[i].CheckPlayed(300);
	}
	for(int i=0; i<MaxSound02; i++)
	{
			AttackSound02[i].CheckPlayed(100);
	}
		
	for(int i=0; i<MaxSound01; i++)
	{
		AttackSound01[i].Update();
	}
	for(int i=0; i<MaxSound02; i++)
	{
		AttackSound02[i].Update();
	}
	for(int i=0; i<MaxSound01; i++)
	{
		AttackSound01[i].Update();
	}
	for(int i=0; i<MaxSound02; i++)
	{
		AttackSound02[i].Update();
	}

	for(int i=0;i<MIN;i++)
	{
		m_My_Infantry[i].Update(passTime,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP,1,&Logo_MoveRoute);	
	}
	for(int i=0; i<MAR; i++)
	{
		m_My_Archer[i].Update(passTime,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP);
	}
	for(int i=0; i<MCA;i++)
	{
		m_My_Cavalry[i].Update(passTime,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP);
	}
	for(int i=0; i<MSP;i++)
	{
		m_My_Spearman[i].Update(passTime,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP);
	}
	

	for(int i=0;i<EIN;i++)
	{
		m_Ey_Infantry[i].Update(passTime,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP,1,&Logo_MoveRoute);
	}
	for(int i=0; i<EAR; i++)
	{
		m_Ey_Archer[i].Update(passTime,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP);
	}
	for(int i=0; i<ECA; i++)
	{
		m_Ey_Cavalry[i].Update(passTime,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP);
	}
	for(int i=0; i<ESP; i++)
	{
		m_Ey_Spearman[i].Update(passTime,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP);
	}
	
	




	int i,j;
	
		//아군 보병 겹침방지(1)
		for(i=0;i<MIN;i++)
		{
			for(j=0;j<MIN;j++)
			{
				if(i == j)
					continue;
				if(m_My_Infantry[i].getHitTest() == 1 && m_My_Infantry[j].getHitTest() == 1)
				{
					if(	m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() > m_My_Infantry[j].getPosX()  &&
						m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() < m_My_Infantry[j].getPosX() + TILE_WIDTH &&
						m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() > m_My_Infantry[j].getPosY()  &&
						m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() < m_My_Infantry[j].getPosY() + TILE_HEIGHT &&

						m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() > m_My_Infantry[i].getPosX()  &&
						m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() < m_My_Infantry[i].getPosX() + TILE_WIDTH &&
						m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() > m_My_Infantry[i].getPosY()  &&
						m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() < m_My_Infantry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Infantry[i].getDistance() > m_My_Infantry[j].getDistance())
							m_My_Infantry[j].setHitTest(0);
						else if(m_My_Infantry[j].getDistance() > m_My_Infantry[i].getDistance())
							m_My_Infantry[i].setHitTest(0);
						else
							m_My_Infantry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MCA;j++)
			{
				if(m_My_Infantry[i].getHitTest() == 1 && m_My_Cavalry[j].getHitTest() == 1)
				{
					if(	m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() > m_My_Cavalry[j].getPosX()  &&
						m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() < m_My_Cavalry[j].getPosX() + TILE_WIDTH &&
						m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() > m_My_Cavalry[j].getPosY()  &&
						m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() < m_My_Cavalry[j].getPosY() + TILE_HEIGHT &&

						m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() > m_My_Infantry[i].getPosX()  &&
						m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() < m_My_Infantry[i].getPosX() + TILE_WIDTH &&
						m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() > m_My_Infantry[i].getPosY()  &&
						m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() < m_My_Infantry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Infantry[i].getDistance() > m_My_Cavalry[j].getDistance())
							m_My_Cavalry[j].setHitTest(0);
						else if(m_My_Cavalry[j].getDistance() > m_My_Infantry[i].getDistance())
							m_My_Infantry[i].setHitTest(0);
						else
							m_My_Cavalry[j].setHitTest(0);
					}
				}


			}
		}

		//적군 보병 겹침방지(1)
		for(i=0;i<EIN;i++)
		{

			for(j=0;j<EIN;j++)
			{
				if(i == j)
					continue;
				if(m_Ey_Infantry[i].getHitTest() == 1 && m_Ey_Infantry[j].getHitTest() == 1)
				{
					if(	m_Ey_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[i].getMoveSpeedX() > m_Ey_Infantry[j].getPosX()  &&
						m_Ey_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[i].getMoveSpeedX() < m_Ey_Infantry[j].getPosX() + TILE_WIDTH &&
						m_Ey_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[i].getMoveSpeedY() > m_Ey_Infantry[j].getPosY()  &&
						m_Ey_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[i].getMoveSpeedY() < m_Ey_Infantry[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() > m_Ey_Infantry[i].getPosX()  &&
						m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() < m_Ey_Infantry[i].getPosX() + TILE_WIDTH &&
						m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() > m_Ey_Infantry[i].getPosY()  &&
						m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() < m_Ey_Infantry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Infantry[i].getDistance() > m_Ey_Infantry[j].getDistance())
							m_Ey_Infantry[j].setHitTest(0);
						else if(m_Ey_Infantry[j].getDistance() > m_Ey_Infantry[i].getDistance())
							m_Ey_Infantry[i].setHitTest(0);
						else
							m_Ey_Infantry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<ECA;j++)
			{
				if(m_Ey_Infantry[i].getHitTest() == 1 && m_Ey_Cavalry[j].getHitTest() == 1)
				{
					if(	m_Ey_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[i].getMoveSpeedX() > m_Ey_Cavalry[j].getPosX()  &&
						m_Ey_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[i].getMoveSpeedX() < m_Ey_Cavalry[j].getPosX() + TILE_WIDTH &&
						m_Ey_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[i].getMoveSpeedY() > m_Ey_Cavalry[j].getPosY()  &&
						m_Ey_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[i].getMoveSpeedY() < m_Ey_Cavalry[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() > m_Ey_Infantry[i].getPosX()  &&
						m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() < m_Ey_Infantry[i].getPosX() + TILE_WIDTH &&
						m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() > m_Ey_Infantry[i].getPosY()  &&
						m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() < m_Ey_Infantry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Infantry[i].getDistance() > m_Ey_Cavalry[j].getDistance())
							m_Ey_Cavalry[j].setHitTest(0);
						else if(m_Ey_Cavalry[j].getDistance() > m_Ey_Infantry[i].getDistance())
							m_Ey_Infantry[i].setHitTest(0);
						else
							m_Ey_Cavalry[j].setHitTest(0);
					}
				}
			}

		}

		//실질적인 이동실행
		for(int i=0;i<MIN;i++)
		{
			m_My_Infantry[i].Move();	
		}

		for(int i=0;i<EIN;i++)
		{
			m_Ey_Infantry[i].Move();	
		}
		for(int i=0;i<MCA;i++)
		{
			m_My_Cavalry[i].Move();
		}

		for(int i=0;i<ECA;i++)
		{
			m_Ey_Cavalry[i].Move();	
		}




		//어그로 리셋
		for(int i=0;i<MIN;i++)
		{
			m_My_Infantry[i].Reset();	
		}

		for(int i=0;i<EIN;i++)
		{
			m_Ey_Infantry[i].Reset();	
		}


	for(int i=0;i<MIN;i++)
	{
		m_My_Infantry[i].CheckLive();
	}
	for(int i=0;i<EIN;i++)
	{
		m_Ey_Infantry[i].CheckLive();
	}
	for(int i=0; i<MAR; i++)
	{
		m_My_Archer[i].CheckLive();
	}
	for(int i=0; i<EAR; i++)
	{
		m_Ey_Archer[i].CheckLive();
	}
	for(int i=0; i<MCA; i++)
	{
		m_My_Cavalry[i].CheckLive();
	}
	for(int i=0; i<ECA; i++)
	{
		m_Ey_Cavalry[i].CheckLive();
	}
	for(int i=0; i<MPR; i++)
	{
		m_My_Priest[i].CheckLive();
	}
	for(int i=0; i<EPR; i++)
	{
		m_Ey_Priest[i].CheckLive();
	}
	for(int i=0; i<MSP; i++)
	{
		m_My_Spearman[i].CheckLive();
	}
	for(int i=0; i<ESP; i++)
	{
		m_Ey_Spearman[i].CheckLive();
	}


	if(REBIRTHABLE == true){
	for(int i=0;i<MCA;i++)
	{
		if(m_My_Cavalry[i].getState_Live() == DEAD)
		{
			m_My_Cavalry[i].Init();
			m_My_Cavalry[i].setPosX(-150);
			m_My_Cavalry[i].setPosY(550 + (rand()%20 - 10));//setPosY(550);
			m_My_Cavalry[i].setState_Live(LIVE);
		}
	}
	for(int i=0;i<ECA;i++)
	{
		if(m_Ey_Cavalry[i].getState_Live() == DEAD)
		{
			m_Ey_Cavalry[i].Init();
			m_Ey_Cavalry[i].setPosX(1300);
			m_Ey_Cavalry[i].setPosY(550 + (rand()%20 - 10));//setPosY(550);
			//m_Ey_Cavalry[i].setMoveSpeed(m_Ey_Cavalry[i].getMoveSpeed() * -1);
			m_Ey_Cavalry[i].setState_Live(LIVE);
		}
	}


	for(int i=0;i<MIN;i++)
	{
		if(m_My_Infantry[i].getState_Live() == DEAD)
		{
			m_My_Infantry[i].Init();
			m_My_Infantry[i].setPosX(rand()%(SCR_WIDTH/2));
			m_My_Infantry[i].setPosY(rand()%SCR_HEIGHT);
			m_My_Infantry[i].setState_Live(LIVE);
		}
	}
	for(int i=0;i<EIN;i++)
	{
		if(m_Ey_Infantry[i].getState_Live() == DEAD)
		{
			m_Ey_Infantry[i].Init();
			m_Ey_Infantry[i].setPosX(rand()%(SCR_WIDTH/2)+(SCR_WIDTH/2));
			m_Ey_Infantry[i].setPosY(rand()%SCR_HEIGHT);
			m_Ey_Infantry[i].setState_Live(LIVE);
		}
	}

	for(int i=0;i<MAR;i++)
	{
		if(m_My_Archer[i].getState_Live() == DEAD)
		{
			m_My_Archer[i].Init();
			m_My_Archer[i].setPosX(-150);
			m_My_Archer[i].setPosY(550 + (rand()%20 - 10));
			m_My_Archer[i].setState_Live(LIVE);
		}
	}
	for(int i=0;i<EAR;i++)
	{
		if(m_Ey_Archer[i].getState_Live() == DEAD)
		{
			m_Ey_Archer[i].Init();
			m_Ey_Archer[i].setPosX(1300);
			m_Ey_Archer[i].setPosY(550 + (rand()%20 - 10));
		//	m_Ey_Archer[i].setMoveSpeed(m_Ey_Archer[i].getMoveSpeed() * -1);
			m_Ey_Archer[i].setState_Live(LIVE);
		}
	}
	
	for(int i=0;i<MPR;i++)
	{
		if(m_My_Priest[i].getState_Live() == DEAD)
		{
			m_My_Priest[i].Init();
			m_My_Priest[i].setPosX(-150);
			m_My_Priest[i].setPosY(550 + (rand()%20 - 10));
			m_My_Priest[i].setState_Live(LIVE);
		}
	}
	for(int i=0;i<EPR;i++)
	{
		if(m_Ey_Priest[i].getState_Live() == DEAD)
		{
			m_Ey_Priest[i].Init();
			m_Ey_Priest[i].setPosX(1300);
			m_Ey_Priest[i].setPosY(550 + (rand()%20 - 10));
		//	m_Ey_Priest[i].setMoveSpeed(m_Ey_Priest[i].getMoveSpeed() * -1);
			m_Ey_Priest[i].setState_Live(LIVE);
		}
	}
	for(int i=0;i<MSP;i++)
	{
		if(m_My_Spearman[i].getState_Live() == DEAD)
		{
			m_My_Spearman[i].Init();
			m_My_Spearman[i].setPosX(-150);
			m_My_Spearman[i].setPosY(550 + (rand()%20 - 10));
			m_My_Spearman[i].setState_Live(LIVE);
		}
	}
	for(int i=0;i<ESP;i++)
	{
		if(m_Ey_Spearman[i].getState_Live() == DEAD)
		{
			m_Ey_Spearman[i].Init();
			m_Ey_Spearman[i].setPosX(1300);
			m_Ey_Spearman[i].setPosY(550 + (rand()%20 - 10));
		//	m_Ey_Spearman[i].setMoveSpeed(m_Ey_Spearman[i].getMoveSpeed() * -1);
			m_Ey_Spearman[i].setState_Live(LIVE);
		}
	}

	}
	//b_Start.CheckOver(x,y);

	for(int i=0; i<50; i++)
	{
		if(Snow[i].Live == true)
		{
			Snow[i].Y += Snow[i].SnowSpeed;
			Snow[i].SnowSpeed += 0.005;
			Snow[i].X += SnowSpeed * Snow[i].Derection;
			Snow[i].Width += SnowSpeed * Snow[i].Derection;
			if(Snow[i].Width > 40 || Snow[i].Width < -40)
			{
				Snow[i].Width = 0;
				Snow[i].Derection *= -1;
			}

			if(Snow[i].Y > 750)
			{
				Snow[i].Live = false;
				Snow[i].X = rand()%1200;
				Snow[i].Y = 0;
				Snow[i].XScale =  Snow[i].YScale = rand()%30 + 30;
				Snow[i].Width = 0;
				Snow[i].Derection = 1;
				Snow[i].SnowSpeed = ( Snow[i].XScale / 100 ) * 3;
			}
		}
	}
	static DWORD SnowTime = 0;
	if(passTime - SnowTime >= SnowRegenTime)
	{
		SnowTime			= passTime;
		for(int i=0; i<50; i++)
		{
			if(Snow[i].Live == false)
			{
				Snow[i].Live = true;
				break;
			}
		}
	}
	if(passTime - viewTime >= RegenTime)
	{
		viewTime			= passTime;
		for(int i=0;i<50;i++)
		{
			
		}
		for(int i=0;i<MAR;i++)
		{
			if(m_My_Archer[i].getState_Live() == NONE)
			{
				//m_My_Archer[i].setMoveSpeed((m_My_Archer[i].getMoveSpeed()/100) * ((rand()%30) + 70));
				m_My_Archer[i].setState_Live(LIVE);
				break;
			}
		}
		for(int i=0;i<EAR;i++)
		{
			if(m_Ey_Archer[i].getState_Live() == NONE)
			{
				//m_Ey_Archer[i].setMoveSpeed((m_Ey_Archer[i].getMoveSpeed()/100) * ((rand()%30) + 70));
				m_Ey_Archer[i].setState_Live(LIVE);
				break;
			}
		}
		for(int i=0;i<MIN;i++)
		{
			if(m_My_Infantry[i].getState_Live() == NONE)
			{
				//m_My_Infantry[i].setMoveSpeed((m_My_Infantry[i].getMoveSpeed()/100) * ((rand()%30) + 70));
				m_My_Infantry[i].setState_Live(LIVE);
				break;
			}
		}
		for(int i=0;i<EIN;i++)
		{
			if(m_Ey_Infantry[i].getState_Live() == NONE)
			{
				//m_Ey_Infantry[i].setMoveSpeed((m_Ey_Infantry[i].getMoveSpeed()/100) * ((rand()%30) + 70));
				m_Ey_Infantry[i].setState_Live(LIVE);
				break;
			}
		}

		for(int i=0;i<MCA;i++)
		{
			if(m_My_Cavalry[i].getState_Live() == NONE)
			{
				//m_My_Infantry[i].setMoveSpeed((m_My_Infantry[i].getMoveSpeed()/100) * ((rand()%30) + 70));
				m_My_Cavalry[i].setState_Live(LIVE);
				break;
			}
		}
		for(int i=0;i<ECA;i++)
		{
			if(m_Ey_Cavalry[i].getState_Live() == NONE)
			{
				//m_My_Infantry[i].setMoveSpeed((m_My_Infantry[i].getMoveSpeed()/100) * ((rand()%30) + 70));
				m_Ey_Cavalry[i].setState_Live(LIVE);
				break;
			}
		}

		for(int i=0;i<MPR;i++)
		{
			if(m_My_Priest[i].getState_Live() == NONE)
			{
				//m_My_Infantry[i].setMoveSpeed((m_My_Infantry[i].getMoveSpeed()/100) * ((rand()%30) + 70));
				m_My_Priest[i].setState_Live(LIVE);
				break;
			}
		}
		for(int i=0;i<EPR;i++)
		{
			if(m_Ey_Priest[i].getState_Live() == NONE)
			{
				//m_My_Infantry[i].setMoveSpeed((m_My_Infantry[i].getMoveSpeed()/100) * ((rand()%30) + 70));
				m_Ey_Priest[i].setState_Live(LIVE);
				break;
			}
		}
		for(int i=0;i<MSP;i++)
		{
			if(m_My_Spearman[i].getState_Live() == NONE)
			{
				//m_My_Infantry[i].setMoveSpeed((m_My_Infantry[i].getMoveSpeed()/100) * ((rand()%30) + 70));
				m_My_Spearman[i].setState_Live(LIVE);
				break;
			}
		}
		for(int i=0;i<ESP;i++)
		{
			if(m_Ey_Spearman[i].getState_Live() == NONE)
			{
				//m_My_Infantry[i].setMoveSpeed((m_My_Infantry[i].getMoveSpeed()/100) * ((rand()%30) + 70));
				m_Ey_Spearman[i].setState_Live(LIVE);
				break;
			}
		}
	}

	/*if(passTime - startTime >= 30000)
	{
		g_Game.gotoPlay(MENU);
	}*/
	obj1Pos.x -= (rand()%3+1)+3;
	if(obj1Pos.x<=0)
	{
		obj1Pos.x		= 800;
	obj1Pos.y		= rand()%600;
	}
	
}
void cLogo::Render()
{
	m_Logo_BGImg.Draw(0,0);
	/*m_Logo_Limit.Draw(0,0,0,0,900,350,900,350,RGB(255,0,255));*/

	for(int i=0; i<MAR; i++)
	{
		if(m_My_Archer[i].getState_Live() == LIVE)
		{
			m_My_ArcherImg.Draw(m_My_Archer[i].getPosX(),m_My_Archer[i].getPosY());
			
		}
		
	
	}
	for(int i=0; i<EAR; i++)
	{
		if(m_Ey_Archer[i].getState_Live() == LIVE)
		{
			m_Ey_ArcherImg.Draw(m_Ey_Archer[i].getPosX(),m_Ey_Archer[i].getPosY());
			
		}
		
	
	}
	d_OFFSET offset;
	offset.x = 0;
	offset.y = 0;
	for(int i=0;i<MIN;i++)
	{
		if(m_My_Infantry[i].getState_Live() == LIVE)
			{
				if(m_My_Infantry[i].Attack == false)
				{
					
					m_My_InfantryImg.Draw(m_My_Infantry[i].getPosX() - offset.x,m_My_Infantry[i].getPosY() - offset.y);
				}
				else if(m_My_Infantry[i].Attack == true)
				{
					m_My_Infantry[i].Render(offset);
				}
			}
	}
	for(int i=0;i<EIN;i++)
	{
		if(m_Ey_Infantry[i].getState_Live() == LIVE)
		m_Ey_InfantryImg.Draw(m_Ey_Infantry[i].getPosX(),m_Ey_Infantry[i].getPosY());
	}

	for(int i=0;i<MCA;i++)
	{
		if(m_My_Cavalry[i].getState_Live() == LIVE)
		m_My_CavalryImg.Draw(m_My_Cavalry[i].getPosX(),m_My_Cavalry[i].getPosY());
	}
	for(int i=0;i<ECA;i++)
	{
		if(m_Ey_Cavalry[i].getState_Live() == LIVE)
		m_Ey_CavalryImg.Draw(m_Ey_Cavalry[i].getPosX(),m_Ey_Cavalry[i].getPosY());
	}
	
	for(int i=0;i<MSP;i++)
	{
		if(m_My_Spearman[i].getState_Live() == LIVE)
		m_My_SpearmanImg.Draw(m_My_Spearman[i].getPosX(),m_My_Spearman[i].getPosY());
		
	}
	for(int i=0;i<ESP;i++)
	{
		if(m_Ey_Spearman[i].getState_Live() == LIVE)
		m_Ey_SpearmanImg.Draw(m_Ey_Spearman[i].getPosX(),m_Ey_Spearman[i].getPosY());
		
	}



	//프리스트렌더는 힐붙어있음 맨뒤로 ㅋ
	for(int i=0;i<MPR;i++)
	{
		if(m_My_Priest[i].getState_Live() == LIVE)
		m_My_PriestImg.Draw(m_My_Priest[i].getPosX(),m_My_Priest[i].getPosY());
		d_OFFSET offset;
		offset.x = 0;
		offset. y = 0;
		m_My_Priest[i].Render(offset);
	}
	for(int i=0;i<EPR;i++)
	{
		if(m_Ey_Priest[i].getState_Live() == LIVE)
		m_Ey_PriestImg.Draw(m_Ey_Priest[i].getPosX(),m_Ey_Priest[i].getPosY());
		d_OFFSET offset;
		offset.x = 0;
		offset. y = 0;
		m_Ey_Priest[i].Render(offset);
	}



	//
	for(int i=0;i<MIN;i++)
	{
		if(m_My_Infantry[i].getState_Live() == LIVE)
		{
			sprintf(strTemp,"%d / %d",m_My_Infantry[i].getHp(),m_My_Infantry[i].getMaxHp());
			g_Graphics.DrawString(m_My_Infantry[i].getPosX(),m_My_Infantry[i].getPosY()-20,strTemp);
		}
	}
	for(int i=0;i<EIN;i++)
	{
	if(m_Ey_Infantry[i].getState_Live() == LIVE)
		{
			sprintf(strTemp,"%d / %d",m_Ey_Infantry[i].getHp(),m_Ey_Infantry[i].getMaxHp());
			g_Graphics.DrawString(m_Ey_Infantry[i].getPosX(),m_Ey_Infantry[i].getPosY()-20,strTemp);
		}
	}
	for(int i=0; i<MAR; i++)
	{
		if(m_My_Archer[i].getState_Live() == LIVE)
		{
			sprintf(strTemp,"%d / %d",m_My_Archer[i].getHp(),m_My_Archer[i].getMaxHp());
			g_Graphics.DrawString(m_My_Archer[i].getPosX(),m_My_Archer[i].getPosY()-20,strTemp);
		}
	}

	for(int i=0; i<EAR; i++)
	{
		if(m_Ey_Archer[i].getState_Live() == LIVE)
		{
			sprintf(strTemp,"%d / %d",m_Ey_Archer[i].getHp(),m_Ey_Archer[i].getMaxHp());
			g_Graphics.DrawString(m_Ey_Archer[i].getPosX(),m_Ey_Archer[i].getPosY()-20,strTemp);
	
		}
	}

	for(int i=0;i<MCA;i++)
	{
		if(m_My_Cavalry[i].getState_Live() == LIVE)
		{
			sprintf(strTemp,"%d / %d",m_My_Cavalry[i].getHp(),m_My_Cavalry[i].getMaxHp());
			g_Graphics.DrawString(m_My_Cavalry[i].getPosX(),m_My_Cavalry[i].getPosY()-20,strTemp);
		}
	}
	for(int i=0;i<ECA;i++)
	{
		if(m_Ey_Cavalry[i].getState_Live() == LIVE)
		{
			sprintf(strTemp,"%d / %d",m_Ey_Cavalry[i].getHp(),m_Ey_Cavalry[i].getMaxHp());
			g_Graphics.DrawString(m_Ey_Cavalry[i].getPosX(),m_Ey_Cavalry[i].getPosY()-20,strTemp);
		}
	}

	for(int i=0;i<MPR;i++)
	{
		if(m_My_Priest[i].getState_Live() == LIVE)
		{
			sprintf(strTemp,"%d / %d",m_My_Priest[i].getHp(),m_My_Priest[i].getMaxHp());
			g_Graphics.DrawString(m_My_Priest[i].getPosX(),m_My_Priest[i].getPosY()-20,strTemp);
		}
	}
	for(int i=0;i<EPR;i++)
	{
		if(m_Ey_Priest[i].getState_Live() == LIVE)
		{
			sprintf(strTemp,"%d / %d",m_Ey_Priest[i].getHp(),m_Ey_Priest[i].getMaxHp());
			g_Graphics.DrawString(m_Ey_Priest[i].getPosX(),m_Ey_Priest[i].getPosY()-20,strTemp);
		}
	}
	for(int i=0;i<MSP;i++)
	{
		if(m_My_Spearman[i].getState_Live() == LIVE)
		{
			sprintf(strTemp,"%d / %d",m_My_Spearman[i].getHp(),m_My_Spearman[i].getMaxHp());
			g_Graphics.DrawString(m_My_Spearman[i].getPosX(),m_My_Spearman[i].getPosY()-20,strTemp);
		}
	}
	for(int i=0;i<ESP;i++)
	{
		if(m_Ey_Spearman[i].getState_Live() == LIVE)
		{
			sprintf(strTemp,"%d / %d",m_Ey_Spearman[i].getHp(),m_Ey_Spearman[i].getMaxHp());
			g_Graphics.DrawString(m_Ey_Spearman[i].getPosX(),m_Ey_Spearman[i].getPosY()-20,strTemp);
		}
	}
	


	
	
	for(int i=0; i<MAR; i++)
	{
		if(m_My_Archer[i].Arrow->getLive() == true)
				m_ArrowImg.Draw(m_My_Archer[i].Arrow->getPosX(),m_My_Archer[i].Arrow->getPosY());
	}


	for(int i=0; i<EAR; i++)
	{
		if(m_Ey_Archer[i].Arrow->getLive() == true)
				m_ArrowImg.Draw(m_Ey_Archer[i].Arrow->getPosX(),m_Ey_Archer[i].Arrow->getPosY());
	}



	
	for(int i=0; i<MPR;i++)
	{
		m_My_Priest[i].Update(passTime,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP);
	}
	for(int i=0; i<EPR; i++)
	{
		m_Ey_Priest[i].Update(passTime,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP);
	}


	for(int i=0; i<50; i++)
	{
		if(Snow[i].Live == true)
		{
			m_SnowImg.Draw(Snow[i].X,Snow[i].Y,0,0,Snow[i].XScale,Snow[i].YScale,100,100,RGB(0,255,0));
		}
	}

	
	g_Graphics.DrawString(550,500,"Touch!");

	if(AlphaOn == true)
		BlackAlpha+=5;
	if(BlackAlpha>=250)
		g_Game.gotoPlay(MENU);
	if(AlphaOn == true)
	m_BlackGroundImg.AlphaDraw(0,0,0,0,1200,750,1200,750,BlackAlpha);
}
int cLogo::Destroy()
{
	delete []m_My_Infantry;
	delete []m_Ey_Infantry;
	delete []m_My_Archer;
	delete []m_Ey_Archer;
	delete []m_My_Cavalry;
	delete []m_Ey_Cavalry;
	delete []m_My_Priest;
	delete []m_Ey_Priest;
	delete []m_My_Spearman;
	delete []m_Ey_Spearman;
	m_My_InfantryImg.Destroy();
	m_Ey_InfantryImg.Destroy();
	m_My_ArcherImg.Destroy();
	m_Ey_ArcherImg.Destroy();
	m_My_CavalryImg.Destroy();
	m_Ey_CavalryImg.Destroy();
	m_My_PriestImg.Destroy();
	m_Ey_PriestImg.Destroy();
	m_My_SpearmanImg.Destroy();
	m_Ey_SpearmanImg.Destroy();
	m_Logo_BGImg.Destroy();
	m_ArrowImg.Destroy();
	m_Image.Destroy();
	m_SnowImg.Destroy();
	m_LogoBGM.DeleteSound();

	return MENU;
}
LRESULT cLogo::MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch(iMessage)
	{
		case WM_LBUTTONDOWN:
			
			AlphaOn = true;
			//b_Start.CheckDown(x,y);
		break;
		case WM_LBUTTONUP:
			//if(b_Start.CheckUp(x,y) == true)
			//{
			//	//실행문장
			//	g_Game.gotoPlay(MENU);
			//}
		break;
		case WM_MOUSEMOVE:
			x = LOWORD(lParam);
			y = HIWORD(lParam);
		break;

		case WM_KEYDOWN:
		//g_Game.gotoPlay(MENU);
		break;

		case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

}
	return (DefWindowProc(hWnd,iMessage,wParam,lParam));
}

