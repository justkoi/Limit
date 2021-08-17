#include "My_include.h"
#include <stdlib.h>
#include <time.h>

#include "cIAngle.h"
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

HINSTANCE g_hlnst;
//
//extern FMOD::System * systemS;
//extern FMOD::Channel * channel;

LPCTSTR lpszClass=TEXT("First");

HWND					g_hWnd;
cGdiGraphics			g_Graphics;
cGdiImage				g_Image;
cStateManager			g_Game;
cIAngle					g_Angle;
char strTemp[256];

bool KeyDownState[4]={false,false,false,false};



//EJq���ҷ� �Ķ��� �������� �����Ķ��� ��������

int APIENTRY WinMain(HINSTANCE hlnstance,HINSTANCE hPrevlnstance
					 ,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hlnst=hlnstance;

	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);		//�����ܺο�
	WndClass.hInstance=hlnstance;			//�θ� ���� �ڱⰡ ��������� �� ����Ȱ�����
	WndClass.lpfnWndProc=WndProc;
	WndClass.lpszClassName=lpszClass;
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW|CS_VREDRAW;
	RegisterClass(&WndClass);
	//���� 800,x600
	hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,SCR_WIDTH,SCR_HEIGHT,
	NULL,(HMENU)NULL,hlnstance,NULL);
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	g_Graphics.Create(hWnd);
	
	g_Image.SetDC(g_Graphics.getGraphicsDC());	//�̹��� �ϳ� �پ������ ./data/1925.bmp");
	g_Image.Load("./data/1945.bmp");
	g_hWnd=hWnd;

	ZeroMemory(&Message,sizeof(Message));

	srand(time(NULL));
	int frameCount =0;
	int frameTime  =0;
	int frameTimeLast=0;		//�ѽ���ɴ� �� �������� ���ư��µ����� �ð� �������� ���� 
	int FPS =0;
	float dt =0.0f;
	RECT rect;
	char strTemp[256];
	while(Message.message!=WM_QUIT)
	{
		::GetClientRect(hWnd,&rect);

		
		++frameCount;
		frameTime = GetTickCount();

		dt = ((frameTime-frameTimeLast)/1000.0f);		//�����ð��� �������ð��� ���� �ɸ� �ð��� ���� 

		if(dt>=0.5)
		{
			FPS = frameCount;
			//if(FPS > 50)
			//	FPS = 50;
			frameCount =0;
			frameTimeLast= frameTime;
		}

		g_Graphics.ClearBlack();			//������ ?
		
		if(PeekMessage(&Message,NULL,0,0,PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		
		g_Game.GameFC((float)FPS);
		//g_Game.setInnerState(DESTROY);
		sprintf(strTemp,"[FPS]: %.2f",float(FPS*2));
		g_Graphics.DrawString(0,0,strTemp);
		g_Graphics.Present();
		Sleep(6);

	}

	return Message.wParam;
}
//
//	while (GetMessage(&Message,NULL,0,0))		//�޼���ť  ���� ������ ���������� Ǯ�� ť�� �Ʒ�������
//	{
//		TranslateMessage(&Message);
//		DispatchMessage(&Message);
//	}
//	return (int)Message.wParam;
//
//}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM IParam)
	{
	if(g_Game.m_State != NULL)
			return (g_Game.m_State)->MsgProc(hWnd,iMessage,wParam,IParam);

	else
			return (DefWindowProc(hWnd,iMessage,wParam,IParam));

	//cGdiImage g_Image;
	switch (iMessage) {
	case MM_MCINOTIFY:
		switch(wParam)
		{
			
		case MCI_NOTIFY_SUCCESSFUL:
		case MCI_NOTIFY_FAILURE:
		case MCI_NOTIFY_SUPERSEDED:
		case MCI_NOTIFY_ABORTED:
			//g_Sound.playRepet();
			break;
		}
		case WM_DESTROY:
	PostQuitMessage(0);
	return 0;
	}
}

//}
//return (DefWindowProc(hWnd,iMessage,wParam,IParam));
//}