#include "cCavalry.h"


cCavalry::cCavalry(void)
{
	
	setPosX(0);
	setPosY(0);
	setMaxHp(80);
	setHp(getMaxHp());
	setMaxMp(100);
	setMp(getMaxMp());
	setUnitRange(2000);
	setRange(TILE_WIDTH + 10);
	setMoveSpeed(2.200/VN_FPS);
	setDamage(13);
	setAttackSpeed(600);
	setUnitType(1);
	setDefence(1);
	setState_Attack(FIGHT);
	setState_Live(LIVE);
	setState_Move(WALK);
	setAttackAble(true);
	setlastAttackTime(0);
	setHitTest(false);
	setMoveTargeting(0);
	setMoveTargeted(false);
}


cCavalry::~cCavalry(void)
{
	
}

void cCavalry::Init()
{
	setPosX(0);
	setPosY(0);
	setMaxHp(80);
	setHp(getMaxHp());
	setMaxMp(100);
	setMp(getMaxMp());
	setUnitRange(2000);
	setRange(TILE_WIDTH + 10);
	setMoveSpeed(2.200/VN_FPS);
	setDamage(14);
	setAttackSpeed(600);
	setUnitType(1);
	setDefence(1);
	setState_Attack(FIGHT);
	setState_Live(LIVE);
	setState_Move(WALK);
	setAttackAble(true);
	setlastAttackTime(0);
	setHitTest(false);
	setMoveTargeting(0);
	setMoveTargeted(false);
}


void cCavalry::SearchEnemy(cCavalry* eCavalry,int MEC,DWORD passTime)
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

void cCavalry::SearchEnemy(cInfantry* eInfantry,int MEI,DWORD passTime)
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

void cCavalry::SearchEnemy(cArcher* eArcher,int MEA,DWORD passTime)
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


void cCavalry::SearchEnemy(cPriest* ePriest,int MEP,DWORD passTime)
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

void cCavalry::SearchEnemy(cSpearman* eSpearman,int MES,DWORD passTime)
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


void cCavalry::Update(DWORD passTime,cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS)
{
	
	if(getState_Live() == LIVE)
	{
		if(getAttackAble() == false && passTime - getlastAttackTime() >= getAttackSpeed())
			setAttackAble(true);

		//setAttackAble(true);
		SearchEnemy(eSpearman,MES,passTime);
		SearchEnemy(eCavalry,MEC,passTime);
		SearchEnemy(eInfantry,MEI,passTime);
		SearchEnemy(eArcher,MEA,passTime);
		SearchEnemy(ePriest,MEP,passTime);
		//if(getState_Live() == LIVE)
		//	{
		MoveSpeedCheck(eInfantry,MEI,eArcher,MEA,eCavalry,MEC,ePriest,MEP,eSpearman,MES);
		MoveCheck(mInfantry,MMI,mArcher,MMA,mCavalry,MMC,mPriest,MMP,mSpearman,MMS);
		//	}
	}
}


