#pragma once

#include <Windows.h>

class cFrame
{
private:
	int	m_ImgNum;
	int m_ImgWidth;
	int m_ImgHeight;
	int m_PosOffsetX;
	int m_PosOffsetY;
	int m_ImgOffsetX;
	int m_ImgOffsetY;

public:
	cFrame();
	~cFrame();

	void setImgNum(int imgNum);
	void setImgSize(int width, int height);
	void setPosOffset(int xValue, int yValue);
	void setImgOffset(int xValue, int yValue);


	int getImgNum();
	int getImgSizeX();
	int getImgSizeY();
	int getPosOffsetX();
	int getPosOffsetY();
	int getImgOffsetX();
	int getImgOffsetY();
	
};