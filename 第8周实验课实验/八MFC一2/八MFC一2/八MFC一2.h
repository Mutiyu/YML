
// ��MFCһ2.h : ��MFCһ2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��MFCһ2App:
// �йش����ʵ�֣������ ��MFCһ2.cpp
//

class C��MFCһ2App : public CWinAppEx
{
public:
	C��MFCһ2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��MFCһ2App theApp;
