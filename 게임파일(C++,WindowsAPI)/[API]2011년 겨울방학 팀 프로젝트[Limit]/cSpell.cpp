#include "cSpell.h"


cSpell::cSpell(void)
{
	State = 0;
	SpellStandBy = 0;
}


cSpell::~cSpell(void)
{
}

int cSpell::HitTest_Circle(double ptx, double pty, double CircleCenterX,double CircleCenterY, double Radius) // 점의 x, y좌표 원의 중심x,y 좌표, 원의 반지름

{

        double TempX = abs(CircleCenterX  - ptx );

        double TempY = abs(CircleCenterY - pty );
 
        double distance =  sqrt((TempX*TempX )+ (TempY * TempY));

 

        if(distance <= Radius)

        {

                return TRUE;

        }

        else

                return FALSE;

}



void cSpell::StandBy_LightningStrike()
{
	State = 1;
	SpellStandBy = 1;
	SpellRange = 50;
}
void cSpell::SpellBy_LightningStrike(DWORD passTime,cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,
		cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS,WORD x,WORD y,double offsetX,double offsetY)
{
	if(State == 1)
	{
		State = 0;
		for(int i=0; i< MEI; i++)
		{
			if(HitTest_Circle(eInfantry[i].getPosX() + (TILE_WIDTH/2),eInfantry[i].getPosY() + (TILE_HEIGHT/2),x + offsetX,y + offsetY,SpellRange) == TRUE)
			{
				eInfantry[i].setHp(eInfantry[i].getHp() - 30);
			}
		}
	}
}