
// ��MFCpractise1.h : ��MFCpractise1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��MFCpractise1App:
// �йش����ʵ�֣������ ��MFCpractise1.cpp
//

class C��MFCpractise1App : public CWinAppEx
{
public:
	C��MFCpractise1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��MFCpractise1App theApp;
