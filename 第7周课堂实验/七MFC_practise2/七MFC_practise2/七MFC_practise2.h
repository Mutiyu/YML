
// 七MFC_practise2.h : 七MFC_practise2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C七MFC_practise2App:
// 有关此类的实现，请参阅 七MFC_practise2.cpp
//

class C七MFC_practise2App : public CWinAppEx
{
public:
	C七MFC_practise2App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C七MFC_practise2App theApp;
