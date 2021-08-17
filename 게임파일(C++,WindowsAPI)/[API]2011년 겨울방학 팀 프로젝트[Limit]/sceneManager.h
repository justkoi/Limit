#pragma once

#include "scene.h"
#include "cGdiGraphics.h"
#include <string>
#include <map>

using namespace std;

class cSceneManager
{
	HDC			m_backDC;
	cGdiImage*	m_ImgList;					//사용될 이미지 리스트
	int			m_MaxImage;					//사용될 이미지 갯수
	map<char*, cScene*> m_SceneList;
	cScene*		m_Scene;
	int			m_CurFrame;
	char*		m_CurKey;
	
	DWORD		m_OutFrameTime;

	int			m_FrameIdx;
	int			m_ElementOfFrameIdx;

public:
	BOOL		m_bFrameOnceCompleted;
	cSceneManager();
	~cSceneManager();

	void setDC(HDC memDC);
	void setImageNum(int ImageNum);
	void setImage(int ImageIdx, char* ImgName);
	void addScene(char* sceneName);
	void setMaxFrame(int maxFrame);
	void setMaxElementOfFrame(DWORD frameTime);
	void addElementOfFrame(int imageIdx, int frameIntervalX, int frameIntervalY, int imageIntervalX, int imageIntervalY, int w, int h);

	void setFirstFrame();
	void setLastFrame();
	void nextFrame();
	void setFrame(int frameIDX);

	void setScene(char* sceneName);
	void drawFrame(int x, int y);
	void drawFrameRGB(int x, int y, UINT uRGB);
	void drawFrameAuto(int x, int y);
	void drawFrameAutoRGB(int x, int y, UINT uRGB);


	void delAllScene();
	void delScene(char* sceneName);
	void delSceneElement(cScene* pScene);
	void destroyFrameManager();

	int getMaxFrame();
	int getCurFrame();
	BOOL getFrameOnce();
	char* getCurKey();

};