
#pragma once

#include "UnitList.h"
#include "My_Define.h"
#include <Windows.h>

class cArcher;
class cInfantry;
class cPriest;
class cSpearman;
class cCavalry :public cUnit
{
public:
	cCavalry(void);
	~cCavalry(void);
	void Init();
	
	void SearchEnemy(cPriest* ePriest,int MEP,DWORD passTime);
	void SearchEnemy(cInfantry* eInfantry,int MEI,DWORD passTime);
	void SearchEnemy(cArcher* eArcher,int MEA,DWORD passTime);
	void SearchEnemy(cCavalry* eCavalry,int MEC,DWORD passTime);
	void SearchEnemy(cSpearman* eSpearman,int MES,DWORD passTime);

	
	void Update(DWORD passTime,cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS);
	
	void MoveSpeedCheck(cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES);
	void MoveCheck(cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS);
	void Move();
	void Reset();
	
	void CheckLive();
	
};
