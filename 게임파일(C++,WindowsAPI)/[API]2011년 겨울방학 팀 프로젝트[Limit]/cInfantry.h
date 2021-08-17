#pragma once

#include "UnitList.h"
#include "My_Define.h"
#include <Windows.h>
#include "cGdiImage.h"
#include "sceneManager.h"
#include "Struct.h"
#include "cIAngle.h"

extern cIAngle g_Angle;
class cArcher;
class cCavalry;
class cPriest;
class cSpearman;

extern double EndPosX;
extern double EndPosY;
class cInfantry :public cUnit
{
private:
	cSceneManager m_Attack;
public:
	bool Attack;
	cInfantry(void);
	~cInfantry(void);
	void Init();
	void SearchEnemy(cPriest* ePriest,int MEP,DWORD passTime);
	void SearchEnemy(cInfantry* eInfantry,int MEI,DWORD passTime);
	void SearchEnemy(cArcher* eArcher,int MEA,DWORD passTime);
	void SearchEnemy(cCavalry* eCavalry,int MEC,DWORD passTime);
	void SearchEnemy(cSpearman* eSpearman,int MES,DWORD passTime);


	void Update(DWORD passTime,cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,
		cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS,int MaxRoute,MoveRoute * MoveRoute);

	void MoveSpeedCheck(cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,int MaxRoute,MoveRoute * MoveRoute);
	void MoveCheck(cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS);
	void Move();
	void Reset();

	void AttackTo(cUnit &target, DWORD passTime);
	void CheckLive();
	void Render(d_OFFSET offset);
	void AngleCheck();
};
