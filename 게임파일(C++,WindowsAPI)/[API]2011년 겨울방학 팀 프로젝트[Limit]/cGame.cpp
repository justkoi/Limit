#include "MY_include.h"

//렉최소화 for문구문 실제 게임 적용시 넣을것!

//for(int j=(int)(offset.y/TILE_HEIGHT); j<(int)(offset.y/TILE_HEIGHT) + 8; j++)
//		{
//			for(int i=(int)(offset.x/TILE_WIDTH); i<(int)(offset.x/TILE_WIDTH) + 8; i++)
//			{

int AlphaSpeed = 5;
#define WM_MOUSEHWHEEL 0x020A

int g_zDelta = 0;

int SelectMap_Height = 20;
int SelectMap_Width = 30;

cButton Game_b_Back(0,0,175,100);
//
//int TileMap[Stage1_Map_Height][Stage1_Map_Width] = 
//{
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//};
//
//int WallMap[Stage1_Map_Height][Stage1_Map_Width]= 
//{
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//};
//int TerrainMap[Stage1_Map_Height][Stage1_Map_Width] = 
//{
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//};
//int Enemy_TileMap[Stage1_Map_Height][Stage1_Map_Width] = 
//{
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//};

int** TileMap = NULL ;

int** Enemy_TileMap = NULL ;

int** TerrainMap = NULL ;

int** WallMap = NULL ;

int MapScale = 100;
int MapScaleTemp = 0;
const int ScaleSpeed = 2;
const double CameraSpeed = 5.0000;

cGame::cGame()
{

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

	
	m_BlackGround.SetDC(g_Graphics.getGraphicsDC());
	m_BlackGround.Load("./Image/Effect/BlackGround.bmp");

	m_RedGround.SetDC(g_Graphics.getGraphicsDC());
	m_RedGround.Load("./Image/Effect/RedGround.bmp");


	m_GridImg.SetDC(g_Graphics.getGraphicsDC());
	m_GridImg.Load("./Image/Effect/Grid_White.bmp");


	m_Tile_Grass01.SetDC(g_Graphics.getGraphicsDC());
	m_Tile_Grass01.Load("./Image/Tile/Grass_01.bmp");

	m_Tile_Grass02.SetDC(g_Graphics.getGraphicsDC());
	m_Tile_Grass02.Load("./Image/Tile/Grass_02.bmp");

	m_Tile_Grass03.SetDC(g_Graphics.getGraphicsDC());
	m_Tile_Grass03.Load("./Image/Tile/Grass_03.bmp");

	m_Tile_Grass04.SetDC(g_Graphics.getGraphicsDC());
	m_Tile_Grass04.Load("./Image/Tile/Grass_04.bmp");


	m_Interface01.SetDC(g_Graphics.getGraphicsDC());
	m_Interface01.Load("./Image/State/Game_Interface_01.bmp");

	
	m_Interface02.SetDC(g_Graphics.getGraphicsDC());
	m_Interface02.Load("./Image/State/Game_Interface_02.bmp");

	m_End_Victory.SetDC(g_Graphics.getGraphicsDC());
	m_End_Victory.Load("./Image/State/Game_Victory.bmp");
	
	m_Hp_Max.SetDC(g_Graphics.getGraphicsDC());
	m_Hp_Max.Load("./Image/Effect/Hp_Max.bmp");
	
	m_Hp.SetDC(g_Graphics.getGraphicsDC());
	m_Hp.Load("./Image/Effect/Hp.bmp");

	Game_Win.SoundLoad("./Sound/Game_Win.wav",false);
	Game_Lose.SoundLoad("./Sound/Game_Lose.wav",false);
	offset.x = 0;
	offset.y = 0;

	m_Grid_OnOff = false;

	MIN = 0;
	MAR = 0;
	MCA = 0;
	MPR = 0;
	MSP = 0;

	m_My_InfantryCount		=	0;
	m_My_ArcherCount		=	0;
	m_My_CavalryCount		=	0;
	m_My_PriestCount		=	0;
	m_My_SpearmanCount		=	0;

	m_Ey_InfantryCount		=	0;
	m_Ey_ArcherCount		=	0;
	m_Ey_CavalryCount		=	0;
	m_Ey_PriestCount		=	0;
	m_Ey_SpearmanCount		=	0;

	EIN = 0; // Ey Infantry Num
	EAR = 0;
	ECA = 0;
	EPR = 0;
	ESP = 0;
}
cGame::~cGame(){
}

int cGame::HitTest_Circle(double ptx, double pty, double CircleCenterX,double CircleCenterY, double Radius) // 점의 x, y좌표 원의 중심x,y 좌표, 원의 반지름

{

        double TempX = abs(CircleCenterX  - ptx );

        double TempY = abs(CircleCenterY - pty );
 
        int distance =  sqrt(TempX*TempX + TempY * TempY);

 

        if(distance <= Radius)

        {

                return TRUE;

        }

        else

                return FALSE;

}

//유닛충돌테스트
bool cGame::HitTest_Unit(int Num,cInfantry* mInfantry,int MMI)
{
	if(mInfantry[Num].getState_Live() == LIVE && mInfantry[Num].getState_Move() == WALK)
	{
		int i = 0;
		for(i=0; i<MMI; i++)
		{
			if(i == Num)
				continue;

			if(mInfantry[Num].getState_Live() == LIVE && //나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면 // 방향을 튕겨 검사
				mInfantry[i].getPosX() + (TILE_WIDTH/2) > mInfantry[Num].getPosX() + mInfantry[Num].getMoveSpeedX() && mInfantry[i].getPosX() + (TILE_WIDTH/2) < mInfantry[Num].getPosX() + mInfantry[Num].getMoveSpeedX()  + TILE_WIDTH &&
				mInfantry[i].getPosY() + (TILE_HEIGHT/2) > mInfantry[Num].getPosY() + mInfantry[Num].getMoveSpeedY() && mInfantry[i].getPosY() + (TILE_HEIGHT/2) < mInfantry[Num].getPosY() + mInfantry[Num].getMoveSpeedY()  + TILE_HEIGHT
			  )
			{
				return false;
			}
		}
		if(i == MMI)
			return true;
	}
	else
		return false;
}

void cGame::InitState()
{
	char * Level;

	
	Game_b_Back.ButtonImgLoad("./Image/Button/b_Back.bmp","./Image/Button/b_Back_over.bmp");
	if(SelectLevel == EASY)
		Level = "Easy";
	else if(SelectLevel == NORMAL)
		Level = "Normal";
	else if(SelectLevel == HARD)
		Level = "Hard";

	//배열크기읽어와서 동적할당
	
	char FileName[256];
	sprintf(FileName,"./MapSize/%s/Stage%d.txt",Level,SelectStage);

	FILE * fp = fopen(FileName,"rt");

	fscanf(fp,"%d",&SelectMap_Width);
	fscanf(fp,"%d",&SelectMap_Height);


	// 주의! 메모리 // 2차원 동적배열 할당과정.
	//*************************************************************************
	//타일맵 할당(아군)
    TileMap = new int*[SelectMap_Height];
     
	//메모리 초기화
    for( int i = 0 ; i < SelectMap_Height; i++ )
     {
            TileMap[i] = new int[SelectMap_Width] ;
            memset( TileMap[i], 0, sizeof(int)*SelectMap_Width) ;
     }
	
	

	//*************************************************************************
	//타일맵 할당(적군)
    Enemy_TileMap = new int*[SelectMap_Height];
     
	//메모리 초기화
    for( int i = 0 ; i < SelectMap_Height ; i++ )
     {
            Enemy_TileMap[i] = new int[SelectMap_Width] ;
            memset( Enemy_TileMap[i], 0, sizeof(int)*SelectMap_Width ) ;
     }

	//*************************************************************************
	//타일맵 할당(지형)
    TerrainMap = new int*[SelectMap_Height];
     
	//메모리 초기화
    for( int i = 0 ; i < SelectMap_Height ; i++ )
     {
            TerrainMap[i] = new int[SelectMap_Width] ;
            memset( TerrainMap[i], 0, sizeof(int)*SelectMap_Width ) ;
     }
	//*************************************************************************
	//타일맵 할당(장애물)
    WallMap = new int*[SelectMap_Height];
     
	//메모리 초기화
    for( int i = 0 ; i < SelectMap_Height ; i++ )
     {
            WallMap[i] = new int[SelectMap_Width] ;
            memset( WallMap[i], 0, sizeof(int)*SelectMap_Width ) ;
     }


	sprintf(FileName,"./TerrainMap/%s/Stage%d.txt",Level,SelectStage);

	fp = fopen(FileName,"rt");
	for(int i=0;i<SelectMap_Height;i++)
	{
		for(int j=0;j<SelectMap_Width;j++)
		{
			WallMap[i][j] = fgetc(fp) - '0';
			if(WallMap[i][j] == 1)
			{
				TerrainMap[i][j] = rand()%4+101;//101,102,103,104중 랜덤으로 저장
			}
		}
		fgetc(fp);
	}
	
	
	sprintf(FileName,"./EnemyMap/%s/Stage%d.txt",Level,SelectStage);

	fp = fopen(FileName,"rt");
	for(int i=0;i<SelectMap_Height;i++)
	{
		for(int j=0;j<SelectMap_Width;j++)
		{
			Enemy_TileMap[i][j] = fgetc(fp) - '0';
		}
		fgetc(fp);
	}



	////////////////////////루트맵 아군
	
	sprintf(FileName,"./MyRouteMap/%s/Stage%d.txt",Level,SelectStage);
	
	fp = fopen(FileName,"rt");

	fscanf(fp,"%d",&Max_My_MoveRoute);

	My_MoveRoute = new MoveRoute[Max_My_MoveRoute];
	int * TempArr = new int[Max_My_MoveRoute];
	for(int i=0; i<Max_My_MoveRoute; i++)
	{
		fscanf(fp,"%lf",&My_MoveRoute[i].Range_Width);		//점의 X가 0일경우 Width가 100이면 0~100까지 범위판정
		fscanf(fp,"%lf",&My_MoveRoute[i].Range_Height);		
	}

	int count = 0;
	fgetc(fp);
	for(int i=0;i<SelectMap_Height;i++)
	{
		for(int j=0;j<SelectMap_Width;j++)
		{
			int Temp =  fgetc(fp) - '0';
			if(Temp != 0)
			{
				TempArr[count] = Temp;
				My_MoveRoute[count].X = TILE_WIDTH * j;
				My_MoveRoute[count].Y = TILE_HEIGHT * i;
				count++;
			}
		}
		fgetc(fp);
	}

	for(int i=0; i<Max_My_MoveRoute; i++)
	{
		for(int j=0; j<Max_My_MoveRoute - i -1; j++)
		{
			if(TempArr[j] > TempArr[j+1])
			{
				int Temp = TempArr[j];
				TempArr[j] = TempArr[j+1];
				TempArr[j+1] = Temp;

				double Temp2 = My_MoveRoute[j].X;
				My_MoveRoute[j].X = My_MoveRoute[j+1].X;
				My_MoveRoute[j+1].X = Temp2;

				double Temp3 = My_MoveRoute[j].Y;
				My_MoveRoute[j].Y = My_MoveRoute[j+1].Y;
				My_MoveRoute[j+1].Y = Temp3;

				
				double Temp4 = My_MoveRoute[j].Range_Width;
				My_MoveRoute[j].Range_Width = My_MoveRoute[j+1].Range_Width;
				My_MoveRoute[j+1].Range_Width = Temp4;

				
				double Temp5 = My_MoveRoute[j].Range_Height;
				My_MoveRoute[j].Range_Height = My_MoveRoute[j+1].Range_Height;
				My_MoveRoute[j+1].Range_Height = Temp5;
			}
		}
	}



	////////////////////루트맵 적군


	sprintf(FileName,"./EyRouteMap/%s/Stage%d.txt",Level,SelectStage);
	
	fp = fopen(FileName,"rt");

	fscanf(fp,"%d",&Max_Ey_MoveRoute);

	Ey_MoveRoute = new MoveRoute[Max_Ey_MoveRoute];
	TempArr = new int[Max_Ey_MoveRoute];
	for(int i=0; i<Max_Ey_MoveRoute; i++)
	{
		fscanf(fp,"%lf",&Ey_MoveRoute[i].Range_Width);		//점의 X가 0일경우 Width가 100이면 0~100까지 범위판정
		fscanf(fp,"%lf",&Ey_MoveRoute[i].Range_Height);		
	}

	count = 0;
	fgetc(fp);
	for(int i=0;i<SelectMap_Height;i++)
	{
		for(int j=0;j<SelectMap_Width;j++)
		{
			int Temp =  fgetc(fp) - '0';
			if(Temp != 0)
			{
				TempArr[count] = Temp;
				Ey_MoveRoute[count].X = TILE_WIDTH * j;
				Ey_MoveRoute[count].Y = TILE_HEIGHT * i;
				count++;
			}
		}
		fgetc(fp);
	}

	for(int i=0; i<Max_Ey_MoveRoute; i++)
	{
		for(int j=0; j<Max_Ey_MoveRoute - i -1; j++)
		{
			if(TempArr[j] > TempArr[j+1])
			{
				int Temp = TempArr[j];
				TempArr[j] = TempArr[j+1];
				TempArr[j+1] = Temp;

				double Temp2 = Ey_MoveRoute[j].X;
				Ey_MoveRoute[j].X = Ey_MoveRoute[j+1].X;
				Ey_MoveRoute[j+1].X = Temp2;

				double Temp3 = Ey_MoveRoute[j].Y;
				Ey_MoveRoute[j].Y = Ey_MoveRoute[j+1].Y;
				Ey_MoveRoute[j+1].Y = Temp3;

				
				double Temp4 = Ey_MoveRoute[j].Range_Width;
				Ey_MoveRoute[j].Range_Width = Ey_MoveRoute[j+1].Range_Width;
				Ey_MoveRoute[j+1].Range_Width = Temp4;

				
				double Temp5 = Ey_MoveRoute[j].Range_Height;
				Ey_MoveRoute[j].Range_Height = Ey_MoveRoute[j+1].Range_Height;
				Ey_MoveRoute[j+1].Range_Height = Temp5;
			}
		}
	}






	/*for(int i=0;i<SelectMap_Height;i++)
	{
		for(int j=0;j<SelectMap_Width;j++)
		{
			TileMap[i][j] = 0;
		}
	}*/


	MIN = 0;
	MAR = 0;
	MCA = 0;
	MPR = 0;
	MSP = 0;

	m_My_InfantryCount		=	0;
	m_My_ArcherCount		=	0;
	m_My_CavalryCount		=	0;
	m_My_PriestCount		=	0;
	m_My_SpearmanCount		=	0;

	m_Ey_InfantryCount		=	0;
	m_Ey_ArcherCount		=	0;
	m_Ey_CavalryCount		=	0;
	m_Ey_PriestCount		=	0;
	m_Ey_SpearmanCount		=	0;

	Buy_Infantry += 500;
	Buy_Archer += 500;
	Buy_Cavalry += 500;
	Buy_Priest += 500;
	Buy_Spearman += 500;


	m_ShowInv = false;
	GameStep = READY;
	m_SelectMenu = 1;
	m_SelectUnit = 1;




	for(int j=0; j<SelectMap_Height; j++)
	{
		for(int i=0; i<SelectMap_Width; i++)
		{
			if(Enemy_TileMap[j][i] == 0)
				continue;
			if(Enemy_TileMap[j][i] == INFANTRY)
				EIN++;
			else if(Enemy_TileMap[j][i] == ARCHER)
				EAR++;
			else if(Enemy_TileMap[j][i] == CAVALRY)
				ECA++;
			else if(Enemy_TileMap[j][i] == PRIEST)
				EPR++;
			else if(Enemy_TileMap[j][i] == SPEARMAN)
				ESP++;

		}
	}

	m_Ey_Infantry = new cInfantry[EIN];
	m_Ey_Archer	  = new cArcher[EAR];
	m_Ey_Cavalry  = new cCavalry[ECA];
	m_Ey_Priest   = new cPriest[EPR];
	m_Ey_Spearman = new cSpearman[ESP];


	for(int j=0; j<SelectMap_Height; j++)
	{
		for(int i=0; i<SelectMap_Width; i++)
		{
			if(Enemy_TileMap[j][i] == 0)
				continue;
			if(Enemy_TileMap[j][i] == INFANTRY)
			{
				m_Ey_Infantry[m_Ey_InfantryCount].setPosX((i*TILE_WIDTH) + GRID_X);
				m_Ey_Infantry[m_Ey_InfantryCount].setPosY((j*TILE_WIDTH) + GRID_Y);
				m_Ey_InfantryCount++;
			}
			else if(Enemy_TileMap[j][i] == ARCHER)
			{
				m_Ey_Archer[m_Ey_ArcherCount].setPosX((i*TILE_WIDTH) + GRID_X);
				m_Ey_Archer[m_Ey_ArcherCount].setPosY((j*TILE_WIDTH) + GRID_Y);
				m_Ey_ArcherCount++;
			}
			else if(Enemy_TileMap[j][i] == CAVALRY)
			{
				m_Ey_Cavalry[m_Ey_CavalryCount].setPosX((i*TILE_WIDTH) + GRID_X);
				m_Ey_Cavalry[m_Ey_CavalryCount].setPosY((j*TILE_WIDTH) + GRID_Y);
				m_Ey_CavalryCount++;
			}
			else if(Enemy_TileMap[j][i] == PRIEST)
			{
				m_Ey_Priest[m_Ey_PriestCount].setPosX((i*TILE_WIDTH) + GRID_X);
				m_Ey_Priest[m_Ey_PriestCount].setPosY((j*TILE_WIDTH) + GRID_Y);
				m_Ey_PriestCount++;
			}
			else if(Enemy_TileMap[j][i] == SPEARMAN)
			{
				m_Ey_Spearman[m_Ey_SpearmanCount].setPosX((i*TILE_WIDTH) + GRID_X);
				m_Ey_Spearman[m_Ey_SpearmanCount].setPosY((j*TILE_WIDTH) + GRID_Y);
				m_Ey_SpearmanCount++;
			}

		}
	}

	GameResult = NONE;
	BlackAlpha = 0;
	BlackAlphaReturn = 0;
	startTime = GetTickCount();
	offset.x = 0.000006;
	offset.y = 0.000006;
	fclose(fp);
}
void cGame::Update(float fElapsedTime)
{
	passTime = GetTickCount();
	
	Game_b_Back.CheckOver(x,y);
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

	KeyCheck();
	if(GameStep<CREATE)
		wHeelCheck();

	if(GameStep == CREATE)
	{
		MapScale = 100;
		for(int j=0; j<SelectMap_Height; j++)
		{
			for(int i=0; i<SelectMap_Width; i++)
			{
				if(TileMap[j][i] == 0)
					continue;
				if(TileMap[j][i] == INFANTRY)
					MIN++;
				else if(TileMap[j][i] == ARCHER)
					MAR++;
				else if(TileMap[j][i] == CAVALRY)
					MCA++;
				else if(TileMap[j][i] == PRIEST)
					MPR++;
				else if(TileMap[j][i] == SPEARMAN)
					MSP++;

			}
		}

		m_My_Infantry = new cInfantry[MIN];
		m_My_Archer	  = new cArcher[MAR];
		m_My_Cavalry  = new cCavalry[MCA];
		m_My_Priest   = new cPriest[MPR];
		m_My_Spearman = new cSpearman[MSP];

		for(int j=0; j<SelectMap_Height; j++)
		{
			for(int i=0; i<SelectMap_Width; i++)
			{
				if(TileMap[j][i] == 0)
					continue;
				if(TileMap[j][i] == INFANTRY)
				{
					m_My_Infantry[m_My_InfantryCount].setPosX((i*TILE_WIDTH) + GRID_X);
					m_My_Infantry[m_My_InfantryCount].setPosY((j*TILE_WIDTH) + GRID_Y);
					m_My_InfantryCount++;
				}
				else if(TileMap[j][i] == ARCHER)
				{
					m_My_Archer[m_My_ArcherCount].setPosX((i*TILE_WIDTH) + GRID_X);
					m_My_Archer[m_My_ArcherCount].setPosY((j*TILE_WIDTH) + GRID_Y);
					m_My_ArcherCount++;
				}
				else if(TileMap[j][i] == CAVALRY)
				{
					m_My_Cavalry[m_My_CavalryCount].setPosX((i*TILE_WIDTH) + GRID_X);
					m_My_Cavalry[m_My_CavalryCount].setPosY((j*TILE_WIDTH) + GRID_Y);
					m_My_CavalryCount++;
				}
				else if(TileMap[j][i] == PRIEST)
				{
					m_My_Priest[m_My_PriestCount].setPosX((i*TILE_WIDTH) + GRID_X);
					m_My_Priest[m_My_PriestCount].setPosY((j*TILE_WIDTH) + GRID_Y);
					m_My_PriestCount++;
				}
				else if(TileMap[j][i] == SPEARMAN)
				{
					m_My_Spearman[m_My_SpearmanCount].setPosX((i*TILE_WIDTH) + GRID_X);
					m_My_Spearman[m_My_SpearmanCount].setPosY((j*TILE_WIDTH) + GRID_Y);
					m_My_SpearmanCount++;
				}

			}
		}
		GameStep = ACTION;
	}

	else if(GameStep == ACTION) //게임을 시작합니다.
	{
		//아군유닛 Update
		for(int i=0;i<MIN;i++)
		{
			m_My_Infantry[i].Update(passTime,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP,Max_My_MoveRoute,My_MoveRoute);	
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
		//적군유닛 Update
		for(int i=0;i<EIN;i++)
		{
			m_Ey_Infantry[i].Update(passTime,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP,Max_Ey_MoveRoute,Ey_MoveRoute);
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
		//
		////아군 기병 겹침방지
		//for(i=0;i<MCA;i++)
		//{
		//	for(j=0;j<MIN;j++)
		//	{
		//		if(m_My_Cavalry[i].getHitTest() == 1 && m_My_Infantry[j].getHitTest() == 1)
		//		{
		//			if(	m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() > m_My_Infantry[j].getPosX()  &&
		//				m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() < m_My_Infantry[j].getPosX() + TILE_WIDTH &&
		//				m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() > m_My_Infantry[j].getPosY()  &&
		//				m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() < m_My_Infantry[j].getPosY() + TILE_HEIGHT &&
		//				
		//				m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() > m_My_Cavalry[i].getPosX()  &&
		//				m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() < m_My_Cavalry[i].getPosX() + TILE_WIDTH &&
		//				m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() > m_My_Cavalry[i].getPosY()  &&
		//				m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() < m_My_Cavalry[i].getPosY() + TILE_HEIGHT
		//				)
		//			{
		//				if(m_My_Cavalry[i].getDistance() > m_My_Infantry[j].getDistance())
		//					m_My_Infantry[j].setHitTest(0);
		//				else if(m_My_Infantry[j].getDistance() > m_My_Cavalry[i].getDistance())
		//					m_My_Cavalry[i].setHitTest(0);
		//				else
		//					m_My_Infantry[j].setHitTest(0);
		//			}
		//		}
		//	}

		//	for(j=0;j<MCA;j++)
		//	{
		//		if(i == j)
		//			continue;
		//		if(m_My_Cavalry[i].getHitTest() == 1 && m_My_Cavalry[j].getHitTest() == 1)
		//		{
		//			if(	m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() > m_My_Cavalry[j].getPosX()  &&
		//				m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() < m_My_Cavalry[j].getPosX() + TILE_WIDTH &&
		//				m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() > m_My_Cavalry[j].getPosY()  &&
		//				m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() < m_My_Cavalry[j].getPosY() + TILE_HEIGHT &&
		//				
		//				m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() > m_My_Cavalry[i].getPosX()  &&
		//				m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() < m_My_Cavalry[i].getPosX() + TILE_WIDTH &&
		//				m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() > m_My_Cavalry[i].getPosY()  &&
		//				m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() < m_My_Cavalry[i].getPosY() + TILE_HEIGHT
		//				)
		//			{
		//				if(m_My_Cavalry[i].getDistance() > m_My_Cavalry[j].getDistance())
		//					m_My_Cavalry[j].setHitTest(0);
		//				else if(m_My_Cavalry[j].getDistance() > m_My_Cavalry[i].getDistance())
		//					m_My_Cavalry[i].setHitTest(0);
		//				else
		//					m_My_Cavalry[j].setHitTest(0);
		//			}
		//		}


		//	}
		//}



		////적군 기병 겹침방지
		//
		//for(i=0;i<ECA;i++)
		//{

		//	for(j=0;j<EIN;j++)
		//	{
		//		if(m_Ey_Cavalry[i].getHitTest() == 1 && m_Ey_Infantry[j].getHitTest() == 1)
		//		{
		//			if(	m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() > m_Ey_Infantry[j].getPosX()  &&
		//				m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() < m_Ey_Infantry[j].getPosX() + TILE_WIDTH &&
		//				m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() > m_Ey_Infantry[j].getPosY()  &&
		//				m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() < m_Ey_Infantry[j].getPosY() + TILE_HEIGHT &&
		//				
		//				m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() > m_Ey_Cavalry[i].getPosX()  &&
		//				m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() < m_Ey_Cavalry[i].getPosX() + TILE_WIDTH &&
		//				m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() > m_Ey_Cavalry[i].getPosY()  &&
		//				m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() < m_Ey_Cavalry[i].getPosY() + TILE_HEIGHT
		//				)
		//			{
		//				if(m_Ey_Cavalry[i].getDistance() > m_Ey_Infantry[j].getDistance())
		//					m_Ey_Infantry[j].setHitTest(0);
		//				else if(m_Ey_Infantry[j].getDistance() > m_Ey_Cavalry[i].getDistance())
		//					m_Ey_Cavalry[i].setHitTest(0);
		//				else
		//					m_Ey_Infantry[j].setHitTest(0);
		//			}
		//		}
		//	}
		//	for(j=0;j<ECA;j++)
		//	{
		//		if(i == j)
		//			continue;
		//		if(m_Ey_Cavalry[i].getHitTest() == 1 && m_Ey_Cavalry[j].getHitTest() == 1)
		//		{
		//			if(	m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() > m_Ey_Cavalry[j].getPosX()  &&
		//				m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() < m_Ey_Cavalry[j].getPosX() + TILE_WIDTH &&
		//				m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() > m_Ey_Cavalry[j].getPosY()  &&
		//				m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() < m_Ey_Cavalry[j].getPosY() + TILE_HEIGHT &&
		//				
		//				m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() > m_Ey_Cavalry[i].getPosX()  &&
		//				m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() < m_Ey_Cavalry[i].getPosX() + TILE_WIDTH &&
		//				m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() > m_Ey_Cavalry[i].getPosY()  &&
		//				m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() < m_Ey_Cavalry[i].getPosY() + TILE_HEIGHT
		//				)
		//			{
		//				if(m_Ey_Cavalry[i].getDistance() > m_Ey_Cavalry[j].getDistance())
		//					m_Ey_Cavalry[j].setHitTest(0);
		//				else if(m_Ey_Cavalry[j].getDistance() > m_Ey_Cavalry[i].getDistance())
		//					m_Ey_Cavalry[i].setHitTest(0);
		//				else
		//					m_Ey_Cavalry[j].setHitTest(0);
		//			}
		//		}
		//	}

		//}

		//아군 보병 겹침방지(1)
		for(i=0;i<MIN;i++)
		{
			//if(m_My_Infantry[i].getState_Live() != LIVE)
			//		continue;
			for(j=0;j<MIN;j++)
			{
				if(i == j)
					continue;
				//if(m_My_Infantry[j].getState_Live() != LIVE)
			//		continue;
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
						{
								m_My_Infantry[j].setHitTest(0);
						}
						else if(m_My_Infantry[j].getDistance() > m_My_Infantry[i].getDistance())
						{
							m_My_Infantry[j].setHitTest(0);
						}
						else
							m_My_Infantry[j].setHitTest(0);;
					}
				}
			}
			for(j=0;j<MAR;j++)
			{
				if(m_My_Infantry[i].getHitTest() == 1 && m_My_Archer[j].getHitTest() == 1)
				{
					if(	m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() > m_My_Archer[j].getPosX()  &&
						m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() < m_My_Archer[j].getPosX() + TILE_WIDTH &&
						m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() > m_My_Archer[j].getPosY()  &&
						m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() < m_My_Archer[j].getPosY() + TILE_HEIGHT &&

						m_My_Archer[j].getPosX() + (TILE_WIDTH/2) + m_My_Archer[j].getMoveSpeedX() > m_My_Infantry[i].getPosX()  &&
						m_My_Archer[j].getPosX() + (TILE_WIDTH/2) + m_My_Archer[j].getMoveSpeedX() < m_My_Infantry[i].getPosX() + TILE_WIDTH &&
						m_My_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[j].getMoveSpeedY() > m_My_Infantry[i].getPosY()  &&
						m_My_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[j].getMoveSpeedY() < m_My_Infantry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Infantry[i].getDistance() > m_My_Archer[j].getDistance())
							m_My_Archer[j].setHitTest(0);
						else if(m_My_Archer[j].getDistance() > m_My_Infantry[i].getDistance())
							m_My_Infantry[i].setHitTest(0);
						else
							m_My_Archer[j].setHitTest(0);
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
			for(j=0;j<MPR;j++)
			{
				if(m_My_Infantry[i].getHitTest() == 1 && m_My_Priest[j].getHitTest() == 1)
				{
					if(	m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() > m_My_Priest[j].getPosX()  &&
						m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() < m_My_Priest[j].getPosX() + TILE_WIDTH &&
						m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() > m_My_Priest[j].getPosY()  &&
						m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() < m_My_Priest[j].getPosY() + TILE_HEIGHT &&

						m_My_Priest[j].getPosX() + (TILE_WIDTH/2) + m_My_Priest[j].getMoveSpeedX() > m_My_Infantry[i].getPosX()  &&
						m_My_Priest[j].getPosX() + (TILE_WIDTH/2) + m_My_Priest[j].getMoveSpeedX() < m_My_Infantry[i].getPosX() + TILE_WIDTH &&
						m_My_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[j].getMoveSpeedY() > m_My_Infantry[i].getPosY()  &&
						m_My_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[j].getMoveSpeedY() < m_My_Infantry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Infantry[i].getDistance() > m_My_Priest[j].getDistance())
							m_My_Priest[j].setHitTest(0);
						else if(m_My_Priest[j].getDistance() > m_My_Infantry[i].getDistance())
							m_My_Infantry[i].setHitTest(0);
						else
							m_My_Priest[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MSP;j++)
			{
				if(m_My_Infantry[i].getHitTest() == 1 && m_My_Spearman[j].getHitTest() == 1)
				{
					if(	m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() > m_My_Spearman[j].getPosX()  &&
						m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() < m_My_Spearman[j].getPosX() + TILE_WIDTH &&
						m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() > m_My_Spearman[j].getPosY()  &&
						m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() < m_My_Spearman[j].getPosY() + TILE_HEIGHT &&

						m_My_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[j].getMoveSpeedX() > m_My_Infantry[i].getPosX()  &&
						m_My_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[j].getMoveSpeedX() < m_My_Infantry[i].getPosX() + TILE_WIDTH &&
						m_My_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[j].getMoveSpeedY() > m_My_Infantry[i].getPosY()  &&
						m_My_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[j].getMoveSpeedY() < m_My_Infantry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Infantry[i].getDistance() > m_My_Spearman[j].getDistance())
							m_My_Spearman[j].setHitTest(0);
						else if(m_My_Spearman[j].getDistance() > m_My_Infantry[i].getDistance())
							m_My_Infantry[i].setHitTest(0);
						else
							m_My_Spearman[j].setHitTest(0);
					}
				}
			}
		}
		//아군 궁수 겹침방지(1)
		for(i=0;i<MAR;i++)
		{
			for(j=0;j<MIN;j++)
			{
				if(m_My_Archer[i].getHitTest() == 1 && m_My_Infantry[j].getHitTest() == 1)
				{
					if(	m_My_Archer[i].getPosX() + (TILE_WIDTH/2) + m_My_Archer[i].getMoveSpeedX() > m_My_Infantry[j].getPosX()  &&
						m_My_Archer[i].getPosX() + (TILE_WIDTH/2) + m_My_Archer[i].getMoveSpeedX() < m_My_Infantry[j].getPosX() + TILE_WIDTH &&
						m_My_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[i].getMoveSpeedY() > m_My_Infantry[j].getPosY()  &&
						m_My_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[i].getMoveSpeedY() < m_My_Infantry[j].getPosY() + TILE_HEIGHT &&

						m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() > m_My_Archer[i].getPosX()  &&
						m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() < m_My_Archer[i].getPosX() + TILE_WIDTH &&
						m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() > m_My_Archer[i].getPosY()  &&
						m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() < m_My_Archer[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Archer[i].getDistance() > m_My_Infantry[j].getDistance())
							m_My_Infantry[j].setHitTest(0);
						else if(m_My_Infantry[j].getDistance() > m_My_Archer[i].getDistance())
							m_My_Archer[i].setHitTest(0);
						else
							m_My_Infantry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MAR;j++)
			{
				if(i == j)
					continue;
				if(m_My_Archer[i].getHitTest() == 1 && m_My_Archer[j].getHitTest() == 1)
				{
					if(	m_My_Archer[i].getPosX() + (TILE_WIDTH/2) + m_My_Archer[i].getMoveSpeedX() > m_My_Archer[j].getPosX()  &&
						m_My_Archer[i].getPosX() + (TILE_WIDTH/2) + m_My_Archer[i].getMoveSpeedX() < m_My_Archer[j].getPosX() + TILE_WIDTH &&
						m_My_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[i].getMoveSpeedY() > m_My_Archer[j].getPosY()  &&
						m_My_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[i].getMoveSpeedY() < m_My_Archer[j].getPosY() + TILE_HEIGHT &&

						m_My_Archer[j].getPosX() + (TILE_WIDTH/2) + m_My_Archer[j].getMoveSpeedX() > m_My_Archer[i].getPosX()  &&
						m_My_Archer[j].getPosX() + (TILE_WIDTH/2) + m_My_Archer[j].getMoveSpeedX() < m_My_Archer[i].getPosX() + TILE_WIDTH &&
						m_My_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[j].getMoveSpeedY() > m_My_Archer[i].getPosY()  &&
						m_My_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[j].getMoveSpeedY() < m_My_Archer[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Archer[i].getDistance() > m_My_Archer[j].getDistance())
							m_My_Archer[j].setHitTest(0);
						else if(m_My_Archer[j].getDistance() > m_My_Archer[i].getDistance())
							m_My_Archer[i].setHitTest(0);
						else
							m_My_Archer[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MCA;j++)
			{
				if(m_My_Archer[i].getHitTest() == 1 && m_My_Cavalry[j].getHitTest() == 1)
				{
					if(	m_My_Archer[i].getPosX() + (TILE_WIDTH/2) + m_My_Archer[i].getMoveSpeedX() > m_My_Cavalry[j].getPosX()  &&
						m_My_Archer[i].getPosX() + (TILE_WIDTH/2) + m_My_Archer[i].getMoveSpeedX() < m_My_Cavalry[j].getPosX() + TILE_WIDTH &&
						m_My_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[i].getMoveSpeedY() > m_My_Cavalry[j].getPosY()  &&
						m_My_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[i].getMoveSpeedY() < m_My_Cavalry[j].getPosY() + TILE_HEIGHT &&

						m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() > m_My_Archer[i].getPosX()  &&
						m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() < m_My_Archer[i].getPosX() + TILE_WIDTH &&
						m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() > m_My_Archer[i].getPosY()  &&
						m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() < m_My_Archer[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Archer[i].getDistance() > m_My_Cavalry[j].getDistance())
							m_My_Cavalry[j].setHitTest(0);
						else if(m_My_Cavalry[j].getDistance() > m_My_Archer[i].getDistance())
							m_My_Archer[i].setHitTest(0);
						else
							m_My_Cavalry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MPR;j++)
			{
				if(m_My_Archer[i].getHitTest() == 1 && m_My_Priest[j].getHitTest() == 1)
				{
					if(	m_My_Archer[i].getPosX() + (TILE_WIDTH/2) + m_My_Archer[i].getMoveSpeedX() > m_My_Priest[j].getPosX()  &&
						m_My_Archer[i].getPosX() + (TILE_WIDTH/2) + m_My_Archer[i].getMoveSpeedX() < m_My_Priest[j].getPosX() + TILE_WIDTH &&
						m_My_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[i].getMoveSpeedY() > m_My_Priest[j].getPosY()  &&
						m_My_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[i].getMoveSpeedY() < m_My_Priest[j].getPosY() + TILE_HEIGHT &&

						m_My_Priest[j].getPosX() + (TILE_WIDTH/2) + m_My_Priest[j].getMoveSpeedX() > m_My_Archer[i].getPosX()  &&
						m_My_Priest[j].getPosX() + (TILE_WIDTH/2) + m_My_Priest[j].getMoveSpeedX() < m_My_Archer[i].getPosX() + TILE_WIDTH &&
						m_My_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[j].getMoveSpeedY() > m_My_Archer[i].getPosY()  &&
						m_My_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[j].getMoveSpeedY() < m_My_Archer[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Archer[i].getDistance() > m_My_Priest[j].getDistance())
							m_My_Priest[j].setHitTest(0);
						else if(m_My_Priest[j].getDistance() > m_My_Archer[i].getDistance())
							m_My_Archer[i].setHitTest(0);
						else
							m_My_Priest[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MSP;j++)
			{
				if(m_My_Archer[i].getHitTest() == 1 && m_My_Spearman[j].getHitTest() == 1)
				{
					if(	m_My_Archer[i].getPosX() + (TILE_WIDTH/2) + m_My_Archer[i].getMoveSpeedX() > m_My_Spearman[j].getPosX()  &&
						m_My_Archer[i].getPosX() + (TILE_WIDTH/2) + m_My_Archer[i].getMoveSpeedX() < m_My_Spearman[j].getPosX() + TILE_WIDTH &&
						m_My_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[i].getMoveSpeedY() > m_My_Spearman[j].getPosY()  &&
						m_My_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[i].getMoveSpeedY() < m_My_Spearman[j].getPosY() + TILE_HEIGHT &&

						m_My_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[j].getMoveSpeedX() > m_My_Archer[i].getPosX()  &&
						m_My_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[j].getMoveSpeedX() < m_My_Archer[i].getPosX() + TILE_WIDTH &&
						m_My_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[j].getMoveSpeedY() > m_My_Archer[i].getPosY()  &&
						m_My_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[j].getMoveSpeedY() < m_My_Archer[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Archer[i].getDistance() > m_My_Spearman[j].getDistance())
							m_My_Spearman[j].setHitTest(0);
						else if(m_My_Spearman[j].getDistance() > m_My_Archer[i].getDistance())
							m_My_Archer[i].setHitTest(0);
						else
							m_My_Spearman[j].setHitTest(0);
					}
				}
			}
		}

		//아군 기병 겹침방지(1)
		for(i=0;i<MCA;i++)
		{
			for(j=0;j<MIN;j++)
			{
				if(m_My_Cavalry[i].getHitTest() == 1 && m_My_Infantry[j].getHitTest() == 1)
				{
					if(	m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() > m_My_Infantry[j].getPosX()  &&
						m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() < m_My_Infantry[j].getPosX() + TILE_WIDTH &&
						m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() > m_My_Infantry[j].getPosY()  &&
						m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() < m_My_Infantry[j].getPosY() + TILE_HEIGHT &&

						m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() > m_My_Cavalry[i].getPosX()  &&
						m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() < m_My_Cavalry[i].getPosX() + TILE_WIDTH &&
						m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() > m_My_Cavalry[i].getPosY()  &&
						m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() < m_My_Cavalry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Cavalry[i].getDistance() > m_My_Infantry[j].getDistance())
							m_My_Infantry[j].setHitTest(0);
						else if(m_My_Infantry[j].getDistance() > m_My_Cavalry[i].getDistance())
							m_My_Cavalry[i].setHitTest(0);
						else
							m_My_Infantry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MAR;j++)
			{
				if(m_My_Cavalry[i].getHitTest() == 1 && m_My_Archer[j].getHitTest() == 1)
				{
					if(	m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() > m_My_Archer[j].getPosX()  &&
						m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() < m_My_Archer[j].getPosX() + TILE_WIDTH &&
						m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() > m_My_Archer[j].getPosY()  &&
						m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() < m_My_Archer[j].getPosY() + TILE_HEIGHT &&

						m_My_Archer[j].getPosX() + (TILE_WIDTH/2) + m_My_Archer[j].getMoveSpeedX() > m_My_Cavalry[i].getPosX()  &&
						m_My_Archer[j].getPosX() + (TILE_WIDTH/2) + m_My_Archer[j].getMoveSpeedX() < m_My_Cavalry[i].getPosX() + TILE_WIDTH &&
						m_My_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[j].getMoveSpeedY() > m_My_Cavalry[i].getPosY()  &&
						m_My_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[j].getMoveSpeedY() < m_My_Cavalry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Cavalry[i].getDistance() > m_My_Archer[j].getDistance())
							m_My_Archer[j].setHitTest(0);
						else if(m_My_Archer[j].getDistance() > m_My_Cavalry[i].getDistance())
							m_My_Cavalry[i].setHitTest(0);
						else
							m_My_Archer[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MCA;j++)
			{
				if(i == j)
					continue;
				if(m_My_Cavalry[i].getHitTest() == 1 && m_My_Cavalry[j].getHitTest() == 1)
				{
					if(	m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() > m_My_Cavalry[j].getPosX()  &&
						m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() < m_My_Cavalry[j].getPosX() + TILE_WIDTH &&
						m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() > m_My_Cavalry[j].getPosY()  &&
						m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() < m_My_Cavalry[j].getPosY() + TILE_HEIGHT &&

						m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() > m_My_Cavalry[i].getPosX()  &&
						m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() < m_My_Cavalry[i].getPosX() + TILE_WIDTH &&
						m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() > m_My_Cavalry[i].getPosY()  &&
						m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() < m_My_Cavalry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Cavalry[i].getDistance() > m_My_Cavalry[j].getDistance())
							m_My_Cavalry[j].setHitTest(0);
						else if(m_My_Cavalry[j].getDistance() > m_My_Cavalry[i].getDistance())
							m_My_Cavalry[i].setHitTest(0);
						else
							m_My_Cavalry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MPR;j++)
			{
				if(m_My_Cavalry[i].getHitTest() == 1 && m_My_Priest[j].getHitTest() == 1)
				{
					if(	m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() > m_My_Priest[j].getPosX()  &&
						m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() < m_My_Priest[j].getPosX() + TILE_WIDTH &&
						m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() > m_My_Priest[j].getPosY()  &&
						m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() < m_My_Priest[j].getPosY() + TILE_HEIGHT &&

						m_My_Priest[j].getPosX() + (TILE_WIDTH/2) + m_My_Priest[j].getMoveSpeedX() > m_My_Cavalry[i].getPosX()  &&
						m_My_Priest[j].getPosX() + (TILE_WIDTH/2) + m_My_Priest[j].getMoveSpeedX() < m_My_Cavalry[i].getPosX() + TILE_WIDTH &&
						m_My_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[j].getMoveSpeedY() > m_My_Cavalry[i].getPosY()  &&
						m_My_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[j].getMoveSpeedY() < m_My_Cavalry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Cavalry[i].getDistance() > m_My_Priest[j].getDistance())
							m_My_Priest[j].setHitTest(0);
						else if(m_My_Priest[j].getDistance() > m_My_Cavalry[i].getDistance())
							m_My_Cavalry[i].setHitTest(0);
						else
							m_My_Priest[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MSP;j++)
			{
				if(m_My_Cavalry[i].getHitTest() == 1 && m_My_Spearman[j].getHitTest() == 1)
				{
					if(	m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() > m_My_Spearman[j].getPosX()  &&
						m_My_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[i].getMoveSpeedX() < m_My_Spearman[j].getPosX() + TILE_WIDTH &&
						m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() > m_My_Spearman[j].getPosY()  &&
						m_My_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[i].getMoveSpeedY() < m_My_Spearman[j].getPosY() + TILE_HEIGHT &&

						m_My_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[j].getMoveSpeedX() > m_My_Cavalry[i].getPosX()  &&
						m_My_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[j].getMoveSpeedX() < m_My_Cavalry[i].getPosX() + TILE_WIDTH &&
						m_My_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[j].getMoveSpeedY() > m_My_Cavalry[i].getPosY()  &&
						m_My_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[j].getMoveSpeedY() < m_My_Cavalry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Cavalry[i].getDistance() > m_My_Spearman[j].getDistance())
							m_My_Spearman[j].setHitTest(0);
						else if(m_My_Spearman[j].getDistance() > m_My_Cavalry[i].getDistance())
							m_My_Cavalry[i].setHitTest(0);
						else
							m_My_Spearman[j].setHitTest(0);
					}
				}
			}
		}
		
		//아군 사제 겹침방지(1)
		for(i=0;i<MPR;i++)
		{
			for(j=0;j<MIN;j++)
			{
				if(m_My_Priest[i].getHitTest() == 1 && m_My_Infantry[j].getHitTest() == 1)
				{
					if(	m_My_Priest[i].getPosX() + (TILE_WIDTH/2) + m_My_Priest[i].getMoveSpeedX() > m_My_Infantry[j].getPosX()  &&
						m_My_Priest[i].getPosX() + (TILE_WIDTH/2) + m_My_Priest[i].getMoveSpeedX() < m_My_Infantry[j].getPosX() + TILE_WIDTH &&
						m_My_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[i].getMoveSpeedY() > m_My_Infantry[j].getPosY()  &&
						m_My_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[i].getMoveSpeedY() < m_My_Infantry[j].getPosY() + TILE_HEIGHT &&

						m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() > m_My_Priest[i].getPosX()  &&
						m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() < m_My_Priest[i].getPosX() + TILE_WIDTH &&
						m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() > m_My_Priest[i].getPosY()  &&
						m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() < m_My_Priest[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Priest[i].getDistance() > m_My_Infantry[j].getDistance())
							m_My_Infantry[j].setHitTest(0);
						else if(m_My_Infantry[j].getDistance() > m_My_Priest[i].getDistance())
							m_My_Priest[i].setHitTest(0);
						else
							m_My_Infantry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MAR;j++)
			{
				if(m_My_Priest[i].getHitTest() == 1 && m_My_Archer[j].getHitTest() == 1)
				{
					if(	m_My_Priest[i].getPosX() + (TILE_WIDTH/2) + m_My_Priest[i].getMoveSpeedX() > m_My_Archer[j].getPosX()  &&
						m_My_Priest[i].getPosX() + (TILE_WIDTH/2) + m_My_Priest[i].getMoveSpeedX() < m_My_Archer[j].getPosX() + TILE_WIDTH &&
						m_My_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[i].getMoveSpeedY() > m_My_Archer[j].getPosY()  &&
						m_My_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[i].getMoveSpeedY() < m_My_Archer[j].getPosY() + TILE_HEIGHT &&

						m_My_Archer[j].getPosX() + (TILE_WIDTH/2) + m_My_Archer[j].getMoveSpeedX() > m_My_Priest[i].getPosX()  &&
						m_My_Archer[j].getPosX() + (TILE_WIDTH/2) + m_My_Archer[j].getMoveSpeedX() < m_My_Priest[i].getPosX() + TILE_WIDTH &&
						m_My_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[j].getMoveSpeedY() > m_My_Priest[i].getPosY()  &&
						m_My_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[j].getMoveSpeedY() < m_My_Priest[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Priest[i].getDistance() > m_My_Archer[j].getDistance())
							m_My_Archer[j].setHitTest(0);
						else if(m_My_Archer[j].getDistance() > m_My_Priest[i].getDistance())
							m_My_Priest[i].setHitTest(0);
						else
							m_My_Archer[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MCA;j++)
			{
				if(m_My_Priest[i].getHitTest() == 1 && m_My_Cavalry[j].getHitTest() == 1)
				{
					if(	m_My_Priest[i].getPosX() + (TILE_WIDTH/2) + m_My_Priest[i].getMoveSpeedX() > m_My_Cavalry[j].getPosX()  &&
						m_My_Priest[i].getPosX() + (TILE_WIDTH/2) + m_My_Priest[i].getMoveSpeedX() < m_My_Cavalry[j].getPosX() + TILE_WIDTH &&
						m_My_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[i].getMoveSpeedY() > m_My_Cavalry[j].getPosY()  &&
						m_My_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[i].getMoveSpeedY() < m_My_Cavalry[j].getPosY() + TILE_HEIGHT &&

						m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() > m_My_Priest[i].getPosX()  &&
						m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() < m_My_Priest[i].getPosX() + TILE_WIDTH &&
						m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() > m_My_Priest[i].getPosY()  &&
						m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() < m_My_Priest[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Priest[i].getDistance() > m_My_Cavalry[j].getDistance())
							m_My_Cavalry[j].setHitTest(0);
						else if(m_My_Cavalry[j].getDistance() > m_My_Priest[i].getDistance())
							m_My_Priest[i].setHitTest(0);
						else
							m_My_Cavalry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MPR;j++)
			{
				if(i == j)
					continue;
				if(m_My_Priest[i].getHitTest() == 1 && m_My_Priest[j].getHitTest() == 1)
				{
					if(	m_My_Priest[i].getPosX() + (TILE_WIDTH/2) + m_My_Priest[i].getMoveSpeedX() > m_My_Priest[j].getPosX()  &&
						m_My_Priest[i].getPosX() + (TILE_WIDTH/2) + m_My_Priest[i].getMoveSpeedX() < m_My_Priest[j].getPosX() + TILE_WIDTH &&
						m_My_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[i].getMoveSpeedY() > m_My_Priest[j].getPosY()  &&
						m_My_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[i].getMoveSpeedY() < m_My_Priest[j].getPosY() + TILE_HEIGHT &&

						m_My_Priest[j].getPosX() + (TILE_WIDTH/2) + m_My_Priest[j].getMoveSpeedX() > m_My_Priest[i].getPosX()  &&
						m_My_Priest[j].getPosX() + (TILE_WIDTH/2) + m_My_Priest[j].getMoveSpeedX() < m_My_Priest[i].getPosX() + TILE_WIDTH &&
						m_My_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[j].getMoveSpeedY() > m_My_Priest[i].getPosY()  &&
						m_My_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[j].getMoveSpeedY() < m_My_Priest[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Priest[i].getDistance() > m_My_Priest[j].getDistance())
							m_My_Priest[j].setHitTest(0);
						else if(m_My_Priest[j].getDistance() > m_My_Priest[i].getDistance())
							m_My_Priest[i].setHitTest(0);
						else
							m_My_Priest[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MSP;j++)
			{
				if(m_My_Priest[i].getHitTest() == 1 && m_My_Spearman[j].getHitTest() == 1)
				{
					if(	m_My_Priest[i].getPosX() + (TILE_WIDTH/2) + m_My_Priest[i].getMoveSpeedX() > m_My_Spearman[j].getPosX()  &&
						m_My_Priest[i].getPosX() + (TILE_WIDTH/2) + m_My_Priest[i].getMoveSpeedX() < m_My_Spearman[j].getPosX() + TILE_WIDTH &&
						m_My_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[i].getMoveSpeedY() > m_My_Spearman[j].getPosY()  &&
						m_My_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[i].getMoveSpeedY() < m_My_Spearman[j].getPosY() + TILE_HEIGHT &&

						m_My_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[j].getMoveSpeedX() > m_My_Priest[i].getPosX()  &&
						m_My_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[j].getMoveSpeedX() < m_My_Priest[i].getPosX() + TILE_WIDTH &&
						m_My_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[j].getMoveSpeedY() > m_My_Priest[i].getPosY()  &&
						m_My_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[j].getMoveSpeedY() < m_My_Priest[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Priest[i].getDistance() > m_My_Spearman[j].getDistance())
							m_My_Spearman[j].setHitTest(0);
						else if(m_My_Spearman[j].getDistance() > m_My_Priest[i].getDistance())
							m_My_Priest[i].setHitTest(0);
						else
							m_My_Spearman[j].setHitTest(0);
					}
				}
			}
		}
		//아군 창병 겹침방지(1)
		for(i=0;i<MSP;i++)
		{
			for(j=0;j<MIN;j++)
			{
				if(m_My_Spearman[i].getHitTest() == 1 && m_My_Infantry[j].getHitTest() == 1)
				{
					if(	m_My_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[i].getMoveSpeedX() > m_My_Infantry[j].getPosX()  &&
						m_My_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[i].getMoveSpeedX() < m_My_Infantry[j].getPosX() + TILE_WIDTH &&
						m_My_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[i].getMoveSpeedY() > m_My_Infantry[j].getPosY()  &&
						m_My_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[i].getMoveSpeedY() < m_My_Infantry[j].getPosY() + TILE_HEIGHT &&

						m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() > m_My_Spearman[i].getPosX()  &&
						m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() < m_My_Spearman[i].getPosX() + TILE_WIDTH &&
						m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() > m_My_Spearman[i].getPosY()  &&
						m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() < m_My_Spearman[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Spearman[i].getDistance() > m_My_Infantry[j].getDistance())
							m_My_Infantry[j].setHitTest(0);
						else if(m_My_Infantry[j].getDistance() > m_My_Spearman[i].getDistance())
							m_My_Spearman[i].setHitTest(0);
						else
							m_My_Infantry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MAR;j++)
			{
				if(m_My_Spearman[i].getHitTest() == 1 && m_My_Archer[j].getHitTest() == 1)
				{
					if(	m_My_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[i].getMoveSpeedX() > m_My_Archer[j].getPosX()  &&
						m_My_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[i].getMoveSpeedX() < m_My_Archer[j].getPosX() + TILE_WIDTH &&
						m_My_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[i].getMoveSpeedY() > m_My_Archer[j].getPosY()  &&
						m_My_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[i].getMoveSpeedY() < m_My_Archer[j].getPosY() + TILE_HEIGHT &&

						m_My_Archer[j].getPosX() + (TILE_WIDTH/2) + m_My_Archer[j].getMoveSpeedX() > m_My_Spearman[i].getPosX()  &&
						m_My_Archer[j].getPosX() + (TILE_WIDTH/2) + m_My_Archer[j].getMoveSpeedX() < m_My_Spearman[i].getPosX() + TILE_WIDTH &&
						m_My_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[j].getMoveSpeedY() > m_My_Spearman[i].getPosY()  &&
						m_My_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_My_Archer[j].getMoveSpeedY() < m_My_Spearman[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Spearman[i].getDistance() > m_My_Archer[j].getDistance())
							m_My_Archer[j].setHitTest(0);
						else if(m_My_Archer[j].getDistance() > m_My_Spearman[i].getDistance())
							m_My_Spearman[i].setHitTest(0);
						else
							m_My_Archer[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MCA;j++)
			{
				if(m_My_Spearman[i].getHitTest() == 1 && m_My_Cavalry[j].getHitTest() == 1)
				{
					if(	m_My_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[i].getMoveSpeedX() > m_My_Cavalry[j].getPosX()  &&
						m_My_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[i].getMoveSpeedX() < m_My_Cavalry[j].getPosX() + TILE_WIDTH &&
						m_My_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[i].getMoveSpeedY() > m_My_Cavalry[j].getPosY()  &&
						m_My_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[i].getMoveSpeedY() < m_My_Cavalry[j].getPosY() + TILE_HEIGHT &&

						m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() > m_My_Spearman[i].getPosX()  &&
						m_My_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_My_Cavalry[j].getMoveSpeedX() < m_My_Spearman[i].getPosX() + TILE_WIDTH &&
						m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() > m_My_Spearman[i].getPosY()  &&
						m_My_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Cavalry[j].getMoveSpeedY() < m_My_Spearman[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Spearman[i].getDistance() > m_My_Cavalry[j].getDistance())
							m_My_Cavalry[j].setHitTest(0);
						else if(m_My_Cavalry[j].getDistance() > m_My_Spearman[i].getDistance())
							m_My_Spearman[i].setHitTest(0);
						else
							m_My_Cavalry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MPR;j++)
			{
				
				if(m_My_Spearman[i].getHitTest() == 1 && m_My_Priest[j].getHitTest() == 1)
				{
					if(	m_My_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[i].getMoveSpeedX() > m_My_Priest[j].getPosX()  &&
						m_My_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[i].getMoveSpeedX() < m_My_Priest[j].getPosX() + TILE_WIDTH &&
						m_My_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[i].getMoveSpeedY() > m_My_Priest[j].getPosY()  &&
						m_My_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[i].getMoveSpeedY() < m_My_Priest[j].getPosY() + TILE_HEIGHT &&

						m_My_Priest[j].getPosX() + (TILE_WIDTH/2) + m_My_Priest[j].getMoveSpeedX() > m_My_Spearman[i].getPosX()  &&
						m_My_Priest[j].getPosX() + (TILE_WIDTH/2) + m_My_Priest[j].getMoveSpeedX() < m_My_Spearman[i].getPosX() + TILE_WIDTH &&
						m_My_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[j].getMoveSpeedY() > m_My_Spearman[i].getPosY()  &&
						m_My_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_My_Priest[j].getMoveSpeedY() < m_My_Spearman[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Spearman[i].getDistance() > m_My_Priest[j].getDistance())
							m_My_Priest[j].setHitTest(0);
						else if(m_My_Priest[j].getDistance() > m_My_Spearman[i].getDistance())
							m_My_Spearman[i].setHitTest(0);
						else
							m_My_Priest[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<MSP;j++)
			{
				if(i == j)
					continue;
				if(m_My_Spearman[i].getHitTest() == 1 && m_My_Spearman[j].getHitTest() == 1)
				{
					if(	m_My_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[i].getMoveSpeedX() > m_My_Spearman[j].getPosX()  &&
						m_My_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[i].getMoveSpeedX() < m_My_Spearman[j].getPosX() + TILE_WIDTH &&
						m_My_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[i].getMoveSpeedY() > m_My_Spearman[j].getPosY()  &&
						m_My_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[i].getMoveSpeedY() < m_My_Spearman[j].getPosY() + TILE_HEIGHT &&

						m_My_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[j].getMoveSpeedX() > m_My_Spearman[i].getPosX()  &&
						m_My_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_My_Spearman[j].getMoveSpeedX() < m_My_Spearman[i].getPosX() + TILE_WIDTH &&
						m_My_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[j].getMoveSpeedY() > m_My_Spearman[i].getPosY()  &&
						m_My_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_My_Spearman[j].getMoveSpeedY() < m_My_Spearman[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_My_Spearman[i].getDistance() > m_My_Spearman[j].getDistance())
							m_My_Spearman[j].setHitTest(0);
						else if(m_My_Spearman[j].getDistance() > m_My_Spearman[i].getDistance())
							m_My_Spearman[i].setHitTest(0);
						else
							m_My_Spearman[j].setHitTest(0);
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
				if(m_Ey_Infantry[i].getHitTest() == 1  && m_Ey_Infantry[j].getHitTest() == 1)
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
			for(j=0;j<EAR;j++)
			{
				if(m_Ey_Infantry[i].getHitTest() == 1 && m_Ey_Archer[j].getHitTest() == 1)
				{
					if(	m_Ey_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[i].getMoveSpeedX() > m_Ey_Archer[j].getPosX()  &&
						m_Ey_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[i].getMoveSpeedX() < m_Ey_Archer[j].getPosX() + TILE_WIDTH &&
						m_Ey_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[i].getMoveSpeedY() > m_Ey_Archer[j].getPosY()  &&
						m_Ey_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[i].getMoveSpeedY() < m_Ey_Archer[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Archer[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[j].getMoveSpeedX() > m_Ey_Infantry[i].getPosX()  &&
						m_Ey_Archer[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[j].getMoveSpeedX() < m_Ey_Infantry[i].getPosX() + TILE_WIDTH &&
						m_Ey_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[j].getMoveSpeedY() > m_Ey_Infantry[i].getPosY()  &&
						m_Ey_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[j].getMoveSpeedY() < m_Ey_Infantry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Infantry[i].getDistance() > m_Ey_Archer[j].getDistance())
							m_Ey_Archer[j].setHitTest(0);
						else if(m_Ey_Archer[j].getDistance() > m_Ey_Infantry[i].getDistance())
							m_Ey_Infantry[i].setHitTest(0);
						else
							m_Ey_Archer[j].setHitTest(0);
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
			for(j=0;j<EPR;j++)
			{
				if(m_Ey_Infantry[i].getHitTest() == 1 && m_Ey_Priest[j].getHitTest() == 1)
				{
					if(	m_Ey_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[i].getMoveSpeedX() > m_Ey_Priest[j].getPosX()  &&
						m_Ey_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[i].getMoveSpeedX() < m_Ey_Priest[j].getPosX() + TILE_WIDTH &&
						m_Ey_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[i].getMoveSpeedY() > m_Ey_Priest[j].getPosY()  &&
						m_Ey_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[i].getMoveSpeedY() < m_Ey_Priest[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Priest[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[j].getMoveSpeedX() > m_Ey_Infantry[i].getPosX()  &&
						m_Ey_Priest[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[j].getMoveSpeedX() < m_Ey_Infantry[i].getPosX() + TILE_WIDTH &&
						m_Ey_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[j].getMoveSpeedY() > m_Ey_Infantry[i].getPosY()  &&
						m_Ey_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[j].getMoveSpeedY() < m_Ey_Infantry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Infantry[i].getDistance() > m_Ey_Priest[j].getDistance())
							m_Ey_Priest[j].setHitTest(0);
						else if(m_Ey_Priest[j].getDistance() > m_Ey_Infantry[i].getDistance())
							m_Ey_Infantry[i].setHitTest(0);
						else
							m_Ey_Priest[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<ESP;j++)
			{
				if(m_Ey_Infantry[i].getHitTest() == 1 && m_Ey_Spearman[j].getHitTest() == 1)
				{
					if(	m_Ey_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[i].getMoveSpeedX() > m_Ey_Spearman[j].getPosX()  &&
						m_Ey_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[i].getMoveSpeedX() < m_Ey_Spearman[j].getPosX() + TILE_WIDTH &&
						m_Ey_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[i].getMoveSpeedY() > m_Ey_Spearman[j].getPosY()  &&
						m_Ey_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[i].getMoveSpeedY() < m_Ey_Spearman[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[j].getMoveSpeedX() > m_Ey_Infantry[i].getPosX()  &&
						m_Ey_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[j].getMoveSpeedX() < m_Ey_Infantry[i].getPosX() + TILE_WIDTH &&
						m_Ey_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[j].getMoveSpeedY() > m_Ey_Infantry[i].getPosY()  &&
						m_Ey_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[j].getMoveSpeedY() < m_Ey_Infantry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Infantry[i].getDistance() > m_Ey_Spearman[j].getDistance())
							m_Ey_Spearman[j].setHitTest(0);
						else if(m_Ey_Spearman[j].getDistance() > m_Ey_Infantry[i].getDistance())
							m_Ey_Infantry[i].setHitTest(0);
						else
							m_Ey_Spearman[j].setHitTest(0);
					}
				}
			}

		}
		
		//적군 궁수 겹침방지(1)
		for(i=0;i<EAR;i++)
		{
			for(j=0;j<EIN;j++)
			{
				if(m_Ey_Archer[i].getHitTest() == 1 && m_Ey_Infantry[j].getHitTest() == 1)
				{
					if(	m_Ey_Archer[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[i].getMoveSpeedX() > m_Ey_Infantry[j].getPosX()  &&
						m_Ey_Archer[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[i].getMoveSpeedX() < m_Ey_Infantry[j].getPosX() + TILE_WIDTH &&
						m_Ey_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[i].getMoveSpeedY() > m_Ey_Infantry[j].getPosY()  &&
						m_Ey_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[i].getMoveSpeedY() < m_Ey_Infantry[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() > m_Ey_Archer[i].getPosX()  &&
						m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() < m_Ey_Archer[i].getPosX() + TILE_WIDTH &&
						m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() > m_Ey_Archer[i].getPosY()  &&
						m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() < m_Ey_Archer[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Archer[i].getDistance() > m_Ey_Infantry[j].getDistance())
							m_Ey_Infantry[j].setHitTest(0);
						else if(m_Ey_Infantry[j].getDistance() > m_Ey_Archer[i].getDistance())
							m_Ey_Archer[i].setHitTest(0);
						else
							m_Ey_Infantry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<EAR;j++)
			{
				if(i == j)
					continue;
				if(m_Ey_Archer[i].getHitTest() == 1 && m_Ey_Archer[j].getHitTest() == 1)
				{
					if(	m_Ey_Archer[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[i].getMoveSpeedX() > m_Ey_Archer[j].getPosX()  &&
						m_Ey_Archer[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[i].getMoveSpeedX() < m_Ey_Archer[j].getPosX() + TILE_WIDTH &&
						m_Ey_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[i].getMoveSpeedY() > m_Ey_Archer[j].getPosY()  &&
						m_Ey_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[i].getMoveSpeedY() < m_Ey_Archer[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Archer[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[j].getMoveSpeedX() > m_Ey_Archer[i].getPosX()  &&
						m_Ey_Archer[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[j].getMoveSpeedX() < m_Ey_Archer[i].getPosX() + TILE_WIDTH &&
						m_Ey_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[j].getMoveSpeedY() > m_Ey_Archer[i].getPosY()  &&
						m_Ey_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[j].getMoveSpeedY() < m_Ey_Archer[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Archer[i].getDistance() > m_Ey_Archer[j].getDistance())
							m_Ey_Archer[j].setHitTest(0);
						else if(m_Ey_Archer[j].getDistance() > m_Ey_Archer[i].getDistance())
							m_Ey_Archer[i].setHitTest(0);
						else
							m_Ey_Archer[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<ECA;j++)
			{
				if(m_Ey_Archer[i].getHitTest() == 1 && m_Ey_Cavalry[j].getHitTest() == 1)
				{
					if(	m_Ey_Archer[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[i].getMoveSpeedX() > m_Ey_Cavalry[j].getPosX()  &&
						m_Ey_Archer[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[i].getMoveSpeedX() < m_Ey_Cavalry[j].getPosX() + TILE_WIDTH &&
						m_Ey_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[i].getMoveSpeedY() > m_Ey_Cavalry[j].getPosY()  &&
						m_Ey_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[i].getMoveSpeedY() < m_Ey_Cavalry[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() > m_Ey_Archer[i].getPosX()  &&
						m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() < m_Ey_Archer[i].getPosX() + TILE_WIDTH &&
						m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() > m_Ey_Archer[i].getPosY()  &&
						m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() < m_Ey_Archer[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Archer[i].getDistance() > m_Ey_Cavalry[j].getDistance())
							m_Ey_Cavalry[j].setHitTest(0);
						else if(m_Ey_Cavalry[j].getDistance() > m_Ey_Archer[i].getDistance())
							m_Ey_Archer[i].setHitTest(0);
						else
							m_Ey_Cavalry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<EPR;j++)
			{
				if(m_Ey_Archer[i].getHitTest() == 1 && m_Ey_Priest[j].getHitTest() == 1)
				{
					if(	m_Ey_Archer[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[i].getMoveSpeedX() > m_Ey_Priest[j].getPosX()  &&
						m_Ey_Archer[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[i].getMoveSpeedX() < m_Ey_Priest[j].getPosX() + TILE_WIDTH &&
						m_Ey_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[i].getMoveSpeedY() > m_Ey_Priest[j].getPosY()  &&
						m_Ey_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[i].getMoveSpeedY() < m_Ey_Priest[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Priest[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[j].getMoveSpeedX() > m_Ey_Archer[i].getPosX()  &&
						m_Ey_Priest[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[j].getMoveSpeedX() < m_Ey_Archer[i].getPosX() + TILE_WIDTH &&
						m_Ey_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[j].getMoveSpeedY() > m_Ey_Archer[i].getPosY()  &&
						m_Ey_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[j].getMoveSpeedY() < m_Ey_Archer[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Archer[i].getDistance() > m_Ey_Priest[j].getDistance())
							m_Ey_Priest[j].setHitTest(0);
						else if(m_Ey_Priest[j].getDistance() > m_Ey_Archer[i].getDistance())
							m_Ey_Archer[i].setHitTest(0);
						else
							m_Ey_Priest[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<ESP;j++)
			{
				if(m_Ey_Archer[i].getHitTest() == 1 && m_Ey_Spearman[j].getHitTest() == 1)
				{
					if(	m_Ey_Archer[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[i].getMoveSpeedX() > m_Ey_Spearman[j].getPosX()  &&
						m_Ey_Archer[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[i].getMoveSpeedX() < m_Ey_Spearman[j].getPosX() + TILE_WIDTH &&
						m_Ey_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[i].getMoveSpeedY() > m_Ey_Spearman[j].getPosY()  &&
						m_Ey_Archer[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[i].getMoveSpeedY() < m_Ey_Spearman[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[j].getMoveSpeedX() > m_Ey_Archer[i].getPosX()  &&
						m_Ey_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[j].getMoveSpeedX() < m_Ey_Archer[i].getPosX() + TILE_WIDTH &&
						m_Ey_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[j].getMoveSpeedY() > m_Ey_Archer[i].getPosY()  &&
						m_Ey_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[j].getMoveSpeedY() < m_Ey_Archer[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Archer[i].getDistance() > m_Ey_Spearman[j].getDistance())
							m_Ey_Spearman[j].setHitTest(0);
						else if(m_Ey_Spearman[j].getDistance() > m_Ey_Archer[i].getDistance())
							m_Ey_Archer[i].setHitTest(0);
						else
							m_Ey_Spearman[j].setHitTest(0);
					}
				}
			}

		}
		//적군 기병 겹침방지(1)
		for(i=0;i<ECA;i++)
		{
			for(j=0;j<EIN;j++)
			{
				if(m_Ey_Cavalry[i].getHitTest() == 1 && m_Ey_Infantry[j].getHitTest() == 1)
				{
					if(	m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() > m_Ey_Infantry[j].getPosX()  &&
						m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() < m_Ey_Infantry[j].getPosX() + TILE_WIDTH &&
						m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() > m_Ey_Infantry[j].getPosY()  &&
						m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() < m_Ey_Infantry[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() > m_Ey_Cavalry[i].getPosX()  &&
						m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() < m_Ey_Cavalry[i].getPosX() + TILE_WIDTH &&
						m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() > m_Ey_Cavalry[i].getPosY()  &&
						m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() < m_Ey_Cavalry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Cavalry[i].getDistance() > m_Ey_Infantry[j].getDistance())
							m_Ey_Infantry[j].setHitTest(0);
						else if(m_Ey_Infantry[j].getDistance() > m_Ey_Cavalry[i].getDistance())
							m_Ey_Cavalry[i].setHitTest(0);
						else
							m_Ey_Infantry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<EAR;j++)
			{
				if(m_Ey_Cavalry[i].getHitTest() == 1 && m_Ey_Archer[j].getHitTest() == 1)
				{
					if(	m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() > m_Ey_Archer[j].getPosX()  &&
						m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() < m_Ey_Archer[j].getPosX() + TILE_WIDTH &&
						m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() > m_Ey_Archer[j].getPosY()  &&
						m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() < m_Ey_Archer[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Archer[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[j].getMoveSpeedX() > m_Ey_Cavalry[i].getPosX()  &&
						m_Ey_Archer[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[j].getMoveSpeedX() < m_Ey_Cavalry[i].getPosX() + TILE_WIDTH &&
						m_Ey_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[j].getMoveSpeedY() > m_Ey_Cavalry[i].getPosY()  &&
						m_Ey_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[j].getMoveSpeedY() < m_Ey_Cavalry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Cavalry[i].getDistance() > m_Ey_Archer[j].getDistance())
							m_Ey_Archer[j].setHitTest(0);
						else if(m_Ey_Archer[j].getDistance() > m_Ey_Cavalry[i].getDistance())
							m_Ey_Cavalry[i].setHitTest(0);
						else
							m_Ey_Archer[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<ECA;j++)
			{
				if(i == j)
					continue;
				if(m_Ey_Cavalry[i].getHitTest() == 1 && m_Ey_Cavalry[j].getHitTest() == 1)
				{
					if(	m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() > m_Ey_Cavalry[j].getPosX()  &&
						m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() < m_Ey_Cavalry[j].getPosX() + TILE_WIDTH &&
						m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() > m_Ey_Cavalry[j].getPosY()  &&
						m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() < m_Ey_Cavalry[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() > m_Ey_Cavalry[i].getPosX()  &&
						m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() < m_Ey_Cavalry[i].getPosX() + TILE_WIDTH &&
						m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() > m_Ey_Cavalry[i].getPosY()  &&
						m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() < m_Ey_Cavalry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Cavalry[i].getDistance() > m_Ey_Cavalry[j].getDistance())
							m_Ey_Cavalry[j].setHitTest(0);
						else if(m_Ey_Cavalry[j].getDistance() > m_Ey_Cavalry[i].getDistance())
							m_Ey_Cavalry[i].setHitTest(0);
						else
							m_Ey_Cavalry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<EPR;j++)
			{
				if(m_Ey_Cavalry[i].getHitTest() == 1 && m_Ey_Priest[j].getHitTest() == 1)
				{
					if(	m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() > m_Ey_Priest[j].getPosX()  &&
						m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() < m_Ey_Priest[j].getPosX() + TILE_WIDTH &&
						m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() > m_Ey_Priest[j].getPosY()  &&
						m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() < m_Ey_Priest[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Priest[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[j].getMoveSpeedX() > m_Ey_Cavalry[i].getPosX()  &&
						m_Ey_Priest[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[j].getMoveSpeedX() < m_Ey_Cavalry[i].getPosX() + TILE_WIDTH &&
						m_Ey_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[j].getMoveSpeedY() > m_Ey_Cavalry[i].getPosY()  &&
						m_Ey_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[j].getMoveSpeedY() < m_Ey_Cavalry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Cavalry[i].getDistance() > m_Ey_Priest[j].getDistance())
							m_Ey_Priest[j].setHitTest(0);
						else if(m_Ey_Priest[j].getDistance() > m_Ey_Cavalry[i].getDistance())
							m_Ey_Cavalry[i].setHitTest(0);
						else
							m_Ey_Priest[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<ESP;j++)
			{
				if(m_Ey_Cavalry[i].getHitTest() == 1 && m_Ey_Spearman[j].getHitTest() == 1)
				{
					if(	m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() > m_Ey_Spearman[j].getPosX()  &&
						m_Ey_Cavalry[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[i].getMoveSpeedX() < m_Ey_Spearman[j].getPosX() + TILE_WIDTH &&
						m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() > m_Ey_Spearman[j].getPosY()  &&
						m_Ey_Cavalry[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[i].getMoveSpeedY() < m_Ey_Spearman[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[j].getMoveSpeedX() > m_Ey_Cavalry[i].getPosX()  &&
						m_Ey_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[j].getMoveSpeedX() < m_Ey_Cavalry[i].getPosX() + TILE_WIDTH &&
						m_Ey_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[j].getMoveSpeedY() > m_Ey_Cavalry[i].getPosY()  &&
						m_Ey_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[j].getMoveSpeedY() < m_Ey_Cavalry[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Cavalry[i].getDistance() > m_Ey_Spearman[j].getDistance())
							m_Ey_Spearman[j].setHitTest(0);
						else if(m_Ey_Spearman[j].getDistance() > m_Ey_Cavalry[i].getDistance())
							m_Ey_Cavalry[i].setHitTest(0);
						else
							m_Ey_Spearman[j].setHitTest(0);
					}
				}
			}

		}
		
		//적군 사제 겹침방지(1)
		for(i=0;i<EPR;i++)
		{
			for(j=0;j<EIN;j++)
			{
				if(m_Ey_Priest[i].getHitTest() == 1 && m_Ey_Infantry[j].getHitTest() == 1)
				{
					if(	m_Ey_Priest[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[i].getMoveSpeedX() > m_Ey_Infantry[j].getPosX()  &&
						m_Ey_Priest[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[i].getMoveSpeedX() < m_Ey_Infantry[j].getPosX() + TILE_WIDTH &&
						m_Ey_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[i].getMoveSpeedY() > m_Ey_Infantry[j].getPosY()  &&
						m_Ey_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[i].getMoveSpeedY() < m_Ey_Infantry[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() > m_Ey_Priest[i].getPosX()  &&
						m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() < m_Ey_Priest[i].getPosX() + TILE_WIDTH &&
						m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() > m_Ey_Priest[i].getPosY()  &&
						m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() < m_Ey_Priest[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Priest[i].getDistance() > m_Ey_Infantry[j].getDistance())
							m_Ey_Infantry[j].setHitTest(0);
						else if(m_Ey_Infantry[j].getDistance() > m_Ey_Priest[i].getDistance())
							m_Ey_Priest[i].setHitTest(0);
						else
							m_Ey_Infantry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<EAR;j++)
			{
				if(m_Ey_Priest[i].getHitTest() == 1 && m_Ey_Archer[j].getHitTest() == 1)
				{
					if(	m_Ey_Priest[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[i].getMoveSpeedX() > m_Ey_Archer[j].getPosX()  &&
						m_Ey_Priest[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[i].getMoveSpeedX() < m_Ey_Archer[j].getPosX() + TILE_WIDTH &&
						m_Ey_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[i].getMoveSpeedY() > m_Ey_Archer[j].getPosY()  &&
						m_Ey_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[i].getMoveSpeedY() < m_Ey_Archer[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Archer[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[j].getMoveSpeedX() > m_Ey_Priest[i].getPosX()  &&
						m_Ey_Archer[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[j].getMoveSpeedX() < m_Ey_Priest[i].getPosX() + TILE_WIDTH &&
						m_Ey_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[j].getMoveSpeedY() > m_Ey_Priest[i].getPosY()  &&
						m_Ey_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[j].getMoveSpeedY() < m_Ey_Priest[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Priest[i].getDistance() > m_Ey_Archer[j].getDistance())
							m_Ey_Archer[j].setHitTest(0);
						else if(m_Ey_Archer[j].getDistance() > m_Ey_Priest[i].getDistance())
							m_Ey_Priest[i].setHitTest(0);
						else
							m_Ey_Archer[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<ECA;j++)
			{
				if(m_Ey_Priest[i].getHitTest() == 1 && m_Ey_Cavalry[j].getHitTest() == 1)
				{
					if(	m_Ey_Priest[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[i].getMoveSpeedX() > m_Ey_Cavalry[j].getPosX()  &&
						m_Ey_Priest[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[i].getMoveSpeedX() < m_Ey_Cavalry[j].getPosX() + TILE_WIDTH &&
						m_Ey_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[i].getMoveSpeedY() > m_Ey_Cavalry[j].getPosY()  &&
						m_Ey_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[i].getMoveSpeedY() < m_Ey_Cavalry[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() > m_Ey_Priest[i].getPosX()  &&
						m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() < m_Ey_Priest[i].getPosX() + TILE_WIDTH &&
						m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() > m_Ey_Priest[i].getPosY()  &&
						m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() < m_Ey_Priest[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Priest[i].getDistance() > m_Ey_Cavalry[j].getDistance())
							m_Ey_Cavalry[j].setHitTest(0);
						else if(m_Ey_Cavalry[j].getDistance() > m_Ey_Priest[i].getDistance())
							m_Ey_Priest[i].setHitTest(0);
						else
							m_Ey_Cavalry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<EPR;j++)
			{
				if(i == j)
					continue;
				if(m_Ey_Priest[i].getHitTest() == 1 && m_Ey_Priest[j].getHitTest() == 1)
				{
					if(	m_Ey_Priest[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[i].getMoveSpeedX() > m_Ey_Priest[j].getPosX()  &&
						m_Ey_Priest[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[i].getMoveSpeedX() < m_Ey_Priest[j].getPosX() + TILE_WIDTH &&
						m_Ey_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[i].getMoveSpeedY() > m_Ey_Priest[j].getPosY()  &&
						m_Ey_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[i].getMoveSpeedY() < m_Ey_Priest[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Priest[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[j].getMoveSpeedX() > m_Ey_Priest[i].getPosX()  &&
						m_Ey_Priest[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[j].getMoveSpeedX() < m_Ey_Priest[i].getPosX() + TILE_WIDTH &&
						m_Ey_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[j].getMoveSpeedY() > m_Ey_Priest[i].getPosY()  &&
						m_Ey_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[j].getMoveSpeedY() < m_Ey_Priest[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Priest[i].getDistance() > m_Ey_Priest[j].getDistance())
							m_Ey_Priest[j].setHitTest(0);
						else if(m_Ey_Priest[j].getDistance() > m_Ey_Priest[i].getDistance())
							m_Ey_Priest[i].setHitTest(0);
						else
							m_Ey_Priest[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<ESP;j++)
			{
				if(m_Ey_Priest[i].getHitTest() == 1 && m_Ey_Spearman[j].getHitTest() == 1)
				{
					if(	m_Ey_Priest[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[i].getMoveSpeedX() > m_Ey_Spearman[j].getPosX()  &&
						m_Ey_Priest[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[i].getMoveSpeedX() < m_Ey_Spearman[j].getPosX() + TILE_WIDTH &&
						m_Ey_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[i].getMoveSpeedY() > m_Ey_Spearman[j].getPosY()  &&
						m_Ey_Priest[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[i].getMoveSpeedY() < m_Ey_Spearman[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[j].getMoveSpeedX() > m_Ey_Priest[i].getPosX()  &&
						m_Ey_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[j].getMoveSpeedX() < m_Ey_Priest[i].getPosX() + TILE_WIDTH &&
						m_Ey_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[j].getMoveSpeedY() > m_Ey_Priest[i].getPosY()  &&
						m_Ey_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[j].getMoveSpeedY() < m_Ey_Priest[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Priest[i].getDistance() > m_Ey_Spearman[j].getDistance())
							m_Ey_Spearman[j].setHitTest(0);
						else if(m_Ey_Spearman[j].getDistance() > m_Ey_Priest[i].getDistance())
							m_Ey_Priest[i].setHitTest(0);
						else
							m_Ey_Spearman[j].setHitTest(0);
					}
				}
			}

		}
		//적군 창병 겹침방지(1)
		for(i=0;i<ESP;i++)
		{
			for(j=0;j<EIN;j++)
			{
				if(m_Ey_Spearman[i].getHitTest() == 1 && m_Ey_Infantry[j].getHitTest() == 1)
				{
					if(	m_Ey_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[i].getMoveSpeedX() > m_Ey_Infantry[j].getPosX()  &&
						m_Ey_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[i].getMoveSpeedX() < m_Ey_Infantry[j].getPosX() + TILE_WIDTH &&
						m_Ey_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[i].getMoveSpeedY() > m_Ey_Infantry[j].getPosY()  &&
						m_Ey_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[i].getMoveSpeedY() < m_Ey_Infantry[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() > m_Ey_Spearman[i].getPosX()  &&
						m_Ey_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Infantry[j].getMoveSpeedX() < m_Ey_Spearman[i].getPosX() + TILE_WIDTH &&
						m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() > m_Ey_Spearman[i].getPosY()  &&
						m_Ey_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Infantry[j].getMoveSpeedY() < m_Ey_Spearman[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Spearman[i].getDistance() > m_Ey_Infantry[j].getDistance())
							m_Ey_Infantry[j].setHitTest(0);
						else if(m_Ey_Infantry[j].getDistance() > m_Ey_Spearman[i].getDistance())
							m_Ey_Spearman[i].setHitTest(0);
						else
							m_Ey_Infantry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<EAR;j++)
			{
				if(m_Ey_Spearman[i].getHitTest() == 1 && m_Ey_Archer[j].getHitTest() == 1)
				{
					if(	m_Ey_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[i].getMoveSpeedX() > m_Ey_Archer[j].getPosX()  &&
						m_Ey_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[i].getMoveSpeedX() < m_Ey_Archer[j].getPosX() + TILE_WIDTH &&
						m_Ey_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[i].getMoveSpeedY() > m_Ey_Archer[j].getPosY()  &&
						m_Ey_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[i].getMoveSpeedY() < m_Ey_Archer[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Archer[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[j].getMoveSpeedX() > m_Ey_Spearman[i].getPosX()  &&
						m_Ey_Archer[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Archer[j].getMoveSpeedX() < m_Ey_Spearman[i].getPosX() + TILE_WIDTH &&
						m_Ey_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[j].getMoveSpeedY() > m_Ey_Spearman[i].getPosY()  &&
						m_Ey_Archer[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Archer[j].getMoveSpeedY() < m_Ey_Spearman[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Spearman[i].getDistance() > m_Ey_Archer[j].getDistance())
							m_Ey_Archer[j].setHitTest(0);
						else if(m_Ey_Archer[j].getDistance() > m_Ey_Spearman[i].getDistance())
							m_Ey_Spearman[i].setHitTest(0);
						else
							m_Ey_Archer[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<ECA;j++)
			{
				if(m_Ey_Spearman[i].getHitTest() == 1 && m_Ey_Cavalry[j].getHitTest() == 1)
				{
					if(	m_Ey_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[i].getMoveSpeedX() > m_Ey_Cavalry[j].getPosX()  &&
						m_Ey_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[i].getMoveSpeedX() < m_Ey_Cavalry[j].getPosX() + TILE_WIDTH &&
						m_Ey_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[i].getMoveSpeedY() > m_Ey_Cavalry[j].getPosY()  &&
						m_Ey_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[i].getMoveSpeedY() < m_Ey_Cavalry[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() > m_Ey_Spearman[i].getPosX()  &&
						m_Ey_Cavalry[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Cavalry[j].getMoveSpeedX() < m_Ey_Spearman[i].getPosX() + TILE_WIDTH &&
						m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() > m_Ey_Spearman[i].getPosY()  &&
						m_Ey_Cavalry[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Cavalry[j].getMoveSpeedY() < m_Ey_Spearman[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Spearman[i].getDistance() > m_Ey_Cavalry[j].getDistance())
							m_Ey_Cavalry[j].setHitTest(0);
						else if(m_Ey_Cavalry[j].getDistance() > m_Ey_Spearman[i].getDistance())
							m_Ey_Spearman[i].setHitTest(0);
						else
							m_Ey_Cavalry[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<EPR;j++)
			{
				if(i == j)
					continue;
				if(m_Ey_Spearman[i].getHitTest() == 1 && m_Ey_Priest[j].getHitTest() == 1)
				{
					if(	m_Ey_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[i].getMoveSpeedX() > m_Ey_Priest[j].getPosX()  &&
						m_Ey_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[i].getMoveSpeedX() < m_Ey_Priest[j].getPosX() + TILE_WIDTH &&
						m_Ey_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[i].getMoveSpeedY() > m_Ey_Priest[j].getPosY()  &&
						m_Ey_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[i].getMoveSpeedY() < m_Ey_Priest[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Priest[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[j].getMoveSpeedX() > m_Ey_Spearman[i].getPosX()  &&
						m_Ey_Priest[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Priest[j].getMoveSpeedX() < m_Ey_Spearman[i].getPosX() + TILE_WIDTH &&
						m_Ey_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[j].getMoveSpeedY() > m_Ey_Spearman[i].getPosY()  &&
						m_Ey_Priest[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Priest[j].getMoveSpeedY() < m_Ey_Spearman[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Spearman[i].getDistance() > m_Ey_Priest[j].getDistance())
							m_Ey_Priest[j].setHitTest(0);
						else if(m_Ey_Priest[j].getDistance() > m_Ey_Spearman[i].getDistance())
							m_Ey_Spearman[i].setHitTest(0);
						else
							m_Ey_Priest[j].setHitTest(0);
					}
				}
			}
			for(j=0;j<ESP;j++)
			{
				if(m_Ey_Spearman[i].getHitTest() == 1 && m_Ey_Spearman[j].getHitTest() == 1)
				{
					if(	m_Ey_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[i].getMoveSpeedX() > m_Ey_Spearman[j].getPosX()  &&
						m_Ey_Spearman[i].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[i].getMoveSpeedX() < m_Ey_Spearman[j].getPosX() + TILE_WIDTH &&
						m_Ey_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[i].getMoveSpeedY() > m_Ey_Spearman[j].getPosY()  &&
						m_Ey_Spearman[i].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[i].getMoveSpeedY() < m_Ey_Spearman[j].getPosY() + TILE_HEIGHT &&

						m_Ey_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[j].getMoveSpeedX() > m_Ey_Spearman[i].getPosX()  &&
						m_Ey_Spearman[j].getPosX() + (TILE_WIDTH/2) + m_Ey_Spearman[j].getMoveSpeedX() < m_Ey_Spearman[i].getPosX() + TILE_WIDTH &&
						m_Ey_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[j].getMoveSpeedY() > m_Ey_Spearman[i].getPosY()  &&
						m_Ey_Spearman[j].getPosY() + (TILE_HEIGHT/2) + m_Ey_Spearman[j].getMoveSpeedY() < m_Ey_Spearman[i].getPosY() + TILE_HEIGHT
						)
					{
						if(m_Ey_Spearman[i].getDistance() > m_Ey_Spearman[j].getDistance())
							m_Ey_Spearman[j].setHitTest(0);
						else if(m_Ey_Spearman[j].getDistance() > m_Ey_Spearman[i].getDistance())
							m_Ey_Spearman[i].setHitTest(0);
						else
							m_Ey_Spearman[j].setHitTest(0);
					}
				}
			}

		}






























		//for(int k=0; k<(MIN/2); k++)
		//{
		//	bool BreakOk = false;
		//	//아군보병겹침방지(1)
		//	for(i=0;i<MIN;i++)
		//	{
		//		//if(m_My_Infantry[i].getState_Live() != LIVE)
		//			//	continue;

		//		for(j=0;j<MIN;j++)
		//		{
		//			if(i == j)
		//				continue;
		//			//if(m_My_Infantry[j].getState_Live() != LIVE)
		//		//		continue;
		//			if(m_My_Infantry[i].getHitTest() == 1 && m_My_Infantry[j].getHitTest() == 1)
		//			{
		//				if(	m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() > m_My_Infantry[j].getPosX()  &&
		//					m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() < m_My_Infantry[j].getPosX() + TILE_WIDTH &&
		//					m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() > m_My_Infantry[j].getPosY()  &&
		//					m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() < m_My_Infantry[j].getPosY() + TILE_HEIGHT &&

		//					m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() > m_My_Infantry[i].getPosX()  &&
		//					m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() < m_My_Infantry[i].getPosX() + TILE_WIDTH &&
		//					m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() > m_My_Infantry[i].getPosY()  &&
		//					m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() < m_My_Infantry[i].getPosY() + TILE_HEIGHT
		//					)
		//				{
		//					if(m_My_Infantry[i].getDistance() > m_My_Infantry[j].getDistance())
		//					{
		//						m_My_Infantry[j].setHitTest(0);
		//						BreakOk = true;
		//						
		//					}
		//					else if(m_My_Infantry[j].getDistance() > m_My_Infantry[i].getDistance())
		//					{
		//						m_My_Infantry[i].setHitTest(0);
		//						BreakOk = true;
		//					}
		//					else
		//					{
		//						m_My_Infantry[j].setHitTest(0);
		//						BreakOk = true;
		//					}
		//				}
		//			}

		//			if(m_My_Infantry[i].getHitTest() == 0 && m_My_Infantry[j].getHitTest() == 0)
		//			{
		//				if(	m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() > m_My_Infantry[j].getPosX()  &&
		//					m_My_Infantry[i].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[i].getMoveSpeedX() < m_My_Infantry[j].getPosX() + TILE_WIDTH &&
		//					m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() > m_My_Infantry[j].getPosY()  &&
		//					m_My_Infantry[i].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[i].getMoveSpeedY() < m_My_Infantry[j].getPosY() + TILE_HEIGHT &&

		//					m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() > m_My_Infantry[i].getPosX()  &&
		//					m_My_Infantry[j].getPosX() + (TILE_WIDTH/2) + m_My_Infantry[j].getMoveSpeedX() < m_My_Infantry[i].getPosX() + TILE_WIDTH &&
		//					m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() > m_My_Infantry[i].getPosY()  &&
		//					m_My_Infantry[j].getPosY() + (TILE_HEIGHT/2) + m_My_Infantry[j].getMoveSpeedY() < m_My_Infantry[i].getPosY() + TILE_HEIGHT
		//					)
		//				{
		//					if(m_My_Infantry[i].getDistance() > m_My_Infantry[j].getDistance())
		//					{
		//						m_My_Infantry[i].setHitTest(1);
		//						BreakOk = true;
		//						
		//					}
		//					else if(m_My_Infantry[j].getDistance() > m_My_Infantry[i].getDistance())
		//					{
		//						m_My_Infantry[j].setHitTest(1);
		//						BreakOk = true;
		//					}
		//					else
		//					{
		//						m_My_Infantry[i].setHitTest(1);
		//						BreakOk = true;
		//					}
		//				}
		//			}
		//		}






		//	}
		//	if(BreakOk == false)
		//		break;
		//}



























		
		//실질적인 이동실행
		for(int i=0;i<MIN;i++)
		{	
			m_My_Infantry[i].Move();	
		}
		for(int i=0;i<EIN;i++)
		{	
			m_Ey_Infantry[i].Move();	
		}
		for(int i=0;i<MAR;i++)
		{	
			m_My_Archer[i].Move();	
		}
		for(int i=0;i<EAR;i++)
		{	
			m_Ey_Archer[i].Move();	
		}
		for(int i=0;i<MCA;i++)
		{
			m_My_Cavalry[i].Move();
		}
		for(int i=0;i<ECA;i++)
		{
			m_Ey_Cavalry[i].Move();	
		}
		for(int i=0;i<MPR;i++)
		{
			m_My_Priest[i].Move();
		}
		for(int i=0;i<EPR;i++)
		{
			m_Ey_Priest[i].Move();
		}
		for(int i=0;i<MSP;i++)
		{
			m_My_Spearman[i].Move();
		}
		for(int i=0;i<ESP;i++)
		{
			m_Ey_Spearman[i].Move();
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
		for(int i=0;i<MAR;i++)
		{	
			m_My_Archer[i].Reset();	
		}
		for(int i=0;i<EAR;i++)
		{	
			m_Ey_Archer[i].Reset();	
		}
		for(int i=0;i<MCA;i++)
		{
			m_My_Cavalry[i].Reset();	
		}
		for(int i=0;i<ECA;i++)
		{
			m_Ey_Cavalry[i].Reset();	
		}
		for(int i=0;i<MPR;i++)
		{
			m_My_Priest[i].Reset();	
		}
		for(int i=0;i<EPR;i++)
		{
			m_Ey_Priest[i].Reset();	
		}
		for(int i=0;i<MSP;i++)
		{
			m_My_Spearman[i].Reset();	
		}
		for(int i=0;i<ESP;i++)
		{
			m_Ey_Spearman[i].Reset();	
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


		//생존여부 검사//게임의 결과 검사

		//모든아군이 죽으면 패배
		//모든적군이 죽으면 승리
		

		
		for(i=0; i<EIN; i++)
		{
			if(m_Ey_Infantry[i].getState_Live() == LIVE)
				break;
		}
		if(i==EIN)
		{

			for(i=0; i<EAR; i++)
			{
				if(m_Ey_Archer[i].getState_Live() == LIVE)
					break;
			}
			if(i==EAR)
			{
				for(i=0; i<ECA; i++)
				{
					if(m_Ey_Cavalry[i].getState_Live() == LIVE)
						break;
				}
				if(i==ECA)
				{
					for(i=0; i<EPR; i++)
					{
						if(m_Ey_Priest[i].getState_Live() == LIVE)
							break;
					}
					if(i==EPR)
					{
						for(i=0; i<ESP; i++)
						{
							if(m_Ey_Spearman[i].getState_Live() == LIVE)
								break;
						}
						if(i==ESP)
						{
							GameStep = END;
							GameResult = VICTORY;
						}
					}
				}
			}
		}

		//모든적군 검사

		for(i=0; i<MIN; i++)
		{
			if(m_My_Infantry[i].getState_Live() == LIVE)
				break;
		}
		if(i==MIN)
		{

			for(i=0; i<MAR; i++)
			{
				if(m_My_Archer[i].getState_Live() == LIVE)
					break;
			}
			if(i==MAR)
			{
				for(i=0; i<MCA; i++)
				{
					if(m_My_Cavalry[i].getState_Live() == LIVE)
						break;
				}
				if(i==MCA)
				{
					for(i=0; i<MPR; i++)
					{
						if(m_My_Priest[i].getState_Live() == LIVE)
							break;
					}
					if(i==MPR)
					{
						for(i=0; i<MSP; i++)
						{
							if(m_My_Spearman[i].getState_Live() == LIVE)
								break;
						}
						if(i==MSP)
						{
							GameStep = END;
							GameResult = DEFEAT;
						}
					}
				}

			}
		}





	}
}
void cGame::Render()
{


	for(int j=0; j<SelectMap_Height; j++)
	{
		for(int i=0; i<SelectMap_Width; i++)
		{
			if(TerrainMap[j][i] == 101)
			{
				m_Tile_Grass01.Draw( (int)(((double)((i*TILE_HEIGHT) + GRID_X  - offset.x)/(double)100)*MapScale),
					(int)(((double)((j*TILE_HEIGHT) + GRID_Y  - offset.y)/(double)100)*MapScale),
					0,0,
					(int)((double)(((double)TILE_WIDTH/(double)100)*(double)MapScale)), (int)((double)(((double)TILE_HEIGHT/(double)100)*(double)MapScale)),TILE_WIDTH,TILE_HEIGHT);
			}
			else if(TerrainMap[j][i] == 102)
			{
				m_Tile_Grass02.Draw( (int)(((double)((i*TILE_HEIGHT) + GRID_X  - offset.x)/(double)100)*MapScale),
					(int)(((double)((j*TILE_HEIGHT) + GRID_Y  - offset.y)/(double)100)*MapScale),
					0,0,
					(int)((double)(((double)TILE_WIDTH/(double)100)*(double)MapScale)), (int)((double)(((double)TILE_HEIGHT/(double)100)*(double)MapScale)),TILE_WIDTH,TILE_HEIGHT);
			}
			else if(TerrainMap[j][i] == 103)
			{
				m_Tile_Grass03.Draw( (int)(((double)((i*TILE_HEIGHT) + GRID_X  - offset.x)/(double)100)*MapScale),
					(int)(((double)((j*TILE_HEIGHT) + GRID_Y  - offset.y)/(double)100)*MapScale),
					0,0,
					(int)((double)(((double)TILE_WIDTH/(double)100)*(double)MapScale)), (int)((double)(((double)TILE_HEIGHT/(double)100)*(double)MapScale)),TILE_WIDTH,TILE_HEIGHT);
			}
			else if(TerrainMap[j][i] == 104)
			{
				m_Tile_Grass04.Draw( (int)(((double)((i*TILE_HEIGHT) + GRID_X  - offset.x)/(double)100)*MapScale),
					(int)(((double)((j*TILE_HEIGHT) + GRID_Y  - offset.y)/(double)100)*MapScale),
					0,0,
					(int)((double)(((double)TILE_WIDTH/(double)100)*(double)MapScale)), (int)((double)(((double)TILE_HEIGHT/(double)100)*(double)MapScale)),TILE_WIDTH,TILE_HEIGHT);
			}

		}
	}
	
	//격자드로우
	if(m_Grid_OnOff == true || (GetKeyState(VK_G) & 0x8000))
	{
		for(int j=0; j<SelectMap_Height; j++)
		{
			for(int i=0; i<SelectMap_Width; i++)
			{
				m_GridImg.Draw(   (((i*TILE_HEIGHT+1) + GRID_X - offset.x)/(double)100)*(double)MapScale  ,
					(((j*TILE_WIDTH+1) + GRID_Y - offset.y)/(double)100)*(double)MapScale	,
					0,0,
					(double)(((double)(TILE_WIDTH)/(double)100)*(double)MapScale),(double)(((double)(TILE_WIDTH)/(double)100)*(double)MapScale),TILE_WIDTH,TILE_WIDTH,RGB(255,0,255));
			}

		}
	}
	

	

	if(GameStep < ACTION)
	{
		for(int j=0; j<SelectMap_Height; j++)
		{
			for(int i=0; i<SelectMap_Width; i++)
			{
				if(TileMap[j][i] == INFANTRY)
				{
					m_My_InfantryImg.Draw( (((i*TILE_HEIGHT) + GRID_X  - offset.x)/(double)100)*(double)MapScale,
						(((j*TILE_WIDTH) + GRID_Y  - offset.y)/(double)100)*(double)MapScale,
						0,0,
						(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),TILE_WIDTH,TILE_WIDTH);
				}
				else if(TileMap[j][i] == ARCHER)
				{
					m_My_ArcherImg.Draw( (((i*TILE_HEIGHT) + GRID_X - offset.x)/(double)100)*(double)MapScale,
						(((j*TILE_WIDTH) + GRID_Y - offset.y)/(double)100)*(double)MapScale,
						0,0,
						(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),TILE_WIDTH,TILE_WIDTH);
				}
				else if(TileMap[j][i] == CAVALRY)
				{
					m_My_CavalryImg.Draw( (((i*TILE_HEIGHT) + GRID_X - offset.x)/(double)100)*(double)MapScale,
						(((j*TILE_WIDTH) + GRID_Y - offset.y)/(double)100)*(double)MapScale,
						0,0,
						(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),TILE_WIDTH,TILE_WIDTH);
				}
				else if(TileMap[j][i] == PRIEST)
				{
					m_My_PriestImg.Draw( (((i*TILE_HEIGHT) + GRID_X - offset.x)/(double)100)*(double)MapScale,
						(((j*TILE_WIDTH) + GRID_Y - offset.y)/(double)100)*(double)MapScale,
						0,0,
						(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),TILE_WIDTH,TILE_WIDTH);
				}
				else if(TileMap[j][i] == SPEARMAN)
				{
					m_My_SpearmanImg.Draw( (((i*TILE_HEIGHT) + GRID_X - offset.x)/(double)100)*(double)MapScale,
						(((j*TILE_WIDTH) + GRID_Y - offset.y)/(double)100)*(double)MapScale,
						0,0,
						(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),TILE_WIDTH,TILE_WIDTH);
				}
			}
		}



		for(int j=0; j<SelectMap_Height; j++)
		{
			for(int i=0; i<SelectMap_Width; i++)
			{
				if(Enemy_TileMap[j][i] == INFANTRY)
				{
					m_Ey_InfantryImg.Draw( (((i*TILE_HEIGHT) + GRID_X - offset.x)/(double)100)*(double)MapScale,
						(((j*TILE_WIDTH) + GRID_Y - offset.y)/(double)100)*(double)MapScale,
						0,0,
						(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),TILE_WIDTH,TILE_WIDTH);
				}
				else if(Enemy_TileMap[j][i] == ARCHER)
				{
					m_Ey_ArcherImg.Draw( (((i*TILE_HEIGHT) + GRID_X - offset.x)/(double)100)*(double)MapScale,
						(((j*TILE_WIDTH) + GRID_Y - offset.y)/(double)100)*(double)MapScale,
						0,0,
						(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),TILE_WIDTH,TILE_WIDTH);
				}
				else if(Enemy_TileMap[j][i] == CAVALRY)
				{
					m_Ey_CavalryImg.Draw( (((i*TILE_HEIGHT) + GRID_X - offset.x)/(double)100)*(double)MapScale,
						(((j*TILE_WIDTH) + GRID_Y - offset.y)/(double)100)*(double)MapScale,
						0,0,
						(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),TILE_WIDTH,TILE_WIDTH);
				}
				else if(Enemy_TileMap[j][i] == PRIEST)
				{
					m_Ey_PriestImg.Draw( (((i*TILE_HEIGHT) + GRID_X - offset.x)/(double)100)*(double)MapScale,
						(((j*TILE_WIDTH) + GRID_Y - offset.y)/(double)100)*(double)MapScale,
						0,0,
						(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),TILE_WIDTH,TILE_WIDTH);
				}
				else if(Enemy_TileMap[j][i] == SPEARMAN)
				{
					m_Ey_SpearmanImg.Draw( (((i*TILE_HEIGHT) + GRID_X - offset.x)/(double)100)*(double)MapScale,
						(((j*TILE_WIDTH) + GRID_Y - offset.y)/(double)100)*(double)MapScale,
						0,0,
						(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),(double)(((double)TILE_WIDTH/(double)100)*(double)MapScale),TILE_WIDTH,TILE_WIDTH);
				}
			}
		}
	}

	if(GameStep == READY)
	{
		if(m_SelectMenu == 1)
		{
			if(m_ShowInv == true)
			{
				g_Graphics.DrawString(260,100,"보병");
				sprintf(strTemp,"%d명",Buy_Infantry);
				g_Graphics.DrawString(260,115,strTemp);
				g_Graphics.DrawString(260,130,"배치");

				g_Graphics.DrawString(360,100,"궁수");
				sprintf(strTemp,"%d명",Buy_Archer);
				g_Graphics.DrawString(360,115,strTemp);
				g_Graphics.DrawString(360,130,"배치");

				g_Graphics.DrawString(460,100,"기병");
				sprintf(strTemp,"%d명",Buy_Cavalry);
				g_Graphics.DrawString(460,115,strTemp);
				g_Graphics.DrawString(460,130,"배치");

				g_Graphics.DrawString(560,100,"사제");
				sprintf(strTemp,"%d명",Buy_Priest);
				g_Graphics.DrawString(560,115,strTemp);
				g_Graphics.DrawString(560,130,"배치");

				g_Graphics.DrawString(660,100,"창병");
				sprintf(strTemp,"%d명",Buy_Spearman);
				g_Graphics.DrawString(660,115,strTemp);
				g_Graphics.DrawString(660,130,"배치");
			}
		}
	}
	else if(GameStep == ACTION)
	{
		for(int i=0; i<MAR; i++)
		{
			if(m_My_Archer[i].getState_Live() == LIVE)
			{
				m_My_ArcherImg.Draw(m_My_Archer[i].getPosX() - offset.x,m_My_Archer[i].getPosY() - offset.y);
			}
		}
		for(int i=0; i<EAR; i++)
		{
			if(m_Ey_Archer[i].getState_Live() == LIVE)
			{
				m_Ey_ArcherImg.Draw(m_Ey_Archer[i].getPosX() - offset.x,m_Ey_Archer[i].getPosY() - offset.y);

			}
		}

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
				m_Ey_InfantryImg.Draw(m_Ey_Infantry[i].getPosX() - offset.x,m_Ey_Infantry[i].getPosY() - offset.y);
		}

		for(int i=0;i<MCA;i++)
		{
			if(m_My_Cavalry[i].getState_Live() == LIVE)
				m_My_CavalryImg.Draw(m_My_Cavalry[i].getPosX() - offset.x,m_My_Cavalry[i].getPosY() - offset.y);
		}
		for(int i=0;i<ECA;i++)
		{
			if(m_Ey_Cavalry[i].getState_Live() == LIVE)
				m_Ey_CavalryImg.Draw(m_Ey_Cavalry[i].getPosX() - offset.x,m_Ey_Cavalry[i].getPosY() - offset.y);
		}

		for(int i=0;i<MSP;i++)
		{
			if(m_My_Spearman[i].getState_Live() == LIVE)
				m_My_SpearmanImg.Draw(m_My_Spearman[i].getPosX() - offset.x,m_My_Spearman[i].getPosY() - offset.y);
		}
		for(int i=0;i<ESP;i++)
		{
			if(m_Ey_Spearman[i].getState_Live() == LIVE)
				m_Ey_SpearmanImg.Draw(m_Ey_Spearman[i].getPosX() - offset.x,m_Ey_Spearman[i].getPosY() - offset.y);
		}



		//프리스트렌더는 힐붙어있음 맨뒤로 ㅋ
		for(int i=0;i<MPR;i++)
		{
			if(m_My_Priest[i].getState_Live() == LIVE)
				m_My_PriestImg.Draw(m_My_Priest[i].getPosX() - offset.x,m_My_Priest[i].getPosY() - offset.y);
			m_My_Priest[i].Render(offset);
		}
		for(int i=0;i<EPR;i++)
		{
			if(m_Ey_Priest[i].getState_Live() == LIVE)
				m_Ey_PriestImg.Draw(m_Ey_Priest[i].getPosX() - offset.x,m_Ey_Priest[i].getPosY() - offset.y);
			m_Ey_Priest[i].Render(offset);
		}



		
		for(int i=0;i<MIN;i++)
		{
			if(m_My_Infantry[i].getState_Live() == LIVE)
			{
				sprintf(strTemp,"%lf",m_My_Infantry[i].getAngle());
				g_Graphics.DrawString(m_My_Infantry[i].getPosX() - offset.x + 10,m_My_Infantry[i].getPosY()-40 - offset.y,strTemp);
			}
		}

		const int HpOffset = 10;
		const int HpWidth  = 50;
		const int HpHeidht = 10;
		for(int i=0;i<MIN;i++)
		{
			if(m_My_Infantry[i].getState_Live() == LIVE)
			{
				
				m_Hp.Draw(m_My_Infantry[i].getPosX() - offset.x,m_My_Infantry[i].getPosY() - HpOffset - offset.y,0,0,( (double)m_My_Infantry[i].getHp() / (double)m_My_Infantry[i].getMaxHp()) * HpWidth,HpHeidht,50,10);
				m_Hp_Max.Draw(m_My_Infantry[i].getPosX() - offset.x,m_My_Infantry[i].getPosY() - HpOffset - offset.y,0,0,HpWidth,HpHeidht,50,10,RGB(255,0,255));
				/*sprintf(strTemp,"%d / %d (%d)",m_My_Infantry[i].getHp(),m_My_Infantry[i].getMaxHp(),m_My_Infantry[i].getHitTest());
				g_Graphics.DrawString(m_My_Infantry[i].getPosX() - offset.x,m_My_Infantry[i].getPosY()-20 - offset.y,strTemp);*/
			}
		}


		for(int i=0;i<EIN;i++)
		{
			if(m_Ey_Infantry[i].getState_Live() == LIVE)
			{
				m_Hp.Draw(m_Ey_Infantry[i].getPosX() - offset.x,m_Ey_Infantry[i].getPosY() - HpOffset - offset.y,0,0,( (double)m_Ey_Infantry[i].getHp() / (double)m_Ey_Infantry[i].getMaxHp()) * HpWidth,HpHeidht,50,10);
				m_Hp_Max.Draw(m_Ey_Infantry[i].getPosX() - offset.x,m_Ey_Infantry[i].getPosY() - HpOffset - offset.y,0,0,HpWidth,HpHeidht,50,10,RGB(255,0,255));
			}
		}
		for(int i=0; i<MAR; i++)
		{
			if(m_My_Archer[i].getState_Live() == LIVE)
			{
				m_Hp.Draw(m_My_Archer[i].getPosX() - offset.x,m_My_Archer[i].getPosY() - HpOffset - offset.y,0,0,( (double)m_My_Archer[i].getHp() / (double)m_My_Archer[i].getMaxHp()) * HpWidth,HpHeidht,50,10);
				m_Hp_Max.Draw(m_My_Archer[i].getPosX() - offset.x,m_My_Archer[i].getPosY() - HpOffset - offset.y,0,0,HpWidth,HpHeidht,50,10,RGB(255,0,255));
			}
		}

		for(int i=0; i<EAR; i++)
		{
			if(m_Ey_Archer[i].getState_Live() == LIVE)
			{
				m_Hp.Draw(m_Ey_Archer[i].getPosX() - offset.x,m_Ey_Archer[i].getPosY() - HpOffset - offset.y,0,0,( (double)m_Ey_Archer[i].getHp() / (double)m_Ey_Archer[i].getMaxHp()) * HpWidth,HpHeidht,50,10);
				m_Hp_Max.Draw(m_Ey_Archer[i].getPosX() - offset.x,m_Ey_Archer[i].getPosY() - HpOffset - offset.y,0,0,HpWidth,HpHeidht,50,10,RGB(255,0,255));
			}
		}

		for(int i=0;i<MCA;i++)
		{
			if(m_My_Cavalry[i].getState_Live() == LIVE)
			{
				m_Hp.Draw(m_My_Cavalry[i].getPosX() - offset.x,m_My_Cavalry[i].getPosY() - HpOffset - offset.y,0,0,( (double)m_My_Cavalry[i].getHp() / (double)m_My_Cavalry[i].getMaxHp()) * HpWidth,HpHeidht,50,10);
				m_Hp_Max.Draw(m_My_Cavalry[i].getPosX() - offset.x,m_My_Cavalry[i].getPosY() - HpOffset - offset.y,0,0,HpWidth,HpHeidht,50,10,RGB(255,0,255));
			}
		}
		for(int i=0;i<ECA;i++)
		{
			if(m_Ey_Cavalry[i].getState_Live() == LIVE)
			{
				m_Hp.Draw(m_Ey_Cavalry[i].getPosX() - offset.x,m_Ey_Cavalry[i].getPosY() - HpOffset - offset.y,0,0,( (double)m_Ey_Cavalry[i].getHp() / (double)m_Ey_Cavalry[i].getMaxHp()) * HpWidth,HpHeidht,50,10);
				m_Hp_Max.Draw(m_Ey_Cavalry[i].getPosX() - offset.x,m_Ey_Cavalry[i].getPosY() - HpOffset - offset.y,0,0,HpWidth,HpHeidht,50,10,RGB(255,0,255));
			}
		}

		for(int i=0;i<MPR;i++)
		{
			if(m_My_Priest[i].getState_Live() == LIVE)
			{
				m_Hp.Draw(m_My_Priest[i].getPosX() - offset.x,m_My_Priest[i].getPosY() - HpOffset - offset.y,0,0,( (double)m_My_Priest[i].getHp() / (double)m_My_Priest[i].getMaxHp()) * HpWidth,HpHeidht,50,10);
				m_Hp_Max.Draw(m_My_Priest[i].getPosX() - offset.x,m_My_Priest[i].getPosY() - HpOffset - offset.y,0,0,HpWidth,HpHeidht,50,10,RGB(255,0,255));
			}
		}
		for(int i=0;i<EPR;i++)
		{
			if(m_Ey_Priest[i].getState_Live() == LIVE)
			{
				m_Hp.Draw(m_Ey_Priest[i].getPosX() - offset.x,m_Ey_Priest[i].getPosY() - HpOffset - offset.y,0,0,( (double)m_Ey_Priest[i].getHp() / (double)m_Ey_Priest[i].getMaxHp()) * HpWidth,HpHeidht,50,10);
				m_Hp_Max.Draw(m_Ey_Priest[i].getPosX() - offset.x,m_Ey_Priest[i].getPosY() - HpOffset - offset.y,0,0,HpWidth,HpHeidht,50,10,RGB(255,0,255));
			}
		}
		for(int i=0;i<MSP;i++)
		{
			if(m_My_Spearman[i].getState_Live() == LIVE)
			{
				m_Hp.Draw(m_My_Spearman[i].getPosX() - offset.x,m_My_Spearman[i].getPosY() - HpOffset - offset.y,0,0,( (double)m_My_Spearman[i].getHp() / (double)m_My_Spearman[i].getMaxHp()) * HpWidth,HpHeidht,50,10);
				m_Hp_Max.Draw(m_My_Spearman[i].getPosX() - offset.x,m_My_Spearman[i].getPosY() - HpOffset - offset.y,0,0,HpWidth,HpHeidht,50,10,RGB(255,0,255));
			}
		}		

		for(int i=0;i<ESP;i++)
		{
			if(m_Ey_Spearman[i].getState_Live() == LIVE)
			{
				m_Hp.Draw(m_Ey_Spearman[i].getPosX() - offset.x,m_Ey_Spearman[i].getPosY() - HpOffset - offset.y,0,0,( (double)m_Ey_Spearman[i].getHp() / (double)m_Ey_Spearman[i].getMaxHp()) * HpWidth,HpHeidht,50,10);
				m_Hp_Max.Draw(m_Ey_Spearman[i].getPosX() - offset.x,m_Ey_Spearman[i].getPosY() - HpOffset - offset.y,0,0,HpWidth,HpHeidht,50,10,RGB(255,0,255));
			}
		}





		for(int i=0; i<MAR; i++)
		{
			if(m_My_Archer[i].Arrow->getLive() == true)
				m_ArrowImg.Draw(m_My_Archer[i].Arrow->getPosX() - offset.x,m_My_Archer[i].Arrow->getPosY() - offset.y);
		}


		for(int i=0; i<EAR; i++)
		{
			if(m_Ey_Archer[i].Arrow->getLive() == true)
				m_ArrowImg.Draw(m_Ey_Archer[i].Arrow->getPosX() - offset.x,m_Ey_Archer[i].Arrow->getPosY() - offset.y);
		}




		for(int i=0; i<MPR;i++)
		{
			m_My_Priest[i].Update(passTime,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP);
		}
		for(int i=0; i<EPR; i++)
		{
			m_Ey_Priest[i].Update(passTime,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP);
		}


	}
	
	
	
	m_Interface01.Draw(0,0);
	m_Interface02.Draw(0,100);

	g_Graphics.DrawString(60,100,"군사");
	g_Graphics.DrawString(100,600,Message);

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

	sprintf(strTemp,"ViewScale :%d",MapScale);
	g_Graphics.DrawString(900,45,strTemp);





	g_Graphics.DrawString(300,500,"게임메인화면");
	sprintf(strTemp,"(%d,%d)",x,y);
	g_Graphics.DrawString(700,0,strTemp);


	sprintf(strTemp,"offset(%f,%f)",offset.x,offset.y);
	g_Graphics.DrawString(600,60,strTemp);

	
	if(GameStep == END)
	{
		m_BlackGround.Draw(0,0);
		if(BlackAlphaReturn < 1)
		{
			BlackAlpha+=AlphaSpeed;

			if(BlackAlpha > 254)
			{
				BlackAlphaReturn++;
			}
		}
		
		if(GameResult == DEFEAT)
		{
			if(Game_Lose.Played == false)
				Game_Lose.PLAYSound();
			m_RedGround.AlphaDraw(0,0,0,0,1200,750,1200,750,BlackAlpha);
		}
		else if(GameResult == VICTORY)
		{	
			if(Game_Win.Played == false)
				Game_Win.PLAYSound();
			m_End_Victory.AlphaDraw(0,0,0,0,1200,750,1200,750,BlackAlpha);
		}
			 
	}

	if(Spell.State == 1)
		g_Graphics.DrawCircle(x,y,Spell.SpellRange);
	Game_b_Back.Render();
	
}
int cGame::Destroy()
{

	
	if(GameStep >= CREATE)
		{
		delete []m_My_Infantry;
		delete []m_My_Archer;
		delete []m_My_Cavalry;
		delete []m_My_Priest;
		delete []m_My_Spearman;
	}
	
	delete []m_Ey_Infantry;
	delete []m_Ey_Archer;
	delete []m_Ey_Cavalry;
	delete []m_Ey_Priest;
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
	m_ArrowImg.Destroy();

	m_BlackGround.Destroy();
	m_RedGround.Destroy();
	m_GridImg.Destroy();
	m_Tile_Grass01.Destroy();
	m_Tile_Grass02.Destroy();
	m_Tile_Grass03.Destroy();
	m_Tile_Grass04.Destroy();
	m_Interface01.Destroy();

	m_End_Victory.Destroy();

	Game_Win.DeleteSound();
	Game_Lose.DeleteSound();
	if(TileMap != NULL)
	{       
		for( int nCount = 0; nCount < SelectMap_Height ; nCount++ )
		{ 
			delete[]  TileMap[nCount] ;
		}
		delete[] TileMap;
		TileMap = NULL;
	}
	
	if(Enemy_TileMap != NULL)
	{       
		for( int nCount = 0; nCount < SelectMap_Height ; nCount++ )
		{ 
			delete[]  Enemy_TileMap[nCount] ;
		}
		delete[] Enemy_TileMap ;
		Enemy_TileMap = NULL;
	}
	if(WallMap != NULL)
	{       
		for( int nCount = 0; nCount < SelectMap_Height ; nCount++ )
		{ 
			delete[]  WallMap[nCount] ;
		}
		delete[] WallMap ;
		WallMap = NULL;
	}
	if(TerrainMap != NULL)
	{       
		for( int nCount = 0; nCount < SelectMap_Height ; nCount++ )
		{ 
			delete[] TerrainMap[nCount] ;
		}
		delete[] TerrainMap ;
		TerrainMap = NULL;
	}

	return MENU;
}
void cGame::KeyCheck()
{
	static DWORD Z_Key_Time = 0;
	if(GetKeyState(VK_UP) & 0x8000)
	{
		if(offset.y > 0 )
			offset.y -= (CameraSpeed/(double)MapScale)*(double)100;
		if(offset.y < 0 )
			offset.y = 0.000006;
	}
	if(GetKeyState(VK_DOWN) & 0x8000)
	{
		if(offset.y < (SelectMap_Height * TILE_HEIGHT) - SCR_HEIGHT + GRID_Y + 38)
			offset.y += (CameraSpeed/(double)MapScale)*(double)100;
		if(offset.y > (SelectMap_Height * TILE_HEIGHT) - SCR_HEIGHT + GRID_Y + 38)
			offset.y = ((SelectMap_Height * TILE_HEIGHT) - SCR_HEIGHT) + 0.000006 + GRID_Y + 38;

	}
	if(GetKeyState(VK_RIGHT) & 0x8000)
	{
		if(offset.x < (SelectMap_Width * TILE_WIDTH) - SCR_WIDTH + GRID_X + 16)
			offset.x += (CameraSpeed/(double)MapScale)*(double)100;
		if(offset.x > (SelectMap_Width * TILE_WIDTH) - SCR_WIDTH + GRID_X + 16)
			offset.x = ((SelectMap_Width * TILE_WIDTH) - SCR_WIDTH + GRID_X + 16) + 0.000006;
	}
	if(GetKeyState(VK_LEFT) & 0x8000)
	{
		if(offset.x > 0)
			offset.x -= (CameraSpeed/(double)MapScale)*(double)100;
		if(offset.x < 0)
			offset.x = 0.000006;
	}
	if(GetKeyState(VK_Z) & 0x8000 && GetTickCount() - Z_Key_Time >= 400)
	{ 
		Z_Key_Time = GetTickCount();
		if(MapScale != 56)
		{
			MapScaleTemp = MapScale;
			MapScale = 56;
		}
		else if(MapScale == 56)
		{
			MapScale = MapScaleTemp;
		}
	}
	if((GetKeyState(VK_S) & 0x8000) && GameStep == READY)
	{
		GameStep = CREATE;
	}
	/*
	if((GetKeyState(VK_BACK) & 0x8000) && GameStep == READY)
	{
		g_Game.gotoPlay(GAME);
	}*/
}
void cGame::wHeelCheck()
{
	if(g_zDelta)
	{
		if(g_zDelta > 0)
		{
			if(MapScale<100)
			{
				MapScale += ScaleSpeed;
			}
			if(MapScale>100)
				MapScale = 100;
			g_zDelta = 0;

			if(MapScale%2 == 1)
				MapScale++;
		}
		else if(g_zDelta < 0)
		{
			if(MapScale>56 + ScaleSpeed)
			{
				MapScale -= ScaleSpeed;
				offset.x -=(CameraSpeed/(double)MapScale)*(double)100;
				offset.y -= (CameraSpeed/(double)MapScale)*(double)100;
			}
			if(MapScale<56)
				MapScale = 56;
			g_zDelta = 0;

			if(MapScale%2 == 1)
				MapScale++;
		}
	}
}
LRESULT cGame::MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch(iMessage)
	{
	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		if(Spell.State == 1)//스펠상태가 대기중일때
		{
			//Spell.State = 2;
			Spell.SpellBy_LightningStrike(passTime,m_Ey_Infantry,EIN,m_Ey_Archer,EAR,m_Ey_Cavalry,ECA,m_Ey_Priest,EPR,m_Ey_Spearman,ESP,m_My_Infantry,MIN,m_My_Archer,MAR,m_My_Cavalry,MCA,m_My_Priest,MPR,m_My_Spearman,MSP,x,y,offset.x,offset.y);
		}
		Game_b_Back.CheckDown(x,y);
		if(GameStep == READY)
		{
			if(x > 60 && x < 60 + 35 && y > 100 && y < 100 + 15)
			{
				m_SelectMenu = 1;
				if(m_ShowInv == false)
				{
					m_ShowInv   = true;
				}
				else if(m_ShowInv == true)
				{
					m_ShowInv   = false;
				}
			}

			if(m_ShowInv == true)
			{


				if(x > 260 && x < 260 + 35 && y > 130 && y < 130 + 15)
				{
					if(Buy_Infantry>0)
					{

						m_ShowInv = false;
						m_Grid_OnOff = true;
						//CreateUnit();
						m_SelectUnit = INFANTRY;
						GameStep = PLACE;
					}
					else
					{
						Message = "배치할 보병이 없습니다.";
					}
				}
				else if(x > 360 && x < 360 + 35 && y > 130 && y < 130 + 15)
				{
					if(Buy_Archer>0)
					{

						m_ShowInv = false;
						m_Grid_OnOff = true;
						//CreateUnit();
						m_SelectUnit = ARCHER;
						GameStep = PLACE;
					}
					else
					{
						Message = "배치할 궁수가 없습니다.";
					}
				}
				else if(x > 460 && x < 460 + 35 && y > 130 && y < 130 + 15)
				{
					if(Buy_Cavalry>0)
					{

						m_ShowInv = false;
						m_Grid_OnOff = true;
						//CreateUnit();
						m_SelectUnit = CAVALRY;
						GameStep = PLACE;
					}
					else
					{
						Message = "배치할 기병이 없습니다.";
					}
				}
				else if(x > 560 && x < 560 + 35 && y > 130 && y < 130 + 15)
				{
					if(Buy_Priest>0)
					{

						m_ShowInv = false;
						m_Grid_OnOff = true;
						//CreateUnit();
						m_SelectUnit = PRIEST;
						GameStep = PLACE;
					}
					else
					{
						Message = "배치할 사제가 없습니다.";
					}
				}
				else if(x > 660 && x < 660 + 35 && y > 130 && y < 130 + 15)
				{
					if(Buy_Spearman>0)
					{

						m_ShowInv = false;
						m_Grid_OnOff = true;
						//CreateUnit();
						m_SelectUnit = SPEARMAN;
						GameStep = PLACE;
					}
					else
					{
						Message = "배치할 창병이 없습니다.";
					}
				}

			}
		}

		else if(GameStep == PLACE)
		{
			if(MapScale == 100)
			{

				int TempY = y;
				int TempX = x;
				if(TempX < GRID_X || TempY < GRID_Y || TempX > GRID_X + (20 * TILE_WIDTH) || TempY > GRID_Y + (12 * TILE_HEIGHT))
				{
					TempX = 0;
					TempY = 0;
					Message = "그곳에는 놓을 수 없습니다.";
					GameStep = READY;
					m_ShowInv   = true;
					m_Grid_OnOff = false;
				}
				else
				{
					TempY = (y - GRID_Y) + offset.y;
					TempX = (x - GRID_X) + offset.x;
					if(TempY < 0)
					{
						TempY = 0;
						Message = "그곳에는 배치할 수 없습니다.";
						GameStep = READY;
						m_ShowInv   = true;
						m_Grid_OnOff = false;
					}
					if(TempX < 0)
					{
						TempX = 0;
						Message = "그곳에는 배치할 수 없습니다.";
						GameStep = READY;
						m_ShowInv   = true;
						m_Grid_OnOff = false;
					}


					if(GameStep == PLACE && TileMap[TempY/TILE_HEIGHT][TempX/TILE_WIDTH] == 0 && Enemy_TileMap[TempY/TILE_HEIGHT][TempX/TILE_WIDTH] == 0)
					{

						TileMap[TempY/TILE_HEIGHT][TempX/TILE_WIDTH] = m_SelectUnit;

						if(m_SelectUnit == INFANTRY)
							Buy_Infantry--;
						else if(m_SelectUnit == ARCHER)
							Buy_Archer--;
						else if(m_SelectUnit == CAVALRY)
							Buy_Cavalry--;
						else if(m_SelectUnit == PRIEST)
							Buy_Priest--;
						else if(m_SelectUnit == SPEARMAN)
							Buy_Spearman--;

						GameStep = READY;
						m_ShowInv   = true;
						m_Grid_OnOff = false;
					}
					else if(GameStep == PLACE)
					{
						Message = "이미 배치된 다른 유닛(혹은 적군)이 있습니다.";
						GameStep = READY;
						m_ShowInv   = true;
						m_Grid_OnOff = false;
					}
					/*for(int i=0; i<32; i++)
					{
					if(m_UnitList[i].Used == false)
					{
					m_UnitList[i].Used = true;
					m_UnitList[i].Type = m_SelectMenu;
					m_UnitList[i].X	   = x;
					m_UnitList[i].Y	   = y;
					GameStep = READY;
					break;
					}
					}*/
				}
			}
			else
			{
				Message = "배치는 시야가 100% 일때만 가능합니다.";
				GameStep = READY;
				m_ShowInv   = true;
				m_Grid_OnOff = false;
			}
		}
		break;
		
	case WM_LBUTTONUP:
		if(Game_b_Back.CheckUp(x,y) == true)
		{
			if(GameStep < CREATE)
			{
				g_Game.gotoPlay(LIMITMENU);
			}
			else if(GameStep == END)
			{
				g_Game.gotoPlay(MENU);
			}
		}
		break;
	case WM_MOUSEMOVE:

		x = LOWORD(lParam);
		y = HIWORD(lParam);
		break;
	case WM_KEYDOWN:

		switch(wParam)
		{
		case VK_F1:
			if(Buy_Spell_Lighting > 0)
			{
				Buy_Spell_Lighting--;
				Spell.StandBy_LightningStrike();
			}
			else
				Message = "사용할 마법이 없습니다.";
			break;
		case VK_NUM1:

			if(m_ShowInv == true)
			{
				if(Buy_Infantry>0)
				{

					m_ShowInv = false;
					m_Grid_OnOff = true;
					//CreateUnit();
					m_SelectUnit = INFANTRY;
					GameStep = PLACE;
				}
				else
				{
					Message = "배치할 보병이 없습니다.";
				}
			}
			break;
		case VK_NUM2:

			if(m_ShowInv == true)
			{
				if(Buy_Archer>0)
				{

					m_ShowInv = false;
					m_Grid_OnOff = true;
					//CreateUnit();
					m_SelectUnit = ARCHER;
					GameStep = PLACE;
				}
				else
				{
					Message = "배치할 궁수가 없습니다.";
				}
			}
			break;
		case VK_NUM3:

			if(m_ShowInv == true)
			{
				if(Buy_Cavalry>0)
				{

					m_ShowInv = false;
					m_Grid_OnOff = true;
					//CreateUnit();
					m_SelectUnit = CAVALRY;
					GameStep = PLACE;
				}
				else
				{
					Message = "배치할 기병이 없습니다.";
				}

			}
			break;
		case VK_NUM4:

			if(m_ShowInv == true)
			{
				if(Buy_Priest>0)
				{

					m_ShowInv = false;
					m_Grid_OnOff = true;
					//CreateUnit();
					m_SelectUnit = PRIEST;
					GameStep = PLACE;
				}
				else
				{
					Message = "배치할 사제가 없습니다.";
				}
			}
			break;
		case VK_NUM5:

			if(m_ShowInv == true)
			{
				if(Buy_Spearman>0)
				{

					m_ShowInv = false;
					m_Grid_OnOff = true;
					//CreateUnit();
					m_SelectUnit = SPEARMAN;
					GameStep = PLACE;
				}
				else
				{
					Message = "배치할 창병이 없습니다.";
				}
			}
			break;


	/*	case VK_RETURN:
			g_Game.setInnerState(DESTROY);
			break;*/

		}
		break;
	case WM_MOUSEHWHEEL:
		g_zDelta = ((short)HIWORD(wParam));
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd,iMessage,wParam,lParam));
}
