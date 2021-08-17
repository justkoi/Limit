#include "cInfantry.h"

 
cInfantry::cInfantry(void)
{
	setPosX(0);
	setPosY(0);
	setMaxHp(80);
	setHp(getMaxHp());
	setMaxMp(100);
	setMp(getMaxMp());
	setUnitRange(2000);
	setRange(TILE_WIDTH + 10);
	setMoveSpeed(1.3000/VN_FPS);
	setDamage(8);
	setAttackSpeed(1000);
	setUnitType(1);
	setDefence(0);
	setState_Attack(FIGHT);
	setState_Live(LIVE);
	setState_Move(WALK);
	setAttackAble(true);
	setlastAttackTime(0);
	setHitTest(false);
	setMoveTargeting(0);
	setMoveTargeted(false);
	setNowRoute(0);
	setAngle(0);
	Attack = false;

	m_Attack.setDC(g_Graphics.getGraphicsDC());
	m_Attack.setImageNum(3);
	m_Attack.setImage(0,"./Image/Unit/My_Infantry_Attack01.bmp");
	m_Attack.setImage(1,"./Image/Unit/My_Infantry_Attack02.bmp");
	m_Attack.setImage(2,"./Image/Unit/My_Infantry_Attack03.bmp");

	m_Attack.addScene("Attack");
	m_Attack.setMaxFrame(3);

	m_Attack.setMaxElementOfFrame(200);
	m_Attack.addElementOfFrame(0,0,0,0,0,50,50);

	m_Attack.setMaxElementOfFrame(200);
	m_Attack.addElementOfFrame(1,0,0,0,0,50,50);

	m_Attack.setMaxElementOfFrame(200);
	m_Attack.addElementOfFrame(2,0,0,0,0,50,50);

	m_Attack.setScene("Attack");
	
}


cInfantry::~cInfantry(void)
{

}

void cInfantry::Init()
{
	setPosX(0);
	setPosY(0);
	setMaxHp(100);
	setHp(getMaxHp());
	setMaxMp(100);
	setMp(getMaxMp());
	setUnitRange(20);
	setRange(TILE_WIDTH + 10);
	setMoveSpeed(1.3000/VN_FPS);
	setDamage(8);
	setAttackSpeed(1000);
	setUnitType(1);
	setDefence(0);
	setState_Attack(FIGHT);
	setState_Live(LIVE);
	setState_Move(WALK);
	setAttackAble(true);
	setlastAttackTime(0);
	setHitTest(false);
	setMoveTargeting(0);
	setMoveTargeted(false);
	setNowRoute(0);
	setAngle(0);
}


void cInfantry::SearchEnemy(cCavalry* eCavalry,int MEC,DWORD passTime)
{
	int i = 0;
	if(getAttackAble() == true)
	{
		for(i=0;i<MEC;i++)
		{
			if(eCavalry[i].getState_Live() == LIVE //getState_Move() == WALK 
				&& eCavalry[i].getPosX() >getPosX() - getRange()  && eCavalry[i].getPosX()  < getPosX() + getRange()
				&& eCavalry[i].getPosY() >getPosY() - getRange()  && eCavalry[i].getPosY()  < getPosY() + getRange() 
				)
			{
				AttackTo(eCavalry[i], passTime);
				return;
			}
		}
		if(i == MEC && getState_Move() == NONE)
		{
			setState_Move(WALK);
		}

	}
}
void cInfantry::SearchEnemy(cInfantry* eInfantry,int MEI,DWORD passTime)
{
	int i = 0;
	if(getAttackAble() == true)
	{
		for(i=0;i<MEI;i++)
		{
			if(eInfantry[i].getState_Live() == LIVE //getState_Move() == WALK 
				&& eInfantry[i].getPosX() >getPosX() - getRange()  && eInfantry[i].getPosX()  < getPosX() + getRange()
				&& eInfantry[i].getPosY() >getPosY() - getRange()  && eInfantry[i].getPosY()  < getPosY() + getRange() 
				)
			{
				AttackTo(eInfantry[i], passTime);
				return;
			}
		}
		if(i == MEI && getState_Move() == NONE)
		{
			setState_Move(WALK);
		}

	}
}

