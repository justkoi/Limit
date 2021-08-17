#pragma once
#include <Windows.h>
//#include "cGdiGraphics.h"
#include "cGdiImage.h"

class cButton
{
	  float X;             // 좌표평면의 X 좌표
        float Y;             // 좌표평면의 Y 좌표
        float Width;         // 가로 길이 값      * 버튼의 터치 반응 범위
        float Height;        // 세로 길이 값      * 버튼의 터치 반응 범위
        bool Over;           // 버튼위에 있는가?
		bool Down;		     // 버튼을 눌럿는가?
        bool Visible;        // 가시성. false 일 경우 보이지 않으며. 모든 기능을 상실한다.
        int Alpha;           // 투명도. 아직 구현 방법모름.     구현이 안될경우 투명도가 flase 일때는 보여주지 않음. bool형으로 바꿈
       // int Xscale;
       // int Yscale;
       // bool Focus;          // 집중도. 이 버튼에 집중하는 중인가. 기능은 아직 정하지 않음. Flash에서는 노란색 테두리가 그려진다.

	cGdiImage Img;       // 실제 이미지
	cGdiImage Img_over;  // 오버 이미지
	cGdiImage Img_down;	// 다운 이미지
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

