
// ��MFCpractise2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��MFCpractise2App: 
// �йش����ʵ�֣������ ��MFCpractise2.cpp
//

class C��MFCpractise2App : public CWinApp
{
public:
	C��MFCpractise2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��MFCpractise2App theApp;