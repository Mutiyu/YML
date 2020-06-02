// Win32Dll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Win32Dll.h"


// 这是导出变量的一个示例
WIN32DLL_API int nWin32Dll=0;

// 这是导出函数的一个示例。
WIN32DLL_API int fnWin32Dll(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 Win32Dll.h
CWin32Dll::CWin32Dll()
{
    return;
}
WIN32DLL_API int factorialDll(int n)
{
	int a = 1;
	for (int i = 1; i <= n; i++)
	{
		a = a*i;
	}
	return a;
}
float FACDll::convertDll(float deg)
{
	return deg*0.01745;
}