/*
* ////////////////////////////////////////////////
*
* �����ߣ�AZPEP
* �������ӣ�
*	-	Bվ��		��ֵĿ���			https://space.bilibili.com/257391258
*	-	Github��	AZPEP-BiliBili		https://github.com/AZPEP-BiliBili
*	-	Gitee��		AZPEP_BiliBili		https://gitee.com/AZPEP_BiliBili
*
* CopyRight AZPEP
*
* ////////////////////////////////////////////////
*/

#pragma once
#pragma execution_character_set("utf-8")

//////////////////////////////////////////////////////////////
//			   �����ʱʹ�õ�dll��ͷ���壬����Ķ���
//////////////////////////////////////////////////////////////
#ifdef MOUNTISO_EXPORTS
#define MOUNTISO_API __declspec(dllexport)
#else
#define MOUNTISO_API __declspec(dllimport)
#endif

//////////////////////////////////////////////////
//					ͷ�ļ�����
//////////////////////////////////////////////////
#include <Windows.h>
#include <string>

//////////////////////////////////////////////////
//					��������
//////////////////////////////////////////////////

/// <summary>
/// ����ָ��ISO�ļ����Զ������̷�
/// </summary>
/// <param name="IsoPath">ISO�ļ�·��</param>
// <returns>�ɹ�����0��ʧ�ܷ���GetLastError()�õ��Ĵ������</returns>
EXTERN_C MOUNTISO_API DWORD MountISO_MountW(
	std::wstring IsoPath
);

/// <summary>
/// ����ָ��ISO�ļ������ֶ������̷�
/// </summary>
/// <param name="IsoPath">ISO�ļ�·��</param>
/// <param name="Letter"></param>
/// <returns>�ɹ�����0��ʧ�ܷ���GetLastError()�õ��Ĵ������</returns>
EXTERN_C MOUNTISO_API DWORD MountISO_MountExW(
	std::wstring IsoPath, 
	WCHAR Letter
);

/// <summary>
/// ��ȡ���һ��ִ�й��ز���ʱΪISO�ļ�������̷�
/// </summary>
/// <returns>�����һ��ʹ��MountISO_MountW��MountISO_MountExW�ɹ�ʱ�����̷���ʧ��ʱ�򷵻�NULL</returns>
EXTERN_C MOUNTISO_API WCHAR MountISO_GetLastMountLetter();