#pragma once
#include <Windows.h>
#define MAX_VOL 100


class MixerWrap
{
public:
	MixerWrap(void){};
public:
	virtual ~MixerWrap(void){};

	static void MicphoneBoost(bool bIsBoost);
	
	static void MicphoneMut(bool bIsMut);
	static void StereoMix(bool bIsMix);
	static bool MicphoneMut_W7(bool bIsMut,float fVolume); //设置麦克风音量
	static int  GetMicphone_W7(DWORD &pdwVolume); //获取麦克风音量
	static void MicphoneBoost_W7(float fValue);//设置麦克风增强等级
	static void GetMicphoneLevel(float &fValue); //获取麦克风增强等级
	static void GetMicphoneLevelData(float &nMin, float &nMax, float &nStep); //获取麦克风最小值，最大值和增量
	static bool GetSpeakerValue_W7(float &fVolume); //获取喇叭音量
	static bool SetSpeakerValue_W7(float fVolume); //设置喇叭音量

		
	static bool MutSpeaker_W7(bool bMute,float fVolume);

	//立体声混音音量调节
	static void StereoMixVolume(int nVolume);	
	static void OutPutMicphoneVolume(int nVolume);
	static void InPutMicphoneVolume(int nVolume);


	static int  SelectRecordIn(DWORD  dwSrcType);
	static int  SelectRecordInByName(WCHAR*  szSrcName);

	

};
