#ifndef __MY_EXTERN_H__
#define __MY_EXTERN_H__

extern HWND g_hWnd;

extern cGdiImage g_Image;
extern cStateManager g_Game;
extern cIAngle	g_Angle;
extern char strTemp[256];
extern WORD x;
extern WORD y;
extern int SelectStage;
extern int SelectLevel;
extern int Gold;
extern int DP;
extern char* Message;
//extern int TileMap[20][30];
extern fSound AttackSound01[MaxSound01];
extern fSound AttackSound02[MaxSound02];
/*
extern FMOD::System * systemS;
extern FMOD::Channel * channel;*/

//extern FMOD::System * systemS;
extern int Buy_Infantry;
extern int Limit_Infantry;

extern int Buy_Archer;
extern int Limit_Archer;

extern int Buy_Cavalry;
extern int Limit_Cavalry;

extern int Buy_Priest;
extern int Limit_Priest;

extern int Buy_Spearman;
extern int Limit_Spearman;


extern int Buy_Spell_Lighting;
extern int Limit_Spell_Lighting;
#endif