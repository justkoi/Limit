#include "cUnit.h"
#include "MY_include.h"

double EndPosX = 800;
double EndPosY = 200;


cUnit::cUnit(void)
{
	/*OpenList_head = new NodeList;
	OpenList_tail = new NodeList;

	
	
	Node_Init();*/
	//m_AttackSound = new fSound();
	//m_AttackSound->SoundLoad("./Sound/Attack01.mp3");
}


cUnit::~cUnit(void)
{

}
void cUnit::Node_Init()
{

	/*

	OpenList_head->f = 1;
	OpenList_head->prev = NULL;
	OpenList_head->next = NULL;

	OpenList_tail->f = 2;
	OpenList_tail->prev = NULL;
	OpenList_tail->next = NULL;

	OpenList_head->next = OpenList_tail;
	OpenList_tail->prev = OpenList_head;
*/
	


}
double cUnit::getPosX()
{
	return X;
}
double cUnit::getPosY()
{
	return Y;
}
int cUnit::getHp()
{
	return Hp;
}
int cUnit::getMaxHp()
{
	return MaxHp;
}
int cUnit::getMp()
{
	return Mp;
}
int cUnit::getMaxMp()
{
	return MaxMp;
}
double cUnit::getRange()
{
	return Range;
}
double cUnit::getMoveSpeed()
{
	return MoveSpeed;
}
int cUnit::getDamage()
{
	return Damage;
}
int cUnit::getAttackSpeed()
{
	return AttackSpeed;
}
int cUnit::getUnitType()
{
	return UnitType;
}

int cUnit::getDefence()
{
	return Defence;
}
int cUnit::getState_Move()
{
	return State_Move;
}
int cUnit::getState_Attack()
{
	return State_Attack;
}

int cUnit::getState_Live()
{
	return State_Live;
}

bool cUnit::getAttackAble()
{
	return AttackAble;
}
	
DWORD cUnit::getlastAttackTime()
{
	return lastAttackTime;
}


double cUnit::getLastEndPosX()
{
	return LastEndPosX;
}
double cUnit::getLastEndPosY()
{
	return LastEndPosY;
}
double cUnit::getMoveSpeedX()
{
	return MoveSpeedX;
}
double cUnit::getMoveSpeedY()
{
	return MoveSpeedY;
}

int cUnit::getHitTest()
{
	return HitTest;
}
double cUnit::getDistance()
{
	return Distance;
}
double cUnit::getUnitRange()
{
	return UnitRange;
}
int cUnit::getMoveTargeting()
{
	return MoveTargeting;
}
bool cUnit::getMoveTargeted()
{
	return MoveTargeted;
}

double  cUnit::getWidth()
{
	return Width;
}
double  cUnit::getHeight()
{
	return Height;
}

int	cUnit::getNowRoute()
{
	return NowRoute;
}
double cUnit::getAngle()
{
	return Angle;
}
////////////



void cUnit::setPosX(double value)
{
	X = value;
}
void cUnit::setPosY(double value)
{
	Y = value;
}
void cUnit::setHp(int value)
{
	Hp = value;
}
void cUnit::setMaxHp(int value)
{
	MaxHp = value;
}
void cUnit::setMp(int value)
{
	Mp = value;
}
void cUnit::setMaxMp(int value)
{
	MaxMp = value;
}
void cUnit::setRange(double value)
{
	Range = value;
}
void cUnit::setMoveSpeed(double value)
{
	MoveSpeed = value;
}
void cUnit::setDamage(int value)
{
	Damage = value;
}
void cUnit::setAttackSpeed(int value)
{
	AttackSpeed = value;
}
void cUnit::setUnitType(int value)
{
	UnitType = value;
}

void cUnit::setDefence(int value)
{
	Defence = value;
}
void cUnit::setState_Move(int value)
{
	State_Move = value;
}
void cUnit::setState_Attack(int value)
{
	State_Attack = value;
}
void cUnit::setState_Live(int value)
{
	State_Live = value;
}
void cUnit::setAttackAble(bool value)
{
	AttackAble = value;
}
void cUnit::setlastAttackTime(DWORD value)
{
lastAttackTime = value;
} 


