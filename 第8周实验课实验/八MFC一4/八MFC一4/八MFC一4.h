
// ��MFCһ4.h : ��MFCһ4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��MFCһ4App:
// �йش����ʵ�֣������ ��MFCһ4.cpp
//

class C��MFCһ4App : public CWinAppEx
{
public:
	C��MFCһ4App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��MFCһ4App theApp;
