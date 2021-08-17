#pragma once
#include "UnitList.h"
class cArcher;
class cInfantry;
class cCavalry;
class cPriest;
class cSpearman;
class cArrow
{
	double X;
	double Y;
	double MoveSpeed;
	double MoveSpeedX;
	double MoveSpeedY;
	double TargetX;
	double TargetY;
	double LastTargetX;
	double LastTargetY;
	int	   Damage;
	bool Live;
	bool TargetLive;
	double MaxRange;
	int	   MaxGo;
	int	   MaxCount;

	cUnit *Target;
	cArcher *tArcher;
	int tMEA;
	cInfantry *tInfantry;
	int tMEI;
	cCavalry *tCavalry;
	int tMEC;
	cPriest *tPriest;
	int tMEP;
	cSpearman *tSpearman;
	int tMES;

public:
	cArrow(void);
	~cArrow(void);
	void AttackTo();
	double getPosX();
	double getPosY();
	bool getLive();
	void setLive(bool value);
	void CreateArrow(cUnit *Enemy, double ArcherX, double ArcherY, cArcher* eArcher,int MEA, cInfantry* eInfantry,int MEI,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES);
	void Update();
};

