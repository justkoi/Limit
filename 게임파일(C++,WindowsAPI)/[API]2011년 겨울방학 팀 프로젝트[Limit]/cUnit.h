#pragma once
#include <iostream>
#include <Windows.h>
#include "MY_Define.h"
#include "fmodSound.h"


typedef struct NodeList
{
	int f;
	struct  NodeList * prev;
	struct  NodeList * next;
}NodeList;
class cUnit
{

private:
	
	//fSound* m_AttackSound;

	double Angle;

	int NowRoute;
	double LastEndPosX;
	double LastEndPosY;
	double MoveSpeedX;
	double MoveSpeedY;
	double Distance;
	double Width;
	double Height;
	double X;
	double Y;
	int Hp;
	int MaxHp;
	int Mp;
	int MaxMp;
	double Range;
	double UnitRange;
	int	MoveTargeting;
	bool MoveTargeted;
	double MoveSpeed;
	
	int Damage;
	int AttackSpeed;
	
	int UnitType;
	int Defence;
	int State_Move;
	int State_Attack;
	int State_Live;
	bool AttackAble;
	DWORD lastAttackTime;

	int HitTest;
/*
	NodeList * OpenList_head;
	NodeList * OpenList_tail;
	NodeList * CloseList;*/
public:
	cUnit * MoveTarget;
	cUnit * AttackTarget;
	//변수관련 get
	double getPosX();
	double getPosY();
	int getHp();
	int getMaxHp();
	int getMp();
	int getMaxMp();
	double getRange();
	double getMoveSpeed();
	int getDamage();
	int getAttackSpeed();
	int getUnitType();
	int getDefence();
	int getState_Move();
	int getState_Attack();
	int getState_Live();
	bool getAttackAble();
	DWORD getlastAttackTime();
	double getLastEndPosX();
	double getLastEndPosY();
	double getMoveSpeedX();
	double getMoveSpeedY();
	int   getHitTest();
	double getDistance();
	double getUnitRange();
	int    getMoveTargeting();
	bool   getMoveTargeted();
	double getWidth();
	double getHeight();
	int		getNowRoute();
	double	getAngle();
	//변수관련 set
	void setPosX(double value);
	void setPosY(double value);
	void setHp(int value);
	void setMaxHp(int value);
	void setMp(int value);
	void setMaxMp(int value);
	void setRange(double value);
	void setMoveSpeed(double value);
	void setAttackSpeed(int value);               
	void setUnitType(int value);
	void setDamage(int value);
	void setDefence(int value);
	void setState_Move(int value);
	void setState_Attack(int value);
	void setState_Live(int value);
	void setAttackAble(bool value);
	void setlastAttackTime(DWORD value);
	void setLastEndPosX(double value);
	void setLastEndPosY(double value);
	void setMoveSpeedX(double value);
	void setMoveSpeedY(double value);
	void setHitTest(int value);
	void setDistance(double value);
	void setUnitRange(double value);
	void setMoveTargeting(int value);
	void setMoveTargeted(bool value);
	void setWidth(double value);
	void setHeight(double value);
	void setNowRoute(int value);
	void setAngle(double value);
	//행동관련
	virtual void AttackTo(cUnit &target, DWORD passTime);
	virtual void CheckLive();
	void Move();
	virtual void SearchEnemy(cUnit* &EyInfantry,int MaxEy , DWORD passTime);


	//출력관련
	void ShowInfo(int i);
	void Node_Init();
	//Update
	virtual void Update(DWORD passTime,cUnit* &Enemy,int MaxEy);
	
	cUnit(void);
	~cUnit(void);
};