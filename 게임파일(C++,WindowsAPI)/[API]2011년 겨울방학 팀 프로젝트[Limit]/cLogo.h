#pragma once
#include "cState.h"
#include "cGdiImage.h"
#include "sceneManager.h"
#include "fmodSound.h"
#include "cButton.h"

#include "sceneManager.h"
#include "UnitList.h"
using namespace std;

typedef struct _pos
{
	int x;
	int y;

}Pos;

typedef struct _snow
{
	double X;
	double Y;
	double XScale;
	double YScale;
	double Width;
	bool Live;
	int Derection;
	double SnowSpeed;
}Snow;
class cLogo : public cState
{
	DWORD			viewTime;
	DWORD			startTime;
	DWORD			passTime;

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
	bool AlphaOn;
public:
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
	cGdiImage	m_Logo_BGImg;
	cGdiImage	m_ArrowImg;
	cGdiImage	m_BlackGroundImg;

	cGdiImage	m_SnowImg;
	int BlackAlpha;
	Snow Snow[50];
	/*
	cGdiImage	m_Logo_Limit;*/
	fSound m_LogoBGM;
	cGdiImage m_Image;
	cLogo();
	~cLogo();

	void InitState();
	void Update(float fElapsedTime);
	void Render();
	int Destroy();
	LRESULT MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
	
};