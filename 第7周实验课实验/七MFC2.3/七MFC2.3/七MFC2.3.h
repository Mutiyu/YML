
// ��MFC2.3.h : ��MFC2.3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��MFC23App:
// �йش����ʵ�֣������ ��MFC2.3.cpp
//

class C��MFC23App : public CWinAppEx
{
public:
	C��MFC23App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��MFC23App theApp;
