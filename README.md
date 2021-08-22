# Limit

### 한국게임과학고등학교 1학년 겨울방학 팀프로젝트

프로젝트 소개 : Limit는 정해진 자원안에서 용병을 고용하여 적을 물리치는 전략게임입니다.

사용 기술 : C++, WindowsAPI

담당 역할 : 팀장, 프로그래밍 전체

개발기간 : 2011년 12월~ 2012년 2월

핵심 기술 / 알고리즘 : 게임 속 유닛의 구현. 아군 및 적군 유닛의 자동전투 시뮬레이션. 전투 이동을 위해 유닛을 겹치지 않으면서 유닛이 다음 위치를 찾아갈 수 있도록 하는 알고리즘 구현. 원거리 투사체 공격 및 아군 힐링 알고리즘 구현.

게임 소개 : https://github.com/justkoi/Limit/blob/main/Limit%EA%B2%8C%EC%9E%84%EC%86%8C%EA%B0%9C.docx 해당 파일을 참고해주세요.

플레이 영상 : https://youtu.be/8KpYQOkhGWc

프로젝트 주소 : https://github.com/justkoi/Limit

### 핵심 코드 설명

#### 소스코드 경로 : [https://github.com/justkoi/Limit/tree/main/%EA%B2%8C%EC%9E%84%ED%8C%8C%EC%9D%BC(C%2B%2B%2CWindowsAPI)/%5BAPI%5D2011%EB%85%84%20%EA%B2%A8%EC%9A%B8%EB%B0%A9%ED%95%99%20%ED%8C%80%20%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8%5BLimit%5D](https://github.com/justkoi/Limit/tree/main/게임파일(C%2B%2B%2CWindowsAPI)/[API]2011년 겨울방학 팀 프로젝트[Limit])

cLogo.cpp - 게임 타이틀 씬

cLevelMenu.cpp, cStageMenu.cpp - 게임 메뉴 씬

[헤더에 대한 선언은 *.cpp파일을 참고해주세요.]

#### cUnit.h : 유닛을 정의하는 부모 클래스.

```C++
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
```

#### cInfantry.h (보병)

```C++
class cInfantry :public cUnit
{
private:
	cSceneManager m_Attack;
public:
	bool Attack;
	cInfantry(void);
	~cInfantry(void);
	void Init();
	void SearchEnemy(cPriest* ePriest,int MEP,DWORD passTime);
	void SearchEnemy(cInfantry* eInfantry,int MEI,DWORD passTime);
	void SearchEnemy(cArcher* eArcher,int MEA,DWORD passTime);
	void SearchEnemy(cCavalry* eCavalry,int MEC,DWORD passTime);
	void SearchEnemy(cSpearman* eSpearman,int MES,DWORD passTime);


	void Update(DWORD passTime,cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,
		cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS,int MaxRoute,MoveRoute * MoveRoute);

	void MoveSpeedCheck(cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,int MaxRoute,MoveRoute * MoveRoute);
	void MoveCheck(cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS);
	void Move();
	void Reset();

	void AttackTo(cUnit &target, DWORD passTime);
	void CheckLive();
	void Render(d_OFFSET offset);
	void AngleCheck();
};
```

#### cArcher.h (궁수)

```C++
class cArcher :public cUnit
{
	
public:
	cArrow* Arrow;

	cArcher(void);
	~cArcher(void);
	
	void Init();

	void SearchEnemy(cCavalry* eCavalry,int MEC,DWORD passTime,cArcher* eArcher,int MEA,cInfantry* eInfantry,int MEI,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES);
	void SearchEnemy(cInfantry* eInfantry,int MEI,DWORD passTime,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES);
	void SearchEnemy(cArcher* eArcher,int MEA,DWORD passTime,cInfantry* eInfantry,int MEI,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES);
	void SearchEnemy(cPriest* ePriest,int MEP,DWORD passTime,cArcher* eArcher,int MEA,cInfantry* eInfantry,int MEI,cCavalry* eCavalry,int MEC,cSpearman* eSpearman,int MES);
	void SearchEnemy(cSpearman* eSpearman,int MES,DWORD passTime,cArcher* eArcher,int MEA,cInfantry* eInfantry,int MEI,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP);


	void Update(DWORD passTime,cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES,
		cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS);
	
	void MoveSpeedCheck(cInfantry* eInfantry,int MEI,cArcher* eArcher,int MEA,cCavalry* eCavalry,int MEC,cPriest* ePriest,int MEP,cSpearman* eSpearman,int MES);
	void MoveCheck(cInfantry* mInfantry,int MMI,cArcher* mArcher,int MMA,cCavalry* mCavalry,int MMC,cPriest* mPriest,int MMP,cSpearman* mSpearman,int MMS);
	void Move();
	void Reset();


	void CheckLive();
	void AttackTo(cUnit &target, DWORD passTime);
	void ShootArrow();
};
```

**cCavalry.h, cPriest.h** (기병, 사제)

사제의 경우 SearchAlly 메서드를 통해 적군 대신 아군을 찾아서 치유함.

의의 : 상속을 이용한 유닛 구현, 가상함수 사용 시도

한계 : 부모 자식 클래스간 형변환에 대한 낮은 이해



#### cGame.cpp - 게임 메인 씬

이동 알고리즘은 각 유닛의 Update와 게임의 Update에서 구현

1. 각 유닛은 별도의 경로맵에 있는 이동 목표 지점을 기억
2. 이동 목표 지점의 방향으로 이동(기본)
3. 이동 중 매 프레임마다 자신의 탐색범위(Range)안에 있는 적을 계속 찾아봄. ( 현재 기억중인 적이 없다면 )
4. 적을 찾았다면 해당 적을 자신의 목표 적으로 기억 후 해당 위치로 이동 목표 지점 수정.
5. 이동 중 매 프레임마다 자신의 공격범위안에 적이 있는지 확인. 적이 있다면 공격을 수행.
6. 외부 Game Update(관리자)가 각 유닛끼리 겹치지 않도록 충돌체크를 통해 겹친경우 잠시 이동을 중재함.

의의 : 실행가능한 이동 및 전투 인공지능 구현

한계 : 별도의 외부 관리자 없이 유닛 내부 Update에서 구현하여 각 유닛이 스스로 상호작용하도록 하는것이 가장 바람직함. A* 알고리즘의 적용 실력부족. 매번 경로 맵이 필요함. 경로와 적의 남은 체력등의 가중치를 혼합하여 자신에게 가장 가까운 적을 향하도록 하는 방안이 좋았을것.



