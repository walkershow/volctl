// volctrl.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//int _tmain(int argc, _TCHAR* argv[])
//{
//	CMixer *pmix = new CMixer(100);
//	bool bMute = pmix->GetMute(CMixer::MixerDeice::SPEAKERS);
//	bool bRet = pmix->SetMute(CMixer::MixerDeice::SPEAKERS, 1);
//	bMute = pmix->GetMute(CMixer::MixerDeice::SPEAKERS);
//	return 0;
//}

#include"FlashRuntimeExtensions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "export.h"
#include "mixer.h"

extern "C"
{
// 	FREObject get_volumn(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
// 	{
// 
// 		const uint8_t *str = 0;
// 		uint32_t vol;
// 		const char *a = NULL;
// 
// 		int32_t dev;
// 		FREGetObjectAsInt32(argv[0], &dev);
// 		CMixer mix(100);
// 		vol = mix.GetVolume((CMixer::MixerDeice)0);
// 
// 		FREObject freObj = NULL;
// 		FRENewObjectFromUint32(vol, &freObj);
// 		return freObj;
// 	}
	char* UTF8ToGBK(const char* strUtf8)
	{
		int len = MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)strUtf8, -1, NULL, 0);
		unsigned short * wszGBK = new unsigned short[len + 1];
		memset(wszGBK, 0, len * 2 + 2);
		MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)strUtf8, -1, (LPWSTR)wszGBK, len);
		len = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wszGBK, -1, NULL, 0, NULL, NULL);
		char *szGBK = new char[len + 1];
		memset(szGBK, 0, len + 1);
		WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wszGBK, -1, (LPSTR)szGBK, len, NULL, NULL);
		return szGBK;
	}

	char* GBKToUTF8(const char* strGBK)
	{
		int len = MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)strGBK, -1, NULL, 0);
		unsigned short * wszUtf8 = new unsigned short[len + 1];
		memset(wszUtf8, 0, len * 2 + 2);
		MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)strGBK, -1, (LPWSTR)wszUtf8, len);
		len = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)wszUtf8, -1, NULL, 0, NULL, NULL);
		char *szUtf8 = new char[len + 1];
		memset(szUtf8, 0, len + 1);
		WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)wszUtf8, -1, (LPSTR)szUtf8, len, NULL, NULL);
		return szUtf8;
	}

	FREObject myFunc1(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
			FREObject freObj = NULL;
			uint32_t vol = 100;
			FRENewObjectFromUint32(vol, &freObj);
			return freObj;
	}

	void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions)
	{
		*numFunctions = 1;

		FRENamedFunction* func = (FRENamedFunction*)malloc(sizeof(FRENamedFunction)* (*numFunctions));

		func[0].name = (const uint8_t*) "myFunc1";
		func[0].functionData = NULL;
		func[0].function = &myFunc1;

		*functions = func;
	}

	void contextFinalizer(FREContext ctx)
	{
		return;
	}

	void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer)
	{
		*ctxInitializer = &contextInitializer;
		*ctxFinalizer = &contextFinalizer;
	}

	void finalizer(void* extData)
	{
		return;
	}
}
