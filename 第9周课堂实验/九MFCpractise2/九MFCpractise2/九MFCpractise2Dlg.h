
// ��MFCpractise2Dlg.h : ͷ�ļ�
//

#pragma once


// C��MFCpractise2Dlg �Ի���
class C��MFCpractise2Dlg : public CDialogEx
{
// ����
public:
	C��MFCpractise2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPRACTISE2_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	afx_msg void foo(CImage &img, int &sx, int &sy, int &w, int &h);
};
