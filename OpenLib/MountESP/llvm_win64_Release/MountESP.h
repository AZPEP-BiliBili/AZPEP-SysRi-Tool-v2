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

//////////////////////////////////////////////////
//					头文件引用
//////////////////////////////////////////////////
#include <Windows.h>
#include <string>
#include <vector>

//////////////////////////////////////////////////
//				  错误代码定义
//////////////////////////////////////////////////
#define ERROR_NO_MORE_AVAIABLE_LETTER	21000		//没有足够的盘符
#define ERROR_DRIVE_NOT_EXIST			21001		//指定的磁盘不存在

//////////////////////////////////////////////////
//					函数定义
//////////////////////////////////////////////////

/// <summary>
/// 挂载计算机上全部的EFI分区
/// </summary>
/// <param name="LetterList">指向存放挂载分区盘符的列表的指针，可为nullptr</param>
/// <param name="ReMountPartition">是否重新挂载，默认FALSE</param>
/// <returns>成功返回0，LetterList指向存放挂载分区盘符的列表的指针；没有足够的盘符返回ERROR_NO_MORE_AVAIABLE_LETTER，失败返回GetLastError()得到的错误代码；若返回代码为非零值，则LetterList为空</returns>
DWORD AstMountEsp_MountEfiPartitionW(
	_Out_ std::vector<WCHAR>* LetterList = nullptr,
	_In_ BOOL ReMountPartition = FALSE
);

/// <summary>
/// 挂载计算机指定磁盘上全部EFI分区
/// </summary>
/// <param name="DiskNumber">将要执行EFI分区挂载操作的磁盘号</param>
/// <param name="LetterList">指向存放挂载分区盘符的列表的指针，可为nullptr</param>
/// <param name="ReMountPartition">是否重新挂载，默认FALSE</param>
/// <returns>成功返回0，LetterList指向存放挂载分区盘符的列表的指针，磁盘不存在返回ERROR_DRIVE_NOT_EXIST，没有足够的盘符返回ERROR_NO_MORE_AVAIABLE_LETTER，失败返回GetLastError()得到的错误代码；若返回代码为非零值，则LetterList为空</returns>
DWORD AstMountEsp_MountEfiPartitionW(
	_In_ DWORD DiskNumber,
	_Out_ std::vector<WCHAR>* LetterList = nullptr,
	_In_ BOOL ReMountPartition = FALSE
);

/// <summary>
/// 卸载计算机上全部EFI分区，已经卸载的不会重复卸载
/// </summary>
/// <param name="LetterList">指向卸载的EFI分区盘符列表的指针，可为nullptr</param>
/// <returns>成功返回0，LetterList存储卸载的EFI分区盘符，失败返回GetLastError()返回的错误代码</returns>
DWORD AstMountEsp_UnMountEfiPartitionW(
	_Out_ std::vector<WCHAR>* LetterList = nullptr
);

/// <summary>
/// 卸载计算机指定磁盘上全部EFI分区，已经卸载的不会重复卸载
/// </summary>
/// <param name="DiskNumber">将要执行EFI分区卸载操作的磁盘号</param>
/// <param name="LetterList">指向卸载的EFI分区盘符列表的指针，可为nullptr</param>
/// <returns>成功返回0，LetterList存储卸载的EFI分区盘符，磁盘不存在返回ERROR_DRIVE_NOT_EXIST，失败返回GetLastError()返回的错误代码；若返回值为非零值则LetterList为空</returns>
DWORD AstMountEsp_UnMountEfiPartitionW(
	_In_ DWORD DiskNumber,
	_Out_ std::vector<WCHAR>* LetterList = nullptr
);
