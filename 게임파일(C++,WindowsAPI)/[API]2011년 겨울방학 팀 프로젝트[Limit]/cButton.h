#pragma once
#include <Windows.h>
//#include "cGdiGraphics.h"
#include "cGdiImage.h"

class cButton
{
	  float X;             // ��ǥ����� X ��ǥ
        float Y;             // ��ǥ����� Y ��ǥ
        float Width;         // ���� ���� ��      * ��ư�� ��ġ ���� ����
        float Height;        // ���� ���� ��      * ��ư�� ��ġ ���� ����
        bool Over;           // ��ư���� �ִ°�?
		bool Down;		     // ��ư�� �����°�?
        bool Visible;        // ���ü�. false �� ��� ������ ������. ��� ����� ����Ѵ�.
        int Alpha;           // ����. ���� ���� �����.     ������ �ȵɰ�� ������ flase �϶��� �������� ����. bool������ �ٲ�
       // int Xscale;
       // int Yscale;
       // bool Focus;          // ���ߵ�. �� ��ư�� �����ϴ� ���ΰ�. ����� ���� ������ ����. Flash������ ����� �׵θ��� �׷�����.

	cGdiImage Img;       // ���� �̹���
	cGdiImage Img_over;  // ���� �̹���
	cGdiImage Img_down;	// �ٿ� �̹���
public:
	cButton(float ipX, float ipY, float ipWidth, float ipHeight) :
	  X(ipX), Y(ipY), Width(ipWidth), Height(ipHeight)
	{
		Over = false;
		Down = false;
	};
	~cButton();
	void SetButtonPos(float setX, float setY);
	void SetButtonHit(float setWidth, float setHeight);
	void ButtonImgLoad(char* rImg,char* rImg_over);
	void CheckOver(WORD mx, WORD my);
	void CheckDown(WORD mx, WORD my);
	bool CheckUp(WORD mx, WORD my);
	void Render();
	void Destroy();
};

