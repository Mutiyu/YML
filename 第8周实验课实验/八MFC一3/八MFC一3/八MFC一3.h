
// ��MFCһ3.h : ��MFCһ3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��MFCһ3App:
// �йش����ʵ�֣������ ��MFCһ3.cpp
//

class C��MFCһ3App : public CWinAppEx
{
public:
	C��MFCһ3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��MFCһ3App theApp;
