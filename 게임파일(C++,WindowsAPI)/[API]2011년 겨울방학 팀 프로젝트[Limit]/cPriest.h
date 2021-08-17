#pragma once

#include "UnitList.h"
#include "My_Define.h"
#include <Windows.h>
#include "cGdiImage.h"
#include "sceneManager.h"

class cArcher;
class cCavalry;
class cInfantry;
class cSpearman;
class cPriest :public cUnit
{
	cUnit* HTarget;
	bool Healing;
	cSceneManager m_Heal;
	int HealSpeed;
	DWORD lastHealTime;
	bool HealAble;
	int HealRange;
public:
	cPriest(void);
	~cPriest(void);
	void Init();
	
	int			getHealSpeed();
	DWORD		getlastHealTime();
	bool		getHealAble();
	int			getHealRange();

	void		setHealSpeed(int value);
	void		setlastHealTime(DWORD value);
	void		setHealAble(bool value);
	void		setHealRange(int value);


	void SearchEnemy(cPriest* ePriest,int MEP,DWORD passTime);
	void SearchEnemy(cInfantry* eInfantry,int MEI,DWORD passTime);
	void SearchEnemy(cArcher* eArcher,int MEA,DWORD passTime);
	void SearchEnemy(cCavalry* eCavalry,int MEC,DWORD passTime);
	void SearchEnemy(cSpearman* eSpearman,int MES,DWORD passTime);


	void SearchAlly(cInfantry* eInfantry,int MEI,DWORD passTime);
	void SearchAlly(cArcher* eArcher,int MEA,DWORD passTime);
	void SearchAlly(cCavalry* eCavalry,int MEC,DWORD passTime);
	void SearchAlly(cSpearman* eSpearman,int MES,DWORD passTime);


	void Update(DWORD passTime,cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,
		cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS);
	void MoveSpeedCheck(cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES);
	void MoveCheck(cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS);
	void Move();
	void Reset();
	
	void CheckLive();
	void Heal(cUnit &target , DWORD passTime);
	void Render(d_OFFSET offset);
	
};
