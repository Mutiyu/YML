// Win32Dll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Win32Dll.h"


// ���ǵ���������һ��ʾ��
WIN32DLL_API int nWin32Dll=0;

// ���ǵ���������һ��ʾ����
WIN32DLL_API int fnWin32Dll(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Win32Dll.h
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