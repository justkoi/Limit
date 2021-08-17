#pragma once
#include <vector>
#include <iterator>
#include "cState.h"
#include "MY_Define.h"
#include "cGdiImage.h"
#include "fmodSound.h"
#include "sceneManager.h"
#include "UnitList.h"
#include "cSpell.h"
#include "Struct.h"
using namespace std;

typedef struct _unitlist
{
	int Type;
	double X;
	double Y;
	bool Used;
}UnitList;


class cGame : public cState
{
	//cSceneManager m_Ani;
	
	//정적할당
	//Node		m_NodeList[32];
	//cInfantry* m_Ey_Infantry;
	//cUnit m_My_Infantry;
	DWORD startTime;
	DWORD passTime;
	int m_SelectMenu;
	int m_SelectUnit;
	bool m_ShowInv;
	d_OFFSET offset;
	bool m_Grid_OnOff;

	
	cInfantry* m_My_Infantry;
	cInfantry* m_Ey_Infantry;
	cArcher*   m_My_Archer;
	cArcher*   m_Ey_Archer;
	cCavalry*  m_My_Cavalry;
	cCavalry*  m_Ey_Cavalry;
	cPriest*   m_My_Priest;
	cPriest*   m_Ey_Priest;
	cSpearman* m_My_Spearman;
	cSpearman* m_Ey_Spearman;

	MoveRoute* My_MoveRoute;
	MoveRoute* Ey_MoveRoute;
	int	Max_My_MoveRoute;
	int	Max_Ey_MoveRoute;

	int MIN;
	int MAR;
	int MCA;
	int MPR;
	int MSP;
	
	int EIN; // Ey Infantry Num
	int EAR;
	int ECA;
	int EPR;
	int ESP;


	int m_My_InfantryCount;
	int m_My_ArcherCount;
	int m_My_CavalryCount;
	int m_My_PriestCount;
	int m_My_SpearmanCount;

	
	int m_Ey_InfantryCount;
	int m_Ey_ArcherCount;
	int m_Ey_CavalryCount;
	int m_Ey_PriestCount;
	int m_Ey_SpearmanCount;

	cSpell Spell;
public:
	//fSound m_BS;
	cGdiImage	m_My_InfantryImg;
	cGdiImage	m_Ey_InfantryImg;
	cGdiImage	m_My_ArcherImg;
	cGdiImage	m_Ey_ArcherImg;
	cGdiImage	m_My_CavalryImg;
	cGdiImage	m_Ey_CavalryImg;
	cGdiImage	m_My_PriestImg;
	cGdiImage	m_Ey_PriestImg;
	cGdiImage	m_My_SpearmanImg;
	cGdiImage	m_Ey_SpearmanImg;
	cGdiImage	m_ArrowImg;
	cGdiImage	m_GridImg;
	cGdiImage	m_BlackGround;
	cGdiImage	m_RedGround;

	cGdiImage	m_Interface01;
	cGdiImage	m_Interface02;



	int BlackAlpha;
	int BlackAlphaReturn;

	//타일이미지

	cGdiImage m_Tile_Grass01;
	cGdiImage m_Tile_Grass02;
	cGdiImage m_Tile_Grass03;
	cGdiImage m_Tile_Grass04;

	cGdiImage m_End_Victory;

	cGdiImage m_Hp_Max;
	cGdiImage m_Hp;
	fSound		Game_Win;
	fSound		Game_Lose;
	int GameStep;
	int GameResult;
	cGame();
	~cGame();

	void CreateUnit();
	void InitState();
	void Update(float fElapsedTime);
	void Render();
	int Destroy();
	void KeyCheck();
	void wHeelCheck();
	int HitTest_Circle(double ptx,double pty, double CircleCenterX,double CircleCenterY, double Radius);
	bool HitTest_Unit(int Num,cInfantry* mInfantry,int MMI);
	LRESULT MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	
};