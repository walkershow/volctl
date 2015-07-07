#include "MixerWrap.h"
#include "VolController.h"
#define  WIN_XP    2
#define  WIN_2003  3
#define  WIN_VISTA 4
#define  WIN_7     5
#define  WIN_2008  6
#define  WIN_8     8

#pragma warning(disable: 4996)  

int GetOSVer()  
{  
	OSVERSIONINFO   osver;     
	osver.dwOSVersionInfoSize   =   sizeof(OSVERSIONINFO);     
	GetVersionEx(&osver);     
	if(osver.dwPlatformId == 2)  
	{  
		if(osver.dwMajorVersion == 5 && osver.dwMinorVersion == 1)   //xp
		{  
			return WIN_XP;  
		}  
		if(osver.dwMajorVersion == 5 && osver.dwMinorVersion == 2)  //2003
		{  
			return WIN_2003;  
		}  
		if(osver.dwMajorVersion ==  6 && (osver.dwMinorVersion == 0 || osver.dwMinorVersion == 1))  //vista or 2008
		{  
			return WIN_VISTA;  
		}  
		if(osver.dwMajorVersion ==  6 && osver.dwMinorVersion == 1 )  //win7
		{  
			return WIN_7;  
		}  
		if(osver.dwMajorVersion ==  6 && osver.dwMinorVersion == 2)  //win8
		{  
			return WIN_8;  
		}  
	}  
	return 0;  
} 

void InitMediaDevice()
{
	if( GetOSVer() == WIN_XP)
	{
		CVolController::InitializeMixer();
	}
}

void GetSystemVolume(float &dVolumeValue) //��ȡ��������ֵ
{
	if( GetOSVer() == WIN_XP)
	{
		LONG max =CVolController::GetVolumeRangMax();
		LONG lValue=CVolController::GetVolumeValue(MainChannel);
		dVolumeValue = lValue * 100 / max;
	}
	else if(GetOSVer() == WIN_7|| GetOSVer() == WIN_8 || GetOSVer() == WIN_VISTA)
	{
		MixerWrap::GetSpeakerValue_W7(dVolumeValue); 
	}
}

void SetSystemVolume(DWORD dVolumeValue) //������������ֵ
{
	if( GetOSVer() == WIN_XP)
	{
		LONG min =CVolController::GetVolumeRangMin();
		LONG max =CVolController::GetVolumeRangMax();
		CVolController::SetVolumeValue((max-min)*dVolumeValue/100);
	}
	else if(GetOSVer() == WIN_7|| GetOSVer() == WIN_8 || GetOSVer() == WIN_VISTA)
	{
		MixerWrap::SetSpeakerValue_W7(dVolumeValue);
	}
}

bool SetSpeakerMute(bool bMute) //������������ֵ
{
	//printf("os is:%d\r\n", GetOSVer());
	if (GetOSVer() == WIN_XP)
	{
		LONG min = CVolController::GetVolumeRangMin();
		LONG max = CVolController::GetVolumeRangMax();
		return CVolController::SetChannelMute(MainChannel, bMute);
	}
	else if (GetOSVer() == WIN_7 || GetOSVer() == WIN_8 || GetOSVer() == WIN_VISTA)
	{
		float vol;
		GetSystemVolume(vol);
		//printf("GetSystemVolume:%f\r\n", vol);
		return MixerWrap::MutSpeaker_W7(bMute, vol);
	}
}

void GetMicrophoneValue(DWORD &dMicorphoneValue) //��ȡ��˷�����
{
	if( GetOSVer() == WIN_XP)
	{
		CVolController::GetMicrPhoneVolume(dMicorphoneValue);
	}
	else if(GetOSVer() == WIN_7|| GetOSVer() == WIN_8 || GetOSVer() == WIN_VISTA)
	{
		MixerWrap::GetMicphone_W7(dMicorphoneValue);
	}
}

void SetMicrophoneValue(DWORD dMicorphoneValue) //������˷�����
{
	if( GetOSVer() == WIN_XP)
	{
		CVolController::SetMicrPhoneVolume(dMicorphoneValue);
	}
	else if(GetOSVer() == WIN_7|| GetOSVer() == WIN_8 || GetOSVer() == WIN_VISTA)
	{
		MixerWrap::MicphoneMut_W7(false, dMicorphoneValue);
	}
}

void SetMicrophoneMute(bool bIsMut) //������˷�����
{
	if (GetOSVer() == WIN_XP)
	{
		CVolController::SetMicrPhoneVolume(0);
	}
	else if (GetOSVer() == WIN_7 || GetOSVer() == WIN_8 || GetOSVer() == WIN_VISTA)
	{
		DWORD d;
		GetMicrophoneValue(d);
		MixerWrap::MicphoneMut_W7(bIsMut, d);
	}
}
bool GetMicroBoostData(float &fMin, float &fMax, float &fStep) //��ȡ��˷���ǿ�ȼ�����Сֵ�����ֵ������
{
	if(GetOSVer() == WIN_7|| GetOSVer() == WIN_8 || GetOSVer() == WIN_VISTA)
	{
		MixerWrap::GetMicphoneLevelData(fMin, fMax,fStep);
		return true;
	}
	return false;
}

bool GetMicroBoostLevel(float &dMicroBoostLevel) //��ȡ��˷���ǿ�ȼ�
{
	if(GetOSVer() == WIN_7|| GetOSVer() == WIN_8 || GetOSVer() == WIN_VISTA)
	{
		MixerWrap::GetMicphoneLevel(dMicroBoostLevel);
		return true;
	}
	return false;
}

void SetMicroBoostLevel(float dMicroBoostLevel) //������˷���ǿ�ȼ�
{
	if(GetOSVer() == WIN_7|| GetOSVer() == WIN_8 || GetOSVer() == WIN_VISTA)
	{
		MixerWrap::MicphoneBoost_W7(dMicroBoostLevel);
	}
}