#pragma once


// Change_Dlg �Ի���

class Change_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Change_Dlg)

public:
	Change_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Change_Dlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long i;
};
