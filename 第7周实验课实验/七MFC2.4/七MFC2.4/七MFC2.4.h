
// ��MFC2.4.h : ��MFC2.4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��MFC24App:
// �йش����ʵ�֣������ ��MFC2.4.cpp
//

class C��MFC24App : public CWinAppEx
{
public:
	C��MFC24App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��MFC24App theApp;
