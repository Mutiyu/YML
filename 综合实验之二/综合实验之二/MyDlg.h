#pragma once


// MyDlg 对话框
class C综合实验之二View;
class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg();
	C综合实验之二View *m_pView;
	CString file;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void draw_pic(CString file);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
