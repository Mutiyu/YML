
// ��MFC_practise1.h : ��MFC_practise1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��MFC_practise1App:
// �йش����ʵ�֣������ ��MFC_practise1.cpp
//

class C��MFC_practise1App : public CWinAppEx
{
public:
	C��MFC_practise1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��MFC_practise1App theApp;
