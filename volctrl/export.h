#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include "FlashRuntimeExtensions.h"
#pragma comment(lib, "FlashRuntimeExtensions.lib")
/*  To use this exported function of dll, include this header
*  in your project.
*/

#define DLL_EXPORT __declspec(dllexport)
extern "C"
{
	//FREObject DLL_EXPORT get_volumn(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
	FREObject DLL_EXPORT myFunc1(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
	void DLL_EXPORT initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);
	void DLL_EXPORT finalizer(void* extData);

}

#endif // __MAIN_H__