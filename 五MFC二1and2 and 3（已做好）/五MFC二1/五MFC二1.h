
// ��MFC��1.h : ��MFC��1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��MFC��1App:
// �йش����ʵ�֣������ ��MFC��1.cpp
//

class C��MFC��1App : public CWinApp
{
public:
	C��MFC��1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��MFC��1App theApp;
