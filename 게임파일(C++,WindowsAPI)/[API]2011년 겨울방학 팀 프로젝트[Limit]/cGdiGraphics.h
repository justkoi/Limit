

#ifndef __CGDIGRAPHICS_H__
#define __CGDIGRAPHICS_H__

class cGdiGraphics
{
private:
	HWND  m_hWnd;
	HDC   m_hdcMain;

	HDC   m_hdcBack;
	HBITMAP  m_hNewBitmap;
	HBITMAP  m_hOldBitmap;


	bool  m_bFullScreen;

	HFONT  m_hOldFont;
	HFONT  m_hNewFont12;
	HFONT  m_hNewFont16;

	HBRUSH  m_hOldBrush;

public:
	
	int   m_ScreenSizeX;
	int   m_ScreenSizeY;
	cGdiGraphics(void): m_hWnd(NULL)
		, m_hdcMain(NULL)
		, m_hdcBack(NULL)
		, m_hOldBitmap(NULL)
		, m_hNewBitmap(NULL)
		, m_ScreenSizeX(0)
		, m_ScreenSizeY(0)
		, m_bFullScreen(false)
	{
		this->InitiateFonts();
	}

	virtual ~cGdiGraphics(void)
	{
		this->FinalizeFonts();
	}

	HDC getGraphicsDC()
	{
		return m_hdcBack;
	}

	void Create(HWND hWnd, bool fullScreen = false)
	{
		m_bFullScreen = fullScreen;

		m_hWnd  = hWnd;
		m_hdcMain = ::GetDC(m_hWnd);
		m_hdcBack = ::CreateCompatibleDC(m_hdcMain);

		RECT rect;
		::GetClientRect(m_hWnd, &rect);
		m_ScreenSizeX = rect.right;
		m_ScreenSizeY = rect.bottom;

		m_hNewBitmap = ::CreateCompatibleBitmap(m_hdcMain, m_ScreenSizeX, m_ScreenSizeY);
		m_hOldBitmap = (HBITMAP)::SelectObject(m_hdcBack, m_hNewBitmap);

		m_hOldFont  = (HFONT)::SelectObject(m_hdcBack, m_hNewFont12);
		this->SetTextTransparent();
		this->SetTextColor(RGB(255,255,255));

		m_hOldBrush  = (HBRUSH)::SelectObject(m_hdcBack, GetStockObject(HOLLOW_BRUSH));

		if(TRUE == m_bFullScreen) // ���÷��� ����
		{
			DEVMODE deviceMode;
			ZeroMemory( &deviceMode, sizeof(deviceMode));

			int i;

			deviceMode.dmSize = sizeof(DEVMODE);
			deviceMode.dmFields = DM_PELSWIDTH + DM_PELSHEIGHT + DM_BITSPERPEL;

			deviceMode.dmPelsWidth  = m_ScreenSizeX;
			deviceMode.dmPelsHeight = m_ScreenSizeY;
			deviceMode.dmBitsPerPel = 32;

			if((i = ChangeDisplaySettings(&deviceMode, 0)) != DISP_CHANGE_SUCCESSFUL)
			{
				m_bFullScreen = false;
				return;

			}
			LONG style;
			style = WS_POPUP;
			::SetWindowLong( m_hWnd, GWL_STYLE, style);

			RECT windowRect;
			windowRect.top	=	0;
			windowRect.left		=	0;
			windowRect.right	=	m_ScreenSizeX;
			windowRect.bottom = m_ScreenSizeY;
			::AdjustWindowRectEx( &windowRect, WS_POPUP, FALSE, WS_EX_TOPMOST);

			::MoveWindow( m_hWnd, 0, 0, windowRect.right, windowRect.bottom, FALSE);
			::ShowWindow( m_hWnd, SW_SHOW);

			::ClipCursor( &windowRect);		// Ŀ�����α�
		}
	}

	void Destroy( )
	{
		if( true == m_bFullScreen)
		{
			::ClipCursor(NULL);		// Ŀ�����α� ����
			::ChangeDisplaySettings( NULL, 0);	// ���÷��� ȸ�� 
		}

		::SelectObject( m_hdcBack, m_hOldFont);

		::SelectObject( m_hdcBack, m_hOldBitmap);
		::DeleteObject( m_hNewBitmap);

		::DeleteDC( m_hdcBack);
		::ReleaseDC( m_hWnd, m_hdcMain);
		m_hWnd = NULL;
	}

	void ClearWhite( )
	{
		::BitBlt( m_hdcBack,
			0, 0, m_ScreenSizeX, m_ScreenSizeY,
			NULL,
			0, 0,
			WHITENESS);
	}

	void ClearBlack( )
	{
		::BitBlt( m_hdcBack,
			0, 0, m_ScreenSizeX, m_ScreenSizeY,
			NULL,
			0, 0,
			BLACKNESS);
	}

	void Present( )
	{
		::BitBlt( m_hdcMain,
			0, 0, m_ScreenSizeX, m_ScreenSizeY,
			m_hdcBack,
			0, 0,
			SRCCOPY);
	}

	void SetTextTransparent( )
	{
		::SetBkMode( m_hdcBack, TRANSPARENT);
	}

	void SetTextOpaque( )
	{
		SetBkMode( m_hdcBack, OPAQUE);
	}

	void SetTextColor( COLORREF color )
	{
		::SetTextColor( m_hdcBack, color);
	}
	void SetFontBig( )
	{
		if(m_hdcBack)
		{
			SelectObject(m_hdcBack, m_hNewFont16);
		}
	}
	void SetFontSmall( )
	{
		if( m_hdcBack)
		{
			SelectObject( m_hdcBack, m_hNewFont12);
		}
	}

	void DrawString( int x, int y, char* msg)
	{
		::TextOut( m_hdcBack, x, y, msg, strlen(msg));
	}

	void DrawDot( int x, int y)
	{
		::SetPixel( m_hdcBack, x, y, RGB( 255, 0, 255));
	}

	void DrawLine( int sx, int sy, int ex, int ey)
	{
		::MoveToEx( m_hdcBack, sx, sy, NULL);
		::LineTo( m_hdcBack, ex, ey);
	}

	void DrawRect( int x, int y, int w, int h)
	{
		::Rectangle( m_hdcBack, x, y, x+w, y+h);
	}

	void DrawCircle( int cx, int cy, int radius)
	{
		::Ellipse(m_hdcBack, 
			cx - radius,
			cy - radius, 
			cx + radius,
			cy + radius );
	}

protected:
	void InitiateFonts( )
	{
		LOGFONT lf ;
		ZeroMemory( &lf, sizeof(lf));

		lf.lfCharSet = DEFAULT_CHARSET;
		strcpy( lf.lfFaceName, "����");
		lf.lfHeight = 12;
		lf.lfWeight = 600;
		m_hNewFont12 = ::CreateFontIndirect( &lf);

		lf.lfHeight = 16;
		lf.lfWeight = 700;
		m_hNewFont12 = ::CreateFontIndirect( &lf);
	}

	void FinalizeFonts( )
	{
		::DeleteObject( m_hNewFont16);
		::DeleteObject( m_hNewFont12);
	}

	void InitiatePens( )
	{

	}

	void FinalizePens( )
	{

	}

	void InitiateBrushes( )
	{

	}

	void FinalizeBrushes( )
	{

	}

private:
	cGdiGraphics(const cGdiGraphics& rhs);
	cGdiGraphics& operator=(const cGdiGraphics& rhs);
};

extern cGdiGraphics g_Graphics;

#endif
