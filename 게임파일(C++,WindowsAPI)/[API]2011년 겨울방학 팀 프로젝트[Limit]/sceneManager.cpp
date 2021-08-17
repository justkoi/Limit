#include "MY_include.h"


cSceneManager::cSceneManager()
{
	m_Scene			= NULL;
	m_CurFrame		= NULL;
	m_CurKey		= NULL;
	m_bFrameOnceCompleted = FALSE;
	m_FrameIdx		= 0;
	m_MaxImage		= 0;
	m_ImgList		= NULL;
}


cSceneManager::~cSceneManager()
{
	destroyFrameManager();
}





void cSceneManager::setDC(HDC memDC)
	{
		m_backDC = memDC;
	}
void cSceneManager::setImageNum(int ImageNum)
{
	m_MaxImage = ImageNum;
	m_ImgList = new cGdiImage[m_MaxImage];
}
void cSceneManager::setImage(int ImageIdx, char* ImgName)
{
	m_ImgList[ImageIdx].SetDC(m_backDC);
	m_ImgList[ImageIdx].Load(ImgName);
}
void cSceneManager::addScene(char* sceneName)
{
	cScene*		pScene = new cScene();
	m_Scene		= pScene;
	m_SceneList[sceneName] = pScene;
}
void cSceneManager::setMaxFrame(int maxFrame)
{
	m_Scene->setMaxFrame(maxFrame);
	m_FrameIdx = 0;
}
void cSceneManager::setMaxElementOfFrame(DWORD frameTime)
{
	m_Scene->setMaxElementOfFrame(m_FrameIdx, frameTime);
	m_ElementOfFrameIdx = m_FrameIdx;
	m_FrameIdx++;

}
void cSceneManager::addElementOfFrame(int imageIdx, int frameIntervalX, int frameIntervalY, int imageIntervalX, int imageIntervalY, int w, int h)
{
	m_Scene->addElementOfFrame(m_ElementOfFrameIdx,imageIdx,frameIntervalX, frameIntervalY, imageIntervalX,imageIntervalY,w,h);
}

void cSceneManager::setFirstFrame()
{
	m_CurFrame = 0;
	m_bFrameOnceCompleted = FALSE;
	m_OutFrameTime = GetTickCount();
}

void cSceneManager::setLastFrame()
{
	m_CurFrame = m_Scene->getMaxFrame() - 1;
	m_OutFrameTime = GetTickCount();
}
void cSceneManager::nextFrame()
{
	if(GetTickCount() - m_OutFrameTime < m_Scene->getFrameTime(m_CurFrame))
		return;

	m_CurFrame++;

	if(m_CurFrame >= m_Scene->getMaxFrame())
	{
		m_CurFrame = 0;
		m_bFrameOnceCompleted = TRUE;
	}
	m_OutFrameTime = GetTickCount();
}

void cSceneManager::setFrame(int frameIDX)
{
	if(frameIDX<0 || frameIDX > getMaxFrame()-1)
		return ;
	m_CurFrame = frameIDX;
}

void cSceneManager::setScene(char* sceneName)
{
	map<char*,cScene*>::iterator it;
	it = m_SceneList.find(sceneName);
	if(it == m_SceneList.end())
		return;
	else
	{
		m_CurKey = it->first;
		m_Scene = it->second;
		setFirstFrame();
	}


}

void cSceneManager::drawFrame(int x, int y)
{
	int imgNum;
	int sx,sy,iw,ih,ix,iy;

	imgNum = m_Scene->getImgNum(m_CurFrame);
	sx = m_Scene->getPosOffsetX(m_CurFrame) + x;
	sy = m_Scene->getPosOffsetX(m_CurFrame) + y;
	iw = m_Scene->getImgSizeX(m_CurFrame);
	ih = m_Scene->getImgSizeY(m_CurFrame);
	ix = m_Scene->getImgOffsetX(m_CurFrame);
	iy = m_Scene->getImgOffsetY(m_CurFrame);

	m_ImgList[imgNum].Draw(sx,sy,ix,iy,iw,ih);


}
	void cSceneManager::drawFrameRGB(int x, int y, UINT uRGB)
	{
		int imgNum;
	int sx,sy,iw,ih,ix,iy;
	
	imgNum = m_Scene->getImgNum(m_CurFrame);
	sx = m_Scene->getPosOffsetX(m_CurFrame) + x;
	sy = m_Scene->getPosOffsetX(m_CurFrame) + y;
	iw = m_Scene->getImgSizeX(m_CurFrame);
	ih = m_Scene->getImgSizeY(m_CurFrame);
	ix = m_Scene->getImgOffsetX(m_CurFrame);
	iy = m_Scene->getImgOffsetY(m_CurFrame);

	m_ImgList[imgNum].Draw(sx,sy,ix,iy,iw,ih,iw,ih, uRGB);
	}
	void cSceneManager::drawFrameAuto(int x, int y)
	{
		drawFrame(x,y);
		nextFrame();
	}
	void cSceneManager::drawFrameAutoRGB(int x, int y, UINT uRGB)
	{
		drawFrameRGB(x,y,uRGB);
		nextFrame();
	}


	void cSceneManager::delAllScene()
	{
		destroyFrameManager();
	}
	void cSceneManager::delScene(char* sceneName)
	{
		map<char*, cScene*>::iterator it;
		it = m_SceneList.find(sceneName);
		if(it == m_SceneList.end())
			return;
		else
		{
			delete it->second;
			m_SceneList.erase(it->first);
		}
	}

	void cSceneManager::delSceneElement(cScene* pScene)
	{
		pScene->destroyScene();
	}
	void cSceneManager::destroyFrameManager()
	{
		map<char*, cScene*>::iterator it;
		for(it = m_SceneList.begin(); it != m_SceneList.end(); it++)
		{
			delete it->second;
		}
		m_SceneList.clear();
		if(m_ImgList!=NULL)
			delete []m_ImgList;

		m_Scene = NULL;
		m_CurFrame = NULL;
		m_CurKey = NULL;
		m_bFrameOnceCompleted = FALSE;
		m_FrameIdx = 0;
		m_ElementOfFrameIdx = 0;
		m_MaxImage = 0;
	}

	int cSceneManager::getMaxFrame()
	{
		return m_Scene->getMaxFrame();
	}
	int cSceneManager::getCurFrame()
	{
		return m_CurFrame;
	}
	BOOL cSceneManager::getFrameOnce()
	{
		return m_bFrameOnceCompleted;
	}
	char* cSceneManager::getCurKey()
	{
		return m_CurKey;
	}
