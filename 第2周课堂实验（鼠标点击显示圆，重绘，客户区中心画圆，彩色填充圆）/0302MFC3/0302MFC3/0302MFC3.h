
// 0302MFC3.h : 0302MFC3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0302MFC3App:
// �йش����ʵ�֣������ 0302MFC3.cpp
//

class CMy0302MFC3App : public CWinAppEx
{
public:
	CMy0302MFC3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0302MFC3App theApp;
