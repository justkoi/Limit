#pragma once

#include "UnitList.h"
#include "My_Define.h"
#include <Windows.h>
class cSpell
{
public:
	int SpellRange;
	int SpellTime;
	int State;//0 없음 //1 사용대기중 (커서) // 2사용
	int SpellStandBy;
	cSpell(void);
	~cSpell(void);
	
	int HitTest_Circle(double ptx,double pty, double CircleCenterX,double CircleCenterY, double Radius);
	void StandBy_LightningStrike();
	void SpellBy_LightningStrike(DWORD passTime,cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,
		cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS,WORD x, WORD y,double offsetX,double offsetY);
};

