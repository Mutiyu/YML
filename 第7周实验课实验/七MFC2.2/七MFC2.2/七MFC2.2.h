
// ��MFC2.2.h : ��MFC2.2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��MFC22App:
// �йش����ʵ�֣������ ��MFC2.2.cpp
//

class C��MFC22App : public CWinAppEx
{
public:
	C��MFC22App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��MFC22App theApp;
