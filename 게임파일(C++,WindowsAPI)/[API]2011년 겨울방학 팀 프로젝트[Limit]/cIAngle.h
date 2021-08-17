#pragma once
class cIAngle
{
public:
	double PI;
	double CI;
public:
	cIAngle()
	{
		PI=3.141592;
		CI=PI*2;
	}
public:
	double Radian(double Degree)
	{
		return Degree*(PI/180.0);
	}
	double Degree(double Radian)
	{
		return Radian*(180/PI);
	}
public:
	double Cell_Radian(double Degree)
	{
		if(Degree==0)
			return Radian(90);
		if(Degree>0)
		{
			if(Degree>90)
			{
				return Radian( 360 + (90 - Degree));
			}
			else
			{
				return Radian(90 - Degree);
			}
		}
		if(Degree<0)
		{
			return Radian(90 - Degree);
		}
	}


	double Cell_Degree(double Radian)
	{
		if(Radian == 0)
			return 90;
		if(Radian>0)
			return 90-Degree(Radian);
		if(Radian<0)
			return 90-Degree(Radian);
	}
public:
	double atan_Radian(double x, double y)
	{
		if(x==0 && y==0)
			return Radian(0);
		if(x>0 && y==0)//0도 혹은 360 도
			return Radian(0);
		if(x==0 && y>0)//90도
			return Radian(90);
		if(x<0 && y==0)//180도
			return Radian(180);
		if(x==0 && y<0)//270도
			return Radian(270);

		if(x>0 && y>0)//1사분면
			return atan(y/x);
		if(x<0 && y>0)//2사분면
			return Radian(180)+atan(y/x);
		if(x<0 && y<0)//3사분면
			return Radian(180)+atan(y/x);
		if(x>0 && y<0)//4사분면
			return Radian(360)+atan(y/x);

	}
	double atan_Degree(double x, double y)
	{
		if(x==0 && y==0)
			return Radian(0);
		if(x>0 && y==0)//0도 혹은 360 도
			return 0;
		if(x==0 && y>0)//90도
			return 90;
		if(x<0 && y==0)//180도
			return 180;
		if(x==0 && y<0)//270도
			return 270;

		if(x>0 && y>0)//1사분면
			return Degree(atan(y/x));
		if(x<0 && y>0)//2사분면
			return 180 + Degree(atan(y/x));
		if(x<0 && y<0)//3사분면
			return 180 + Degree(atan(y/x));
		if(x>0 && y<0)//4사분면
			return 360 + Degree(atan(y/x));

	}


};