
// ��MFCһ1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��MFCһ1App: 
// �йش����ʵ�֣������ ��MFCһ1.cpp
//

class C��MFCһ1App : public CWinApp
{
public:
	C��MFCһ1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��MFCһ1App theApp;