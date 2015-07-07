// VolController.h: interface for the CVolController class.
// ������Ϣ��ȡ������
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VOLCONTROLLER_H__22FA0D6F_E9B8_48CF_AA93_A369AC22A5E2__INCLUDED_)
#define AFX_VOLCONTROLLER_H__22FA0D6F_E9B8_48CF_AA93_A369AC22A5E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <MMSystem.h>
#include <mmsystem.h>       // link with winmm.lib
#pragma  comment  (lib,  "winmm.lib")

enum MixerChannel{MainChannel = 0, LeftChannel, RightChannel};

class CVolController  
{
public:
	CVolController();
	virtual ~CVolController();

private:
	static BOOL	  m_mixerInited;        // ����������ǰ����ر����Ƿ񱻳�ʼ��
	static HMIXER m_hmx;                // ���������
	static DWORD  m_dwLineID;           // ����������LineID��Ϣ
	static UINT   m_nChannelCount;      // ������ͨ������
	static DWORD  m_dwVolumeControlID;  // ��������������ֵ��Control��ID
	static DWORD  m_dwMuteControlID;    // ���������þ�����Control��ID
	static LONG   m_lMinVlm;            // ��������С����ֵ
	static LONG   m_lMaxVlm;            // �������������ֵ

public:
    // �Ի��������в���ǰ,����������������йص����б����ĳ�ʼ��
    static BOOL InitializeMixer();
	// ��ȡ����������Сֵ�����ֵ
	static LONG GetVolumeRangMin();
	static LONG GetVolumeRangMax();
    // ��ȡ��ǰ������������ֵ
	static LONG GetVolumeValue(MixerChannel destChannel);
    // ���û�����������ֵ
	static BOOL SetVolumeValue(LONG lVlmVal);
	// ������������, bIsMuteΪ��ʱ����Ϊ����������ָ�����
	static BOOL SetChannelMute(MixerChannel destChannel, BOOL bIsMute);
	// �Ի��������п���������
	// bEnableΪTRUEʱ�����������Ӳ�����״̬����Ϊ����״̬(�������Ǿ���)����֮
	static void EnableLine(BOOL bEnable);
	// ��û������ľ���״̬������ʱ����TRUE����֮
	static BOOL DetectSilence(MixerChannel destChannel);

	
    // ������˷����������ֵ
	static BOOL SetMicrPhoneVolume(DWORD dwVolume);
	static BOOL GetMicrPhoneVolume(DWORD &dwVolume);
};

#endif // !defined(AFX_VOLCONTROLLER_H__22FA0D6F_E9B8_48CF_AA93_A369AC22A5E2__INCLUDED_)
