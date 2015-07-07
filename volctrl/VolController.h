// VolController.h: interface for the CVolController class.
// 音量信息读取与设置
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
	static BOOL	  m_mixerInited;        // 混音器控制前，相关变量是否被初始化
	static HMIXER m_hmx;                // 混音器句柄
	static DWORD  m_dwLineID;           // 混音器音量LineID信息
	static UINT   m_nChannelCount;      // 混音器通道数量
	static DWORD  m_dwVolumeControlID;  // 混音器设置音量值的Control的ID
	static DWORD  m_dwMuteControlID;    // 混音器设置静音的Control的ID
	static LONG   m_lMinVlm;            // 混音器最小音量值
	static LONG   m_lMaxVlm;            // 混音器最大音量值

public:
    // 对混音器进行操作前,进行与混音器设置有关的所有变量的初始化
    static BOOL InitializeMixer();
	// 获取混音器的最小值和最大值
	static LONG GetVolumeRangMin();
	static LONG GetVolumeRangMax();
    // 获取当前混音器的音量值
	static LONG GetVolumeValue(MixerChannel destChannel);
    // 设置混音器的音量值
	static BOOL SetVolumeValue(LONG lVlmVal);
	// 设置声道静音, bIsMute为真时设置为静音，否则恢复声音
	static BOOL SetChannelMute(MixerChannel destChannel, BOOL bIsMute);
	// 对混音器进行可用性设置
	// bEnable为TRUE时，将混音器从不可用状态设置为可用状态(静音到非静音)，反之
	static void EnableLine(BOOL bEnable);
	// 获得混音器的静音状态。静音时返回TRUE，反之
	static BOOL DetectSilence(MixerChannel destChannel);

	
    // 设置麦克风的输入音量值
	static BOOL SetMicrPhoneVolume(DWORD dwVolume);
	static BOOL GetMicrPhoneVolume(DWORD &dwVolume);
};

#endif // !defined(AFX_VOLCONTROLLER_H__22FA0D6F_E9B8_48CF_AA93_A369AC22A5E2__INCLUDED_)
