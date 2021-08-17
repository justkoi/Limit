#ifndef __CGDIIMAGE_H__
#define __CGDIIMAGE_H__

#include "cGdiGraphics.h"

class cGdiImage
	
{
public:

	HDC	m_memDC;
	HDC m_hdcMem;		//�޸𸮵��
	HBITMAP m_hbmNew;	//��Ʈ���̹���
	HBITMAP m_hbmOld;	//�������̹���

	DWORD m_Width;	//�ȼ���
	DWORD m_Height;//�ȼ� ����


	BLENDFUNCTION bf;


public:
	cGdiImage(void):m_hdcMem(NULL),m_hbmNew(NULL),m_hbmOld(NULL)
	{
		//nothing
		//���İ�.����
		bf.BlendOp=AC_SRC_OVER;
		bf.BlendFlags =0;
		bf.SourceConstantAlpha=0;
		bf.AlphaFormat=0;
	}

	virtual ~cGdiImage(void)
	{
		this->Destroy();
	}

	void SetDC(HDC memDC)
	{
		m_memDC = memDC;
	}

	void Load(const char* fileName)
	{
		//���� ���ҽ� ����
		this->Destroy();

		m_hdcMem=::CreateCompatibleDC(m_memDC);

		m_hbmNew = (HBITMAP)::LoadImage(::GetModuleHandle(NULL),
		fileName,IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION|LR_LOADFROMFILE);

		m_hbmOld=(HBITMAP)::SelectObject(m_hdcMem,m_hbmNew);

		BITMAP bmp;
		::GetObject(m_hbmNew,sizeof(BITMAP),(LPVOID)&bmp);

		m_Width = bmp.bmWidth;
		m_Height=bmp.bmHeight;



	}


	void Destroy()
	{
		if(m_hbmNew)//��Ʈ�� ����
		{
			::SelectObject(m_hdcMem,m_hbmOld);
			::DeleteObject(m_hbmNew);m_hbmNew=NULL;
		}

		if(m_hdcMem)//�޸� ��� ����
		{
			::DeleteDC(m_hdcMem);m_hdcMem=NULL;

		}

	}

	void Draw(int x, int y)
	{
		::BitBlt(m_memDC,x,y,m_Width,m_Height,m_hdcMem,0,0,SRCCOPY);

	}

	void Draw(int dx, int dy, int sx, int sy)
	{
		::BitBlt(m_memDC,dx,dy,m_Width,m_Height,m_hdcMem,sx,sy,SRCCOPY);

	}

	void Draw(int dx,int dy, int sx, int sy, int sw, int sh)
	{
		::BitBlt(m_memDC,dx,dy,sw,sh,m_hdcMem,sx,sy,SRCCOPY);
	}

	void Draw(int dx, int dy, int sx, int sy, int sw, int sh, int iw, int ih)
	{
		::StretchBlt(m_memDC, dx,dy,sw,sh,m_hdcMem,sx,sy,iw,ih,SRCCOPY);
	}
	void Draw(int dx, int dy, int sx, int sy, int sw, int sh, int iw, int ih, UINT uRGB)
	{
		{
			::TransparentBlt(m_memDC,dx,dy,sw,sh,m_hdcMem,sx,sy,iw,ih,uRGB);
		}
	}

	void AlphaDraw(int dx, int dy, int sx, int sy,int sw, int sh, int iw,int ih, int alphaValue)
	{
		bf.SourceConstantAlpha= alphaValue;
		::AlphaBlend(m_memDC, dx,dy,sw,sh,m_hdcMem,sx,sy,iw,ih,bf);
	
	}
	private:
		cGdiImage(const  cGdiImage& rhs);
		cGdiImage& operator =(const cGdiImage& rhs);

	
};

#endif