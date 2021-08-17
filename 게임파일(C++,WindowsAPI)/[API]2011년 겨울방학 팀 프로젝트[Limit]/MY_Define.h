#ifndef __MY_DEFINE_H__
#define __MY_DEFINE_H__


//수학

#define ROOT_2 1.41421356
#define Sin45 0.70710678
#define SCR_WIDTH 1200
#define SCR_HEIGHT 750

#define GRID_X 200
#define GRID_Y 100
typedef struct _d_offset
{
	double x;
	double y;
}d_OFFSET;

//GameResult
#define NONE	0
#define VICTORY 1
#define DEFEAT	2
#define DRAW	3


#define Stage1_Map_Width  30
#define Stage1_Map_Height  20
//유닛
#define INFANTRY	1
#define ARCHER		2
#define	CAVALRY		3
#define	PRIEST		4
#define SPEARMAN	5
//가상 프레임 상수

#define VN_FPS 2

//m_State
#define LOGO 1
#define MENU 2
#define GAME 3
#define LEVELMENU 4
#define STAGEMENU 5
#define LIMITMENU 6



#define INIT 1
#define LOOP 2
#define DESTROY 3
#define GOTOPLAY 4

//효과음 1~5]
#define MaxSound01 5
#define MaxSound02 5
//State_Move
#define NONE	0
#define WALK	1
//State_Attack
#define NONE	0
#define FIGHT	1
//State_Live
#define NONE	0
#define LIVE	1
#define DING	2
#define	DEAD	3
//GameStep
#define READY	0
#define PLACE	1
#define CREATE	2
#define ACTION	3
#define END		4

//SelectLevel //선택한 난이도
#define EASY	1
#define NORMAL	2
#define HARD	3

//SelectStage
#define MAX_STAGE	10

//SelectMenu

#define TILE_WIDTH  50
#define TILE_HEIGHT 50
enum Check_Value{
	Check_None = 0,
	Check_Exc  = 1,
	Check_Good = 2,
	Check_Bad  = 3,
};

//비용정리




#define VK_NUM1 0x31
#define VK_NUM2 0x32
#define VK_NUM3 0x33
#define VK_NUM4 0x34
#define VK_NUM5 0x35
#define VK_NUM6 0x36
#define VK_NUM7 0x37
#define VK_NUM8 0x38
#define VK_NUM9 0x39
#define VK_NUM0 0x30
#define VK_A	0x41
#define VK_B	0x42
#define VK_C	0x43
#define VK_D	0x44
#define VK_E	0x45
#define VK_F	0x46
#define VK_G	0x47
#define VK_H	0x48
#define VK_I	0x49
#define VK_J	0x4A
#define VK_K	0x4B
#define VK_L	0x4C
#define VK_M	0x4D
#define VK_N	0x4E
#define VK_O	0x4F
#define VK_P	0x50
#define VK_Q	0x51
#define VK_R	0x52
#define VK_S	0x53
#define VK_T	0x54
#define VK_U	0x55
#define VK_V	0x56
#define VK_W	0x57
#define VK_X	0x58
#define VK_Y	0x59
#define VK_Z	0x5A


#endif