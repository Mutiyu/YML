
// ��MFCһ1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

// C��MFCһ1Dlg �Ի���
class C��MFCһ1Dlg : public CDialogEx
{
// ����
public:
	C��MFCһ1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	double b;
	double a;
	CComboBox combox;
	double c;
	CString s;
	afx_msg void OnBnClickedButton1();
};
