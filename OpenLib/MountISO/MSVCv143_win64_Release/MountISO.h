/*
* ////////////////////////////////////////////////
*
* 开发者：AZPEP
* 友情链接：
*	-	B站：		零分的考卷			https://space.bilibili.com/257391258
*	-	Github：	AZPEP-BiliBili		https://github.com/AZPEP-BiliBili
*	-	Gitee：		AZPEP_BiliBili		https://gitee.com/AZPEP_BiliBili
*
* CopyRight AZPEP
*
* ////////////////////////////////////////////////
*/

#pragma once
#pragma execution_character_set("utf-8")

//////////////////////////////////////////////////////////////
//			   编译库时使用的dll标头定义，请勿改动！
//////////////////////////////////////////////////////////////
#ifdef MOUNTISO_EXPORTS
#define MOUNTISO_API __declspec(dllexport)
#else
#define MOUNTISO_API __declspec(dllimport)
#endif

//////////////////////////////////////////////////
//					头文件引用
//////////////////////////////////////////////////
#include <Windows.h>
#include <string>

//////////////////////////////////////////////////
//					函数定义
//////////////////////////////////////////////////

/// <summary>
/// 挂载指定ISO文件，自动分配盘符
/// </summary>
/// <param name="IsoPath">ISO文件路径</param>
// <returns>成功返回0，失败返回GetLastError()得到的错误代码</returns>
EXTERN_C MOUNTISO_API DWORD MountISO_MountW(
	std::wstring IsoPath
);

/// <summary>
/// 挂载指定ISO文件，需手动分配盘符
/// </summary>
/// <param name="IsoPath">ISO文件路径</param>
/// <param name="Letter"></param>
/// <returns>成功返回0，失败返回GetLastError()得到的错误代码</returns>
EXTERN_C MOUNTISO_API DWORD MountISO_MountExW(
	std::wstring IsoPath, 
	WCHAR Letter
);

/// <summary>
/// 获取最后一次执行挂载操作时为ISO文件分配的盘符
/// </summary>
/// <returns>若最后一次使用MountISO_MountW或MountISO_MountExW成功时返回盘符，失败时则返回NULL</returns>
EXTERN_C MOUNTISO_API WCHAR MountISO_GetLastMountLetter();