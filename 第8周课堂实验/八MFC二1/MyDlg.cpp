// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��MFC��1.h"
#include "MyDlg.h"
#include "afxdialogex.h"
//#include "��MFC��1View.h"


// MyDlg �Ի���

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
{

}

MyDlg::~MyDlg()
{
	set = false;
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
	DDX_Control(pDX, IDC_LIST1, s2);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
END_MESSAGE_MAP()


// MyDlg ��Ϣ�������


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//C��MFC��1View *view;
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//s = "";
	if (set)
	{
      s2.AddString(s);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
