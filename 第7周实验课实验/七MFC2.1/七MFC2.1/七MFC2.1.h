
// ��MFC2.1.h : ��MFC2.1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��MFC21App:
// �йش����ʵ�֣������ ��MFC2.1.cpp
//

class C��MFC21App : public CWinAppEx
{
public:
	C��MFC21App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��MFC21App theApp;
