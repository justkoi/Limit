#include "cSpearman.h"


cSpearman::cSpearman(void)
{
	setPosX(0);
	setPosY(0);
	setMaxHp(110);
	setHp(getMaxHp());
	setMaxMp(100);
	setMp(getMaxMp());
	setUnitRange(2000);
	setRange(TILE_WIDTH + 30);
	setMoveSpeed(1.3000/VN_FPS);
	setDamage(12);
	setStrikeDamage(35);					//기병에게 추가데미지
	setAttackSpeed(1500);
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
}


cSpearman::~cSpearman(void)
{
	
}

void cSpearman::Init()
{
	setPosX(0);
	setPosY(0);
	setMaxHp(110);
	setHp(getMaxHp());
	setMaxMp(100);
	setMp(getMaxMp());
	setUnitRange(2000);
	setRange(TILE_WIDTH + 30);
	setMoveSpeed(1.3000/VN_FPS);
	setDamage(12);
	setStrikeDamage(35);					//기병에게 추가데미지
	setAttackSpeed(1500);
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
}


void cSpearman::SearchEnemy(cCavalry* eCavalry,int MEC,DWORD passTime)
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
				StrikeTo(eCavalry[i], passTime);
				return;
			}
		}
		if(i == MEC && getState_Move() == NONE)
		{
			setState_Move(WALK);
		}

	}
}
void cSpearman::SearchEnemy(cInfantry* eInfantry,int MEI,DWORD passTime)
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

void cSpearman::SearchEnemy(cArcher* eArcher,int MEA,DWORD passTime)
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


void cSpearman::SearchEnemy(cPriest* ePriest,int MEP,DWORD passTime)
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


void cSpearman::SearchEnemy(cSpearman* eSpearman,int MES,DWORD passTime)
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

void cSpearman::Update(DWORD passTime,cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,
		cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS)
{
	
	if(getState_Live() == LIVE)
	{
		if(getAttackAble() == false && passTime - getlastAttackTime() >= getAttackSpeed())
			setAttackAble(true);

		//setAttackAble(true);
		SearchEnemy(eCavalry,MEC,passTime);
		SearchEnemy(eInfantry,MEI,passTime);
		SearchEnemy(eArcher,MEA,passTime);
		SearchEnemy(ePriest,MEP,passTime);
		SearchEnemy(eSpearman,MES,passTime);
		//if(getState_Live() == LIVE)
		//	{
		MoveSpeedCheck(eInfantry,MEI,eArcher,MEA,eCavalry,MEC,ePriest,MEP,eSpearman,MES);
		MoveCheck(mInfantry,MMI,mArcher,MMA,mCavalry,MMC,mPriest,MMP,mSpearman,MMS);
		
		//	}
	}
}


void cSpearman::MoveSpeedCheck(cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES)
{
	if(getMoveTargeted() == false)
	{
		if(getState_Live() == LIVE && getState_Move() == WALK)
		{

			//TempPos에 목적지를 넣습니다.
			int TempPosX = EndPosX;
			int TempPosY = EndPosY;

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
			setWidth( ((getLastEndPosX()) - getPosX()) );
			setHeight( ((getLastEndPosY()) - getPosY()) );
			setDistance(sqrt((getWidth()*getWidth()) + (getHeight()*getHeight())));

			setMoveSpeedX ( getWidth() / (getDistance()/getMoveSpeed()) );
			setMoveSpeedY ( getHeight()/ (getDistance()/getMoveSpeed()) );

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
			setWidth( ((getLastEndPosX()) - getPosX()) );
			setHeight( ((getLastEndPosY()) - getPosY()) );
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
void cSpearman::MoveCheck(cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS)
{
	
		

	if(getState_Live() == LIVE && getState_Move() == WALK)
	{
			int i=0;
			
			
			for(i=0; i<MMI; i++)
			{
				
				if(mInfantry[i].getState_Live() == LIVE && //나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
						mInfantry[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mInfantry[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
						mInfantry[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mInfantry[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
						)
					{
							setHitTest(1);
							break;
					}

			}
			if(i == MMI) //아군이 존재하지 않는다면 이동함
				setHitTest(0);
			if(getHitTest() == 0) //앞의 아군이 존재하지 않는다면 다른아군종류를 검사함
			{
				for(i=0; i<MMA; i++)
				{
					if(mArcher[i].getState_Live() == LIVE &&//나의 다음 진행방향에 아군이 존재한다면 나는 기다림 // 존재한다면
							mArcher[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mArcher[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
							mArcher[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mArcher[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
							)
						{
								setHitTest(1);
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
								if(mSpearman[i].getPosX() == getPosX() && mSpearman[i].getPosY() == getPosY())//검사할 아군이 자신일경우 다음아군검사
										continue;
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
void cSpearman::Move()
{
	if(getState_Live() == LIVE && getState_Move() == WALK)
	{
		if(getHitTest() == 0) // 진행방향에 아군이 없으면 이동
		{
			setPosX ( getPosX() + getMoveSpeedX() );
			setPosY ( getPosY() + getMoveSpeedY() );
		}
	}
}
void cSpearman::Reset()
{
	setMoveTargeting(0);
}



void cSpearman::CheckLive()
{
	cUnit::CheckLive();
}


void cSpearman::StrikeTo(cUnit &target, DWORD passTime)
{
	if(getAttackAble() == true)
	{
		setState_Move(NONE);
		setAttackAble(false);
		setlastAttackTime(passTime);
		
		target.setHp(target.getHp() - getDamage() - getStrikeDamage());
		//target.setHp(target.getHp() - ((rand()%Damage)/5) + ((rand()%Damage)/5) - Damage);
	}
}




int cSpearman::getStrikeDamage()
{
	return StrikeDamage;
}
void cSpearman::setStrikeDamage(int value)
{
	StrikeDamage = value;
}