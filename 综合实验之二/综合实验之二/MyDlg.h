#pragma once


// MyDlg �Ի���
class C�ۺ�ʵ��֮��View;
class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg();
	C�ۺ�ʵ��֮��View *m_pView;
	CString file;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void draw_pic(CString file);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
