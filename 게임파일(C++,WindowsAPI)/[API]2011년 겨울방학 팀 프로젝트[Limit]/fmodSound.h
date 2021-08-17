#pragma once



#include <fmod.hpp>
#include <fmod_errors.h>
#pragma comment (lib,"fmodex_vc.lib")

	
class fSound
{
	FMOD::System * systemS;
	FMOD::Channel * channel;
	FMOD::Sound * sound;
	
public:
	bool Played;
	DWORD lastPlayTime;
	fSound()
	{
		systemS = NULL;
		sound = NULL;
		channel = NULL;
		Played = false;
	}
	~fSound()
	{

	}
	void ERRCHECK(FMOD_RESULT result)
	{
		if(result != FMOD_OK)
		{
			char str[256];
			sprintf(str,"FMOD error! (%d) %s\n",result,FMOD_ErrorString(result));
			MessageBox(NULL,str,"TEST",MB_OK);
		}
	}

	void Update()
	{
		systemS->update();
	}
	void SoundLoad(char* fileName,bool loop)
	{
		FMOD_RESULT result;
		result = FMOD::System_Create(&systemS);
		ERRCHECK(result);
		result = systemS->init(1,FMOD_INIT_NORMAL,0);
		ERRCHECK(result);
		if(loop == false)
			result = systemS->createSound(fileName,FMOD_DEFAULT,0,&sound);
		else
			result = systemS->createSound(fileName,FMOD_LOOP_NORMAL,0,&sound);
		ERRCHECK(result);
	}

	void PLAYSound()
	{
		FMOD_RESULT result;
		result = systemS->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
		channel->setVolume(1.0f);
		ERRCHECK(result);
		Played = true;
		lastPlayTime = GetTickCount();
	}
	void DeleteSound()
	{
		if(sound) sound->release();
		if(systemS) systemS->release();
	}

	void StopSound(bool paused)
	{
		if(channel != NULL)
		{
			channel->setPaused(paused);
		}
	}
	void CheckPlayed(int ResetTime)
	{
		if(GetTickCount() - lastPlayTime >= ResetTime)
		{
			if(Played == true)
			{
				Played = false;
			}
		}
	}
protected:

private:

};