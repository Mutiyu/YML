// Change_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验之三.h"
#include "Change_Dlg.h"
#include "afxdialogex.h"


// Change_Dlg 对话框

IMPLEMENT_DYNAMIC(Change_Dlg, CDialogEx)

Change_Dlg::Change_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, i(0)
{

}

Change_Dlg::~Change_Dlg()
{
}

void Change_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, i);
}


BEGIN_MESSAGE_MAP(Change_Dlg, CDialogEx)
END_MESSAGE_MAP()


// Change_Dlg 消息处理程序
