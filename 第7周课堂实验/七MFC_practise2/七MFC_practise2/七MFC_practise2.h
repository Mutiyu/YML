
// ��MFC_practise2.h : ��MFC_practise2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��MFC_practise2App:
// �йش����ʵ�֣������ ��MFC_practise2.cpp
//

class C��MFC_practise2App : public CWinAppEx
{
public:
	C��MFC_practise2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��MFC_practise2App theApp;