void cInfantry::SearchEnemy(cArcher* eArcher,int MEA,DWORD passTime)
{
	int i = 0;
	if(getAttackAble() == true)
	{
		for(i=0;i<MEA;i++)
		{
			if(eArcher[i].getState_Live() == LIVE //getState_Move() == WALK 
				&& eArcher[i].getPosX() >getPosX() - getRange()  && eArcher[i].getPosX()  < getPosX() + getRange()
				&& eArcher[i].getPosY() >getPosY() - getRange()  && eArcher[i].getPosY()  < getPosY() + getRange() 
				)
			{
				AttackTo(eArcher[i], passTime);
				return;
			}
		}
		if(i == MEA && getState_Move() == NONE)
		{
			setState_Move(WALK);
		}

	}
}


void cInfantry::SearchEnemy(cPriest* ePriest,int MEP,DWORD passTime)
{
	int i = 0;
	if(getAttackAble() == true)
	{
		for(i=0;i<MEP;i++)
		{

			if(ePriest[i].getState_Live() == LIVE //getState_Move() == WALK 
				&& ePriest[i].getPosX() >getPosX() - getRange()  && ePriest[i].getPosX()  < getPosX() + getRange()
				&& ePriest[i].getPosY() >getPosY() - getRange()  && ePriest[i].getPosY()  < getPosY() + getRange() 
				)
			{
				AttackTo(ePriest[i], passTime);
				return;
			}
		}
		if(i == MEP && getState_Move() == NONE)
		{
			setState_Move(WALK);
		}

	}
}


void cInfantry::SearchEnemy(cSpearman* eSpearman,int MES,DWORD passTime)
{
	int i = 0;
	if(getAttackAble() == true)
	{
		for(i=0;i<MES;i++)
		{

			if(eSpearman[i].getState_Live() == LIVE //getState_Move() == WALK 
				&& eSpearman[i].getPosX() >getPosX() - getRange()  && eSpearman[i].getPosX()  < getPosX() + getRange()
				&& eSpearman[i].getPosY() >getPosY() - getRange()  && eSpearman[i].getPosY()  < getPosY() + getRange() 
				)
			{
				AttackTo(eSpearman[i], passTime);
				return;
			}
		}
		if(i == MES && getState_Move() == NONE)
		{
			setState_Move(WALK);
		}

	}
}


void cInfantry::Update(DWORD passTime,cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,
	cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS,int MaxRoute,MoveRoute * MoveRoute
	)
{

	if(getState_Live() == LIVE)
	{
		if(getAttackAble() == false && passTime - getlastAttackTime() >= getAttackSpeed())
			setAttackAble(true);

		//setAttackAble(true);
		SearchEnemy(eCavalry,MEC,passTime);
		SearchEnemy(eInfantry,MEI,passTime);
		SearchEnemy(eSpearman,MES,passTime);
		SearchEnemy(eArcher,MEA,passTime);
		SearchEnemy(ePriest,MEP,passTime);
		//if(getState_Live() == LIVE)
		//	{
		MoveSpeedCheck(eInfantry,MEI,eArcher,MEA,eCavalry,MEC,ePriest,MEP,eSpearman,MES,MaxRoute,MoveRoute);
		MoveCheck(mInfantry,MMI,mArcher,MMA,mCavalry,MMC,mPriest,MMP,mSpearman,MMS);
		//	}
	}
}

