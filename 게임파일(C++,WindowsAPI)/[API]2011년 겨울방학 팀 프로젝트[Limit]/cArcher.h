#ifndef __CARCHER_H__
#define __CARCHER_H__

#pragma once
#include "UnitList.h"
#include <Windows.h>
#include "cArrow.h"

class cInfantry;
class cArrow;
class cCavalry;
class cSpearman;
class cArcher :public cUnit
{
	
public:
	cArrow* Arrow;

	cArcher(void);
	~cArcher(void);
	
	void Init();

	void SearchEnemy(cCavalry* eCavalry,int MEC,DWORD passTime,cArcher* eArcher,int MEA,cInfantry* eInfantry,int MEI,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES);
	void SearchEnemy(cInfantry* eInfantry,int MEI,DWORD passTime,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES);
	void SearchEnemy(cArcher* eArcher,int MEA,DWORD passTime,cInfantry* eInfantry,int MEI,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES);
	void SearchEnemy(cPriest* ePriest,int MEP,DWORD passTime,cArcher* eArcher,int MEA,cInfantry* eInfantry,int MEI,cCavalry* eCavalry,int MEC,cSpearman* eSpearman,int MES);
	void SearchEnemy(cSpearman* eSpearman,int MES,DWORD passTime,cArcher* eArcher,int MEA,cInfantry* eInfantry,int MEI,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP);


	void Update(DWORD passTime,cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,
		cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS);
	
	void MoveSpeedCheck(cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES);
	void MoveCheck(cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS);
	void Move();
	void Reset();


	void CheckLive();
	void AttackTo(cUnit &target, DWORD passTime);
	void ShootArrow();
};

#endif