void cCavalry::MoveSpeedCheck(cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES)
{
	if(getMoveTargeted() == false)
	{
		if(getState_Live() == LIVE && getState_Move() == WALK)
		{

			//TempPos�� �������� �ֽ��ϴ�.
			int TempPosX = EndPosX;
			int TempPosY = EndPosY;

			bool TargetBreak = false;
			int TargetingCount = 1;
			int i = 0;
			while(TargetBreak == false)
			{

				//���� ������ �˻��մϴ�.
				for(i=0;i<MEI;i++)
				{
					if(eInfantry[i].getState_Live() == LIVE//getState_Move() == WALK //����������  ���ֽþ� �ȿ� �������
						&& eInfantry[i].getPosX() >getPosX() - getUnitRange()  && eInfantry[i].getPosX()  < getPosX() + getUnitRange()
						&& eInfantry[i].getPosY() >getPosY() - getUnitRange()  && eInfantry[i].getPosY()  < getPosY() + getUnitRange() 
						)
					{
						//���� ������ Ÿ������ 0�� ���
						if(eInfantry[i].getMoveTargeting() < TargetingCount)
						{
							eInfantry[i].setMoveTargeting(eInfantry[i].getMoveTargeting() + 1);//������ Ÿ������ 1 �ø���
							TempPosX = eInfantry[i].getPosX();								   //���� ��ġ�� �������� ���մϴ�.
							TempPosY = eInfantry[i].getPosY();
							TargetBreak = true;
							setMoveTargeted(true);
							MoveTarget = &eInfantry[i];
							break;
						}
					}
				}
				//���� ���������� Ÿ������ ���� �Ǿ��������
				//����������� �ü��� �˻��մϴ�.
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
			setWidth ( ((getLastEndPosX()) - getPosX()) );
			setHeight ( ((getLastEndPosY()) - getPosY()) );
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
void cCavalry::MoveCheck(cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS)
{
	
		

	if(getState_Live() == LIVE && getState_Move() == WALK)
	{
			int i=0;
			
			
			for(i=0; i<MMI; i++)
			{
				
				if(mInfantry[i].getState_Live() == LIVE && //���� ���� ������⿡ �Ʊ��� �����Ѵٸ� ���� ��ٸ� // �����Ѵٸ�
						mInfantry[i].getPosX() + (TILE_WIDTH/2) > getPosX() + getMoveSpeedX() && mInfantry[i].getPosX() + (TILE_WIDTH/2) < getPosX() + getMoveSpeedX()  + TILE_WIDTH &&
						mInfantry[i].getPosY() + (TILE_HEIGHT/2) > getPosY() + getMoveSpeedY() && mInfantry[i].getPosY() + (TILE_HEIGHT/2) < getPosY() + getMoveSpeedY()  + TILE_HEIGHT
						)
					{
							setHitTest(1);
							break;
					}

			}
			if(i == MMI) //�Ʊ��� �������� �ʴ´ٸ� �̵���
				setHitTest(0);
			if(getHitTest() == 0) //���� �Ʊ��� �������� �ʴ´ٸ� �ٸ��Ʊ������� �˻���
			{
				for(i=0; i<MMA; i++)
				{
					if(mArcher[i].getState_Live() == LIVE &&//���� ���� ������⿡ �Ʊ��� �����Ѵٸ� ���� ��ٸ� // �����Ѵٸ�
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
				if(getHitTest() == 0) //���� �Ʊ��� �������� �ʴ´ٸ� �ٸ��Ʊ������� �˻���
				{
					for(i=0; i<MMC; i++)
					{
						if(mCavalry[i].getPosX() == getPosX() && mCavalry[i].getPosY() == getPosY())//�˻��� �Ʊ��� �ڽ��ϰ�� �����Ʊ��˻�
								continue;
						if(mCavalry[i].getState_Live() == LIVE &&//���� ���� ������⿡ �Ʊ��� �����Ѵٸ� ���� ��ٸ� // �����Ѵٸ�
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
					if(getHitTest() == 0) //���� �Ʊ��� �������� �ʴ´ٸ� �ٸ��Ʊ������� �˻���
					{
						for(i=0; i<MMP; i++)
						{
							if(mPriest[i].getState_Live() == LIVE &&//���� ���� ������⿡ �Ʊ��� �����Ѵٸ� ���� ��ٸ� // �����Ѵٸ�
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
						if(getHitTest() == 0) //���� �Ʊ��� �������� �ʴ´ٸ� �ٸ��Ʊ������� �˻���
						{
							for(i=0; i<MMS; i++)
							{
								if(mSpearman[i].getState_Live() == LIVE &&//���� ���� ������⿡ �Ʊ��� �����Ѵٸ� ���� ��ٸ� // �����Ѵٸ�
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
void cCavalry::Move()
{
	if(getState_Live() == LIVE && getState_Move() == WALK)
	{
		if(getHitTest() == 0) // ������⿡ �Ʊ��� ������ �̵�
		{
			setPosX ( getPosX() + getMoveSpeedX() );
			setPosY ( getPosY() + getMoveSpeedY() );
		}
	}
}
void cCavalry::Reset()
{
	setMoveTargeting(0);
}

void cCavalry::CheckLive()
{
	cUnit::CheckLive();
}