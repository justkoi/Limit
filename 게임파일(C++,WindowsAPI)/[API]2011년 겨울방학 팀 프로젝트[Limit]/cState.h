#pragma once

class cState
{
public:
	cState(){}
	virtual ~cState(){}

	virtual void InitState() = 0;
	virtual void Update(float fElapsedTime) = 0;
	virtual void Render() = 0;
	virtual int  Destroy() = 0;
	virtual LRESULT MsgProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) = 0;

};