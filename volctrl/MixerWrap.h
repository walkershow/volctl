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
	static bool MicphoneMut_W7(bool bIsMut,float fVolume); //������˷�����
	static int  GetMicphone_W7(DWORD &pdwVolume); //��ȡ��˷�����
	static void MicphoneBoost_W7(float fValue);//������˷���ǿ�ȼ�
	static void GetMicphoneLevel(float &fValue); //��ȡ��˷���ǿ�ȼ�
	static void GetMicphoneLevelData(float &nMin, float &nMax, float &nStep); //��ȡ��˷���Сֵ�����ֵ������
	static bool GetSpeakerValue_W7(float &fVolume); //��ȡ��������
	static bool SetSpeakerValue_W7(float fVolume); //������������

		
	static bool MutSpeaker_W7(bool bMute,float fVolume);

	//������������������
	static void StereoMixVolume(int nVolume);	
	static void OutPutMicphoneVolume(int nVolume);
	static void InPutMicphoneVolume(int nVolume);


	static int  SelectRecordIn(DWORD  dwSrcType);
	static int  SelectRecordInByName(WCHAR*  szSrcName);

	

};
