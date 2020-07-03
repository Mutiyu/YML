#pragma once


// Change_Dlg 对话框

class Change_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Change_Dlg)

public:
	Change_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Change_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long i;
};
