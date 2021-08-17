#include "cButton.h"

cButton::~cButton()
{
}

void cButton::SetButtonHit(float setWidth, float setHeight)
{
	Width = setWidth;
	Height = setHeight;
}
void cButton::SetButtonPos(float setX, float setY)
{
	X = setX;
	Y = setY;
}
void cButton::ButtonImgLoad(char* rImg,char* rImg_over)
{
	Img.SetDC(g_Graphics.getGraphicsDC());
	Img_over.SetDC(g_Graphics.getGraphicsDC());
	

	
	Img.Load(rImg);
	Img_over.Load(rImg_over);
}
void cButton::CheckOver(WORD mx, WORD my)
{
	
	if(mx > X && mx < X + Width
	&& my > Y && my < Y + Height)
	{
		Over = true;
	}
	else
	{
		Over = false;
	}
}

void cButton::CheckDown(WORD mx, WORD my)
{
	if(mx > X && mx < X + Width
	&& my > Y && my < Y + Height)
	{
		Down = true;
	}
	
}


bool cButton::CheckUp(WORD mx, WORD my)
{
	if(mx > X && mx < X + Width
	&& my > Y && my < Y + Height)
	{
		if(Down == true)
		{
			Down = false;
			return true;
		}
	}
	Down = false;
	return false;
}

void cButton::Render()
{
	if(Down == true)
	{
		Img_over.Draw(X+8,Y+8,0,0,Width,Height,Width,Height);
		//Img_over.Draw(X+8,Y+8,0,0,Width,Height,Width,Height,RGB(255,0,255));
	}
	else if(Over == true)
	{ 
		Img_over.Draw(X,Y,0,0,Width,Height,Width,Height);
	}
	else
	{
		Img.AlphaDraw(X,Y,0,0,Width,Height,Width,Height,200);
		//Img.Draw(X,Y,0,0,Width,Height,Width,Height,RGB(255,0,255));
	}
}

void cButton::Destroy()
{
	Img.Destroy();       
	Img_over.Destroy();  
	Img_down.Destroy();	
}