void cInfantry::MoveSpeedCheck(cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,int MaxRoute,MoveRoute * MoveRoute)
{
	if(getMoveTargeted() == false)
	{
		bool Searched = false;
		int TempPosX = EndPosX;
		int TempPosY = EndPosY;

		if(getState_Live() == LIVE && getState_Move() == WALK)
		{

			
			//TempPos에 목적지를 넣습니다.
			
			bool TargetBreak = false;
			int TargetingCount = 1;
			int i = 0;
			while(TargetBreak == false)
			{

				//적군 보병을 검사합니다.
				for(i=0;i<MEI;i++)
				{
					if(eInfantry[i].getState_Live() == LIVE//getState_Move() == WALK //적군보병이  유닛시야 안에 있을경우
						&& eInfantry[i].getPosX() >getPosX() - getUnitRange()  && eInfantry[i].getPosX()  < getPosX() + getUnitRange()
						&& eInfantry[i].getPosY() >getPosY() - getUnitRange()  && eInfantry[i].getPosY()  < getPosY() + getUnitRange() 
						)
					{
						//적군 보병의 타겟팅이 0일 경우
						if(eInfantry[i].getMoveTargeting() < TargetingCount)
						{
							eInfantry[i].setMoveTargeting(eInfantry[i].getMoveTargeting() + 1);//적군의 타겟팅을 1 올리고
							TempPosX = eInfantry[i].getPosX();								   //적의 위치를 목적지로 정합니다.
							TempPosY = eInfantry[i].getPosY();
							TargetBreak = true;
							setMoveTargeted(true);
							MoveTarget = &eInfantry[i];
							Searched = true;
							break;
						}
					}
				}
				//만약 적군보병의 타겟팅이 전부 되어있을경우
				//같은방법으로 궁수를 검사합니다.
				if(i == MEI)
				{
					for(i=0;i<MEA;i++)
					{
						if(eArcher[i].getState_Live() == LIVE//getState_Move() == WALK 
							&& eArcher[i].getPosX() >getPosX() - getUnitRange()  && eArcher[i].getPosX()  < getPosX() + getUnitRange()
							&& eArcher[i].getPosY() >getPosY() - getUnitRange()  && eArcher[i].getPosY()  < getPosY() + getUnitRange() 
							)
						{
							if(eArcher[i].getMoveTargeting() < TargetingCount)
							{
								eArcher[i].setMoveTargeting(eArcher[i].getMoveTargeting() + 1);
								TempPosX = eArcher[i].getPosX();
								TempPosY = eArcher[i].getPosY();
								TargetBreak = true;
								setMoveTargeted(true);
								MoveTarget = &eArcher[i];
								Searched = true;
								break;
							}
						}
					}
					if(i == MEA)
					{
						for(i=0;i<MEC;i++)
						{
							if(eCavalry[i].getState_Live() == LIVE//getState_Move() == WALK 
								&& eCavalry[i].getPosX() >getPosX() - getUnitRange()  && eCavalry[i].getPosX()  < getPosX() + getUnitRange()
								&& eCavalry[i].getPosY() >getPosY() - getUnitRange()  && eCavalry[i].getPosY()  < getPosY() + getUnitRange() 
								)
							{
								if(eCavalry[i].getMoveTargeting() < TargetingCount)
								{
									eCavalry[i].setMoveTargeting(eCavalry[i].getMoveTargeting() + 1);
									TempPosX = eCavalry[i].getPosX();
									TempPosY = eCavalry[i].getPosY();
									TargetBreak = true;
									setMoveTargeted(true);
									MoveTarget = &eCavalry[i];
									Searched = true;
									break;
								}
							}
						}
						if(i == MEC)
						{
							for(i=0;i<MEP;i++)
							{
								if(ePriest[i].getState_Live() == LIVE//getState_Move() == WALK 
									&& ePriest[i].getPosX() >getPosX() - getUnitRange()  && ePriest[i].getPosX()  < getPosX() + getUnitRange()
									&& ePriest[i].getPosY() >getPosY() - getUnitRange()  && ePriest[i].getPosY()  < getPosY() + getUnitRange() 
									)
								{
									if(ePriest[i].getMoveTargeting() < TargetingCount)
									{
										ePriest[i].setMoveTargeting(ePriest[i].getMoveTargeting() + 1);
										TempPosX = ePriest[i].getPosX();
										TempPosY = ePriest[i].getPosY();
										TargetBreak = true;
										setMoveTargeted(true);
										MoveTarget = &ePriest[i];
										Searched = true;
										break;
									}
								}
							}
							if(i==MEP)
							{
								for(i=0;i<MES;i++)
								{
									if(eSpearman[i].getState_Live() == LIVE//getState_Move() == WALK 
										&& eSpearman[i].getPosX() >getPosX() - getUnitRange()  && eSpearman[i].getPosX()  < getPosX() + getUnitRange()
										&& eSpearman[i].getPosY() >getPosY() - getUnitRange()  && eSpearman[i].getPosY()  < getPosY() + getUnitRange() 
										)
									{
										if(eSpearman[i].getMoveTargeting() < TargetingCount)
										{
											eSpearman[i].setMoveTargeting(eSpearman[i].getMoveTargeting() + 1);
											TempPosX = eSpearman[i].getPosX();
											TempPosY = eSpearman[i].getPosY();
											TargetBreak = true;
											setMoveTargeted(true);
											MoveTarget = &eSpearman[i];
											Searched = true;
											break;
										}
									}
								}
							}
						}
					}
				}
				TargetingCount++;
				if(TargetingCount>30)
					break;
			}


			setLastEndPosX( (TempPosX + (TILE_WIDTH/2)));
			setLastEndPosY( (TempPosY + (TILE_HEIGHT/2)));
			setWidth ( ((getLastEndPosX()) - getPosX()) ) ;
			setHeight ( ((getLastEndPosY()) - getPosY()) ) ;
			setDistance(sqrt((getWidth()*getWidth()) + (getHeight()*getHeight())));

			setMoveSpeedX ( getWidth() / (getDistance()/getMoveSpeed()) );
			setMoveSpeedY ( getHeight()/ (getDistance()/getMoveSpeed()) );

		}

		if(Searched == false)
		{

			if(getNowRoute() < MaxRoute)
			{
				if(getPosX() >= MoveRoute[getNowRoute()].X && getPosX() <= MoveRoute[getNowRoute()].X + MoveRoute[getNowRoute()].Range_Width &&
				   getPosY() >= MoveRoute[getNowRoute()].Y && getPosY() <= MoveRoute[getNowRoute()].Y + MoveRoute[getNowRoute()].Range_Height )
					{
						setNowRoute( getNowRoute() + 1 );
					}
			}
			if(getNowRoute() == MaxRoute)
			{
				setMoveSpeedX (0);
				setMoveSpeedY (0);
			}
			if(getNowRoute() < MaxRoute)
			{
				

				TempPosX = MoveRoute[getNowRoute()].X + (MoveRoute[getNowRoute()].Range_Width/2);
				TempPosY = MoveRoute[getNowRoute()].Y + (MoveRoute[getNowRoute()].Range_Height/2);

				setLastEndPosX(TempPosX);
				setLastEndPosY(TempPosY);
				setWidth ( ((getLastEndPosX()) - getPosX()) ) ;
				setHeight ( ((getLastEndPosY()) - getPosY()) ) ;
				setDistance(sqrt((getWidth()*getWidth()) + (getHeight()*getHeight())));

				setMoveSpeedX ( getWidth() / (getDistance()/getMoveSpeed()) );
				setMoveSpeedY ( getHeight()/ (getDistance()/getMoveSpeed()) );
			}
		}
	}
	else
	{
		if(MoveTarget->getState_Live() != DEAD)
		{
			int TempPosX = MoveTarget->getPosX();
			int TempPosY = MoveTarget->getPosY();
			setLastEndPosX( (TempPosX + (TILE_WIDTH/2)));
			setLastEndPosY( (TempPosY + (TILE_HEIGHT/2)));
			setWidth ( ((getLastEndPosX()) - getPosX()) );
			setHeight ( ((getLastEndPosY()) - getPosY()) );
			setDistance(sqrt((getWidth()*getWidth()) + (getHeight()*getHeight())));

			setMoveSpeedX ( getWidth() / (getDistance()/getMoveSpeed()) );
			setMoveSpeedY ( getHeight()/ (getDistance()/getMoveSpeed()) );
		}
		else
		{
			MoveTarget = NULL;
			setMoveTargeted(false);
		}

	}
}
void cInfantry::MoveCheck(cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS)
{



	if(getState_Live() == LIVE && getState_Move() == WALK)
	{
		int i=0;

		int count = 0;
		bool fBreak = false;
		double TempMoveSpeedX = 0;
		double TempMoveSpeedY = 0;
		int CprDer = 1; // ComparisonDerection 비교방향
		//1	오른쪽
		//2 왼쪽
		//3 아래
		//4 위

		if(abs(getMoveSpeedX()) > abs(getMoveSpeedY()))
		{
			if(getMoveSpeedX() > 0.0000)	//오른쪽
			{
				CprDer = 1;
			}
			else if(getMoveSpeedX() < 0.0000)		//왼쪽
			{
				CprDer = 2;
			}
		}
		else if(abs(getMoveSpeedX()) < abs(getMoveSpeedY()))
		{
			if(getMoveSpeedY() > 0.0000)	//아래쪽
			{
				CprDer = 3;
			}
			else if(getMoveSpeedY() < 0.0000)	//위쪽
			{
				CprDer = 4;
			}
		}
		
		

		//오른쪽이동중일때
		if(CprDer == 1)
		
		{
			for(i=0; i<MMI; i++)
			{
				if(mInfantry[i].getPosX() == getPosX() && mInfantry[i].getPosY() == getPosY())//검사할 아군이 자신일경우 다음아군검사
					continue;

				count = 0;
				while(count < 9)
				{
					if(mInfantry[i].getState_Live() == LIVE && //나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면 // 방향을 튕겨 검사

						(
						mInfantry[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mInfantry[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
						mInfantry[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mInfantry[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
						)

						)
					{

						//setHitTest(1);
						//break;
						if(count == 0)
							{
								TempMoveSpeedX = getMoveSpeedX();
								TempMoveSpeedY = getMoveSpeedY();
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 1)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	);
								count++;
							}
							else if(count == 2)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed());
								count++;
							}
							else if(count == 3)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	 * -1);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	);
								count++;
							}
							else if(count == 4)
							{
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 5)
							{
								setMoveSpeedX(	(	(Sin45 * getMoveSpeed())		) * -1);
								setMoveSpeedY(	(	(Sin45 * getMoveSpeed())		) * -1);
								count++;
							}
							else if(count == 6)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed() * -1);
								count++;
							}
							else if(count == 7)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	 * -1);
								count++;
							}
							else if(count == 8)
							{
								setMoveSpeedX(TempMoveSpeedX);
								setMoveSpeedY(TempMoveSpeedY);
								setHitTest(1);
								count++;
								fBreak = true;
								break;
							}

					}
					else
						break;
				}

				if(fBreak == true)
				{
					fBreak = false;
					count = 0;
					break;
				}

			}
			if(i == MMI) //아군이 존재하지 않는다면 이동함
				setHitTest(0);
			if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
			{
				for(i=0; i<MMA; i++)
				{

					//while(count < 9)
					//{
						if(mArcher[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
							mArcher[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mArcher[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
							mArcher[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mArcher[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
							)
						{
							/*if(count == 0)
							{
								TempMoveSpeedX = getMoveSpeedX();
								TempMoveSpeedY = getMoveSpeedY();
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 1)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	);
								count++;
							}
							else if(count == 2)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed());
								count++;
							}
							else if(count == 3)
							{
								setMoveSpeedX((	(Sin45 * getMoveSpeed())	) * -1);
								setMoveSpeedY((	(Sin45 * getMoveSpeed())	)		);
								count++;
							}
							else if(count == 4)
							{
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 5)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	 * -1);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	 * -1);
								count++;
							}
							else if(count == 6)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed() * -1);
								count++;
							}
							else if(count == 7)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	 * -1);
								count++;
							}
							else if(count == 8)
							{
								setMoveSpeedX(TempMoveSpeedX);
								setMoveSpeedY(TempMoveSpeedY);
								setHitTest(1);
								count++;
								fBreak = true;
								break;
							}
						}
						else
							break;*/
							setHitTest(1);
								break;

					}/*
					if(fBreak == true)
					{
						fBreak = false;
						break;
					}*/

			//	}
				}
				if(i == MMA)
					setHitTest(0);
				if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
				{
					for(i=0; i<MMC; i++)
					{
						if(mCavalry[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면


							mCavalry[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mCavalry[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
							mCavalry[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mCavalry[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
							
							
							)
						{
							setHitTest(1);
							break;
						}

					}
					if(i == MMC)
						setHitTest(0);
					if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
					{
						for(i=0; i<MMP; i++)
						{
							if(mPriest[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
								mPriest[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mPriest[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
								mPriest[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mPriest[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
								)
							{
								setHitTest(1);
								break;
							}

						}
						if(i == MMP)
							setHitTest(0);
						if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
						{
							for(i=0; i<MMS; i++)
							{
								if(mSpearman[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
									mSpearman[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mSpearman[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
									mSpearman[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mSpearman[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
									)
								{
									setHitTest(1);
									break;
								}

							}
							if(i == MMS)
								setHitTest(0);
						}
					}
				}

			}

		}
		//왼쪾이동중일때
		else if(CprDer == 2)
		{
			for(i=0; i<MMI; i++)
			{
				if(mInfantry[i].getPosX() == getPosX() && mInfantry[i].getPosY() == getPosY())//검사할 아군이 자신일경우 다음아군검사
					continue;


				while(count < 9)
				{
					if(mInfantry[i].getState_Live() == LIVE && //나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면 // 방향을 튕겨 검사
						
						mInfantry[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mInfantry[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
						mInfantry[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mInfantry[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
						
						
						)
					{

							if(count == 0)
							{
								TempMoveSpeedX = getMoveSpeedX();
								TempMoveSpeedY = getMoveSpeedY();
								setMoveSpeedX(getMoveSpeed() * -1);
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 1)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	* -1);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	 * -1);
								count++;
							}
							else if(count == 2)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed() * -1);
								count++;
							}
							else if(count == 3)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	 * -1);
								count++;
							}
							else if(count == 4)
							{
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 5)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	 );
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	);
								count++;
							}
							else if(count == 6)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed());
								count++;
							}
							else if(count == 7)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	 * -1);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	);
								count++;
							}
							else if(count == 8)
							{
								setMoveSpeedX(TempMoveSpeedX);
								setMoveSpeedY(TempMoveSpeedY);
								setHitTest(1);
								count++;
								fBreak = true;
								break;
							}

					}
					else
						break;
				}

				if(fBreak == true)
				{
					fBreak = false;
					count = 0;
					break;
				}

			}
			if(i == MMI) //아군이 존재하지 않는다면 이동함
				setHitTest(0);
			if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
			{
				for(i=0; i<MMA; i++)
				{

					while(count < 9)
					{
						if(mArcher[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
							mArcher[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mArcher[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
							mArcher[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mArcher[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
							)
						{
							if(count == 0)
							{
								TempMoveSpeedX = getMoveSpeedX();
								TempMoveSpeedY = getMoveSpeedY();
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 1)
							{
								setMoveSpeedX(getMoveSpeed()/2);
								setMoveSpeedY(getMoveSpeed()/2);
								count++;
							}
							else if(count == 2)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed());
								count++;
							}
							else if(count == 3)
							{
								setMoveSpeedX((getMoveSpeed()/2) * -1);
								setMoveSpeedY(getMoveSpeed()/2);
								count++;
							}
							else if(count == 4)
							{
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 5)
							{
								setMoveSpeedX((getMoveSpeed()/2) * -1);
								setMoveSpeedY((getMoveSpeed()/2) * -1);
								count++;
							}
							else if(count == 6)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed() * -1);
								count++;
							}
							else if(count == 7)
							{
								setMoveSpeedX(getMoveSpeed()/2);
								setMoveSpeedY((getMoveSpeed()/2) * -1);
								count++;
							}
							else if(count == 8)
							{
								setMoveSpeedX(TempMoveSpeedX);
								setMoveSpeedY(TempMoveSpeedY);
								setHitTest(1);
								count++;
								fBreak = true;
								break;
							}
						}
						else
							break;

					}
					if(fBreak == true)
					{
						fBreak = false;
						break;
					}

				}
				if(i == MMA)
					setHitTest(0);
				if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
				{
					for(i=0; i<MMC; i++)
					{
						if(mCavalry[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
							mCavalry[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mCavalry[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
							mCavalry[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mCavalry[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
							)
						{
							setHitTest(1);
							break;
						}

					}
					if(i == MMC)
						setHitTest(0);
					if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
					{
						for(i=0; i<MMP; i++)
						{
							if(mPriest[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
								mPriest[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mPriest[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
								mPriest[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mPriest[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
								)
							{
								setHitTest(1);
								break;
							}

						}
						if(i == MMP)
							setHitTest(0);
						if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
						{
							for(i=0; i<MMS; i++)
							{
								if(mSpearman[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
									mSpearman[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mSpearman[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
									mSpearman[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mSpearman[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
									)
								{
									setHitTest(1);
									break;
								}

							}
							if(i == MMS)
								setHitTest(0);
						}
					}
				}

			}


		}
		else if(CprDer == 3)//아래쪽이동중일때
		
		{
			for(i=0; i<MMI; i++)
			{
				if(mInfantry[i].getPosX() == getPosX() && mInfantry[i].getPosY() == getPosY())//검사할 아군이 자신일경우 다음아군검사
					continue;

				count = 0;
				while(count < 9)
				{
					if(mInfantry[i].getState_Live() == LIVE && //나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면 // 방향을 튕겨 검사
						
						
						mInfantry[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mInfantry[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
						mInfantry[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mInfantry[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
						
						
						)
					{

						//setHitTest(1);
						//break;
						if(count == 0)
							{
								TempMoveSpeedX = getMoveSpeedX();
								TempMoveSpeedY = getMoveSpeedY();
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed());
								count++;
							}
							else if(count == 1)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed()) * -1	);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	);
								count++;
							}
							else if(count == 2)
							{
								setMoveSpeedX(getMoveSpeed() * -1);
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 3)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed()) * -1 );
								setMoveSpeedY(	(Sin45 * getMoveSpeed()) * -1 );
								count++;
							}
							else if(count == 4)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed() * -1);
								count++;
							}
							else if(count == 5)
							{
								setMoveSpeedX(	(	(Sin45 * getMoveSpeed())		));
								setMoveSpeedY(	(	(Sin45 * getMoveSpeed())		) * -1);
								count++;
							}
							else if(count == 6)
							{
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 7)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed()) );
								setMoveSpeedY(	(Sin45 * getMoveSpeed()) );
								count++;
							}
							else if(count == 8)
							{
								setMoveSpeedX(TempMoveSpeedX);
								setMoveSpeedY(TempMoveSpeedY);
								setHitTest(1);
								count++;
								fBreak = true;
								break;
							}

					}
					else
						break;
				}

				if(fBreak == true)
				{
					fBreak = false;
					count = 0;
					break;
				}

			}
			if(i == MMI) //아군이 존재하지 않는다면 이동함
				setHitTest(0);
			if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
			{
				for(i=0; i<MMA; i++)
				{

					//while(count < 9)
					//{
						if(mArcher[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
							mArcher[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mArcher[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
							mArcher[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mArcher[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
							)
						{
							/*if(count == 0)
							{
								TempMoveSpeedX = getMoveSpeedX();
								TempMoveSpeedY = getMoveSpeedY();
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 1)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	);
								count++;
							}
							else if(count == 2)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed());
								count++;
							}
							else if(count == 3)
							{
								setMoveSpeedX((	(Sin45 * getMoveSpeed())	) * -1);
								setMoveSpeedY((	(Sin45 * getMoveSpeed())	)		);
								count++;
							}
							else if(count == 4)
							{
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 5)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	 * -1);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	 * -1);
								count++;
							}
							else if(count == 6)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed() * -1);
								count++;
							}
							else if(count == 7)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	 * -1);
								count++;
							}
							else if(count == 8)
							{
								setMoveSpeedX(TempMoveSpeedX);
								setMoveSpeedY(TempMoveSpeedY);
								setHitTest(1);
								count++;
								fBreak = true;
								break;
							}
						}
						else
							break;*/
							setHitTest(1);
								break;

					}/*
					if(fBreak == true)
					{
						fBreak = false;
						break;
					}*/

			//	}
				}
				if(i == MMA)
					setHitTest(0);
				if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
				{
					for(i=0; i<MMC; i++)
					{
						if(mCavalry[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
							mCavalry[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mCavalry[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
							mCavalry[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mCavalry[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
							)
						{
							setHitTest(1);
							break;
						}

					}
					if(i == MMC)
						setHitTest(0);
					if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
					{
						for(i=0; i<MMP; i++)
						{
							if(mPriest[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
								mPriest[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mPriest[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
								mPriest[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mPriest[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
								)
							{
								setHitTest(1);
								break;
							}

						}
						if(i == MMP)
							setHitTest(0);
						if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
						{
							for(i=0; i<MMS; i++)
							{
								if(mSpearman[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
									mSpearman[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mSpearman[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
									mSpearman[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mSpearman[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
									)
								{
									setHitTest(1);
									break;
								}

							}
							if(i == MMS)
								setHitTest(0);
						}
					}
				}

			}

		}
		else if(CprDer == 4)//위쪽이동중일때
		
		{
			for(i=0; i<MMI; i++)
			{
				if(mInfantry[i].getPosX() == getPosX() && mInfantry[i].getPosY() == getPosY())//검사할 아군이 자신일경우 다음아군검사
					continue;

				count = 0;
				while(count < 9)
				{
					if(mInfantry[i].getState_Live() == LIVE && //나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면 // 방향을 튕겨 검사
						
						mInfantry[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mInfantry[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
						mInfantry[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mInfantry[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
						
						

						)
					{

						//setHitTest(1);
						//break;
						if(count == 0)
							{
								TempMoveSpeedX = getMoveSpeedX();
								TempMoveSpeedY = getMoveSpeedY();
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed() * -1);
								count++;
							}
							else if(count == 1)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed()) 	);
								setMoveSpeedY(	(Sin45 * getMoveSpeed()) * -1	);
								count++;
							}
							else if(count == 2)
							{
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 3)
							{
								setMoveSpeedX((Sin45 * getMoveSpeed()));
								setMoveSpeedY((Sin45 * getMoveSpeed()));
								count++;
							}
							else if(count == 4)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed());
								count++;
							}
							else if(count == 5)
							{
								setMoveSpeedX((Sin45 * getMoveSpeed()) * -1);
								setMoveSpeedY((Sin45 * getMoveSpeed()));
								count++;
							}
							else if(count == 6)
							{
								setMoveSpeedX(getMoveSpeed() * -1);
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 7)
							{
								setMoveSpeedX((Sin45 * getMoveSpeed()) * -1);
								setMoveSpeedY((Sin45 * getMoveSpeed()) * -1);
								count++;
							}
							else if(count == 8)
							{
								setMoveSpeedX(TempMoveSpeedX);
								setMoveSpeedY(TempMoveSpeedY);
								setHitTest(1);
								count++;
								fBreak = true;
								break;
							}

					}
					else
						break;
				}

				if(fBreak == true)
				{
					fBreak = false;
					count = 0;
					break;
				}

			}
			if(i == MMI) //아군이 존재하지 않는다면 이동함
				setHitTest(0);
			if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
			{
				for(i=0; i<MMA; i++)
				{

					//while(count < 9)
					//{
						if(mArcher[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
							mArcher[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mArcher[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
							mArcher[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mArcher[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
							)
						{
							/*if(count == 0)
							{
								TempMoveSpeedX = getMoveSpeedX();
								TempMoveSpeedY = getMoveSpeedY();
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 1)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	);
								count++;
							}
							else if(count == 2)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed());
								count++;
							}
							else if(count == 3)
							{
								setMoveSpeedX((	(Sin45 * getMoveSpeed())	) * -1);
								setMoveSpeedY((	(Sin45 * getMoveSpeed())	)		);
								count++;
							}
							else if(count == 4)
							{
								setMoveSpeedX(getMoveSpeed());
								setMoveSpeedY(0);
								count++;
							}
							else if(count == 5)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	 * -1);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	 * -1);
								count++;
							}
							else if(count == 6)
							{
								setMoveSpeedX(0);
								setMoveSpeedY(getMoveSpeed() * -1);
								count++;
							}
							else if(count == 7)
							{
								setMoveSpeedX(	(Sin45 * getMoveSpeed())	);
								setMoveSpeedY(	(Sin45 * getMoveSpeed())	 * -1);
								count++;
							}
							else if(count == 8)
							{
								setMoveSpeedX(TempMoveSpeedX);
								setMoveSpeedY(TempMoveSpeedY);
								setHitTest(1);
								count++;
								fBreak = true;
								break;
							}
						}
						else
							break;*/
							setHitTest(1);
								break;

					}/*
					if(fBreak == true)
					{
						fBreak = false;
						break;
					}*/

			//	}
				}
				if(i == MMA)
					setHitTest(0);
				if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
				{
					for(i=0; i<MMC; i++)
					{
						if(mCavalry[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
							mCavalry[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mCavalry[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
							mCavalry[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mCavalry[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
							)
						{
							setHitTest(1);
							break;
						}

					}
					if(i == MMC)
						setHitTest(0);
					if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
					{
						for(i=0; i<MMP; i++)
						{
							if(mPriest[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
								mPriest[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mPriest[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
								mPriest[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mPriest[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
								)
							{
								setHitTest(1);
								break;
							}

						}
						if(i == MMP)
							setHitTest(0);
						if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
						{
							for(i=0; i<MMS; i++)
							{
								if(mSpearman[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
									mSpearman[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mSpearman[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
									mSpearman[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mSpearman[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
									)
								{
									setHitTest(1);
									break;
								}

							}
							if(i == MMS)
								setHitTest(0);
						}
					}
				}

			}

		}

	}
}
void cInfantry::Move()
{
	if(getState_Live() == LIVE && getState_Move() == WALK)
	{
		setAngle(g_Angle.atan_Degree(getMoveSpeedX(),getMoveSpeedY()));
		if(getHitTest() == 0) // 진행방향에 아군이 없으면 이동
		{
			setPosX ( getPosX() + getMoveSpeedX() );
			setPosY ( getPosY() + getMoveSpeedY() );
		}
	}
}
void cInfantry::Reset()
{
	setMoveTargeting(0);
}
void cInfantry::CheckLive()
{
	cUnit::CheckLive();

}

void cInfantry::AttackTo(cUnit &target, DWORD passTime)
{
	Attack = true;
	cUnit::AttackTo(target,passTime);
	//AttackTarget->setHp(AttackTarget->getHp() - getDamage());
}

void cInfantry::Render(d_OFFSET offset)
{
	if(m_Attack.getFrameOnce() == true)
	{
		Attack = false;
		m_Attack.m_bFrameOnceCompleted = false;
		//AttackTarget->setHp(AttackTarget->getHp() - getDamage());
	}
	if(Attack == true)
	{
		m_Attack.drawFrameAutoRGB(getPosX() - offset.x,getPosY() - offset.y,RGB(255,0,255));
	}
}