void cUnit::setLastEndPosX(double value)
{
	LastEndPosX = value;
}
void cUnit::setLastEndPosY(double value)
{
	LastEndPosY = value;
}
void cUnit::setMoveSpeedX(double value)
{
	MoveSpeedX = value;
}
void cUnit::setMoveSpeedY(double value)
{
	MoveSpeedY = value;
}

void cUnit::setHitTest(int value)
{
	HitTest = value;
}

void cUnit::setDistance(double value)
{
	Distance = value;
}
void cUnit::setUnitRange(double value)
{
	UnitRange = value;
}
void cUnit::setMoveTargeting(int value)
{
	MoveTargeting = value;
}
void cUnit::setMoveTargeted(bool value)
{
	MoveTargeted = value;
}
void cUnit::setWidth(double value)
{
	Width = value;
}
void cUnit::setHeight(double value)
{
	Height = value;
}
void cUnit::setNowRoute(int value)
{
	NowRoute = value;
}
void cUnit::setAngle(double value)
{
	Angle = value;
}
//
void cUnit::ShowInfo(int i)
{//콘솔창에서실험의 잔재입니다.

	printf("***\t%d번째\t***\n",i);
	printf("유닛의 체력\t: %d / %d\n",Hp,MaxHp);
	printf("유닛의 마나\t: %d / %d\n",Mp,MaxMp);
	printf("유닛의 사거리\t: %d\n",Range);
	printf("유닛의 좌표\t: (%d,%d)\n",X,Y);
	printf("유닛의 유형\t: %d\n",UnitType);
	printf("유닛의 생존\t: %d\n",State_Live);
	printf("**************************\n");
}

//행동관련

void cUnit::AttackTo(cUnit &target , DWORD passTime)
{
	if(AttackAble == true)
	{
	//	setHitTest(1);
		State_Move = NONE;
		AttackAble = false;
		lastAttackTime = passTime;
		
		AttackTarget = &target;
		AttackTarget->setHp(AttackTarget->getHp() - getDamage());
		//AttackTarget->setHp(AttackTarget->getHp() - ((getDamage()*(rand()%30+90))/100) );
		for(int i=0; i<MaxSound01; i++)
		{
			if(AttackSound01[i].Played == false)
			{
				AttackSound01[i].PLAYSound();
				break;
			}
		}
	}
}
void cUnit::CheckLive()
{
	if(Hp<=0 && State_Live == LIVE)
	{
		State_Live = DING;
	}
	else if(State_Live == DING)
	{
		//애니메이션재생 후에
		State_Live = DEAD;
	}
	else if(State_Live == DEAD)
	{
		//딱히 없음
	}
}
void cUnit::Move()
{
	
	if(State_Live == LIVE && State_Move == WALK)
	{
	
		LastEndPosX = EndPosX + (TILE_WIDTH/2);
		LastEndPosY = EndPosY + (TILE_HEIGHT/2);
		double Width = ((LastEndPosX) - X);
		double Height = ((LastEndPosY) - Y);
		double Distance = sqrt((Width*Width) + (Height*Height));
		
		MoveSpeedX = Width / (Distance/MoveSpeed);
		MoveSpeedY = Height/ (Distance/MoveSpeed);

		X += MoveSpeedX;
		Y += MoveSpeedY;

	}
}
void cUnit::SearchEnemy(cUnit* &EyInfantry,int MaxEy, DWORD passTime)
{
	
	if(AttackAble == true)
	{
		for(int i=0;i<MaxEy;i++)
		{
			if(State_Move == WALK && EyInfantry[i].getState_Live() == LIVE
				&& EyInfantry[i].getPosX() >X - Range  && EyInfantry[i].getPosX()  < X + Range
				&& EyInfantry[i].getPosY() >Y- Range  && EyInfantry[i].getPosY()  < Y + Range )
			{
				//적 검색 완료
				AttackTo(EyInfantry[i], passTime);
				return;
			}
		}
	}
	else if(State_Move == NONE)
	{
		State_Move == WALK;
	}
}



//업데이트
void cUnit::Update(DWORD passTime,cUnit* &Enemy,int MaxEy)
{
	if(AttackAble == false && passTime - lastAttackTime >= AttackSpeed)
		AttackAble = true;
	SearchEnemy(Enemy,MaxEy,passTime);
	if(State_Live == LIVE)
	{
		Move();
	}
}