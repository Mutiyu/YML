// win32D.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "win32D.h"


// ���ǵ���������һ��ʾ��
WIN32D_API int nwin32D=0;

// ���ǵ���������һ��ʾ����
WIN32D_API int fnwin32D(void)
{
    return 42;
}

WIN32D_API int GetInt()
{
	return 2020;
}
// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� win32D.h
Cwin32D::Cwin32D()
{
    return;
}
