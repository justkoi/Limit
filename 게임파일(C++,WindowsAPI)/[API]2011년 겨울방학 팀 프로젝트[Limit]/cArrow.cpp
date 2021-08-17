#include "cArrow.h"
#include "MY_include.h"

cArrow::cArrow(void)
{
	X			= 0;
	Y			= 0;
	MoveSpeed	= 5/VN_FPS;
	MoveSpeedX	= 0;
	MoveSpeedY	= 0;
	TargetX		= 0;
	TargetY		= 0;
	Damage		= 19;
	Live		= false;
	Target		= NULL;
	LastTargetX = 0;
	LastTargetY = 0;
	MaxRange	= 4.5 * (TILE_WIDTH + 10);
	MaxGo		= 0;
	MaxCount	= 0;
}


cArrow::~cArrow(void)
{

}


void cArrow::AttackTo()
{

	int i;
	for(i=0;i<tMEI;i++)
	{
		if(	tInfantry[i].getState_Live() == LIVE &&
				X > tInfantry[i].getPosX() && X < tInfantry[i].getPosX() + TILE_WIDTH &&
				Y > tInfantry[i].getPosY() && Y < tInfantry[i].getPosY() + TILE_HEIGHT)
			{
					Live = false;
					tInfantry[i].setHp(tInfantry[i].getHp() - Damage);
				return;
			}
			
	}
	for(i=0;i<tMEA;i++)
	{
			if(	tArcher[i].getState_Live() == LIVE &&
				X > tArcher[i].getPosX() && X < tArcher[i].getPosX() + TILE_WIDTH &&
				Y > tArcher[i].getPosY() && Y < tArcher[i].getPosY() + TILE_HEIGHT)
			{
					Live = false;
					tArcher[i].setHp(tArcher[i].getHp() - Damage);
					return;
			}
			
	}
	for(i=0;i<tMEC;i++)
	{
			if(	tCavalry[i].getState_Live() == LIVE &&
				X > tCavalry[i].getPosX() && X < tCavalry[i].getPosX() + TILE_WIDTH &&
				Y > tCavalry[i].getPosY() && Y < tCavalry[i].getPosY() + TILE_HEIGHT)
			{
					Live = false;
					tCavalry[i].setHp(tCavalry[i].getHp() - Damage);
					return;
			}
			
	}
	for(i=0;i<tMEP;i++)
	{
			if(	tPriest[i].getState_Live() == LIVE &&
				X > tPriest[i].getPosX() && X < tPriest[i].getPosX() + TILE_WIDTH &&
				Y > tPriest[i].getPosY() && Y < tPriest[i].getPosY() + TILE_HEIGHT)
			{
					Live = false;
					tPriest[i].setHp(tPriest[i].getHp() - Damage);
					return;
			}
			
	}
	for(i=0;i<tMES;i++)
	{
			if(	tSpearman[i].getState_Live() == LIVE &&
				X > tSpearman[i].getPosX() && X < tSpearman[i].getPosX() + TILE_WIDTH &&
				Y > tSpearman[i].getPosY() && Y < tSpearman[i].getPosY() + TILE_HEIGHT)
			{
					Live = false;
					tSpearman[i].setHp(tSpearman[i].getHp() - Damage);
					return;
			}
			
	}
	
		



}
double cArrow::getPosX()
{
	return X;
}
double cArrow::getPosY()
{
	return Y;
}


bool cArrow::getLive()
{
	return Live;
}
void cArrow::setLive(bool value)
{
	Live = value;
}
void cArrow::CreateArrow(cUnit *Enemy, double ArcherX, double ArcherY,cArcher* eArcher,int MEA, cInfantry* eInfantry,int MEI,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES)
{
	if(Live == false)
	{
		for(int i=0; i<MaxSound02; i++)
		{
			if(AttackSound02[i].Played == false)
			{
				AttackSound02[i].PLAYSound();
				break;
			}
		}
		MaxGo		= 0;
		MaxCount	= 0;
		X = ArcherX + (TILE_WIDTH / 2);
		Y = ArcherY + (TILE_HEIGHT / 2);
		Live = true;
		Target = Enemy;
		tArcher = eArcher;
		tMEA = MEA;
		tInfantry = eInfantry;
		tMEI = MEI;
		tCavalry = eCavalry;
		tMEC = MEC;
		tPriest = ePriest;
		tMEP = MEP;
		tSpearman = eSpearman;
		tMES = MES;
		TargetLive = true;

		LastTargetX = Target->getPosX() + (TILE_WIDTH/2);
		LastTargetY = Target->getPosY() + (TILE_HEIGHT/2);
		double Width = ((LastTargetX) - X);
		double Height = ((LastTargetY) - Y);
		double Distance = sqrt((Width*Width) + (Height*Height));
		
		MoveSpeedX = Width / (Distance/MoveSpeed);
		MoveSpeedY = Height/ (Distance/MoveSpeed);

		MaxGo = (MaxRange/MoveSpeed);
		if(MaxGo <= 0)
			MaxGo = 1;
	}
}

void cArrow::Update()
{
	if(Live == true)
	{
		



			/*if(TargetLive == true)
			{
				
			}*/
		
			/*double Width = ((Target->getPosX()) - X);
			double Height = ((Target->getPosY()) - Y);
			double Distance = sqrt((Width*Width) + (Height*Height));
			MoveSpeedX = Width / (Distance/MoveSpeed);
			MoveSpeedY = Height/ (Distance/MoveSpeed);*/
			
			
		
			if(MaxCount < MaxGo)
			{
				MaxCount++;
				X += MoveSpeedX;
				Y += MoveSpeedY;
			
				AttackTo();
			}
			else if(MaxCount == MaxGo)
			{
				Live = false;
			}
	}
}