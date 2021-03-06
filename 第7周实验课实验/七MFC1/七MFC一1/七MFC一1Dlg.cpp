
// 七MFC一1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "七MFC一1.h"
#include "七MFC一1Dlg.h"
#include "afxdialogex.h"
#include"MyDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C七MFC一1Dlg 对话框



C七MFC一1Dlg::C七MFC一1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC1_DIALOG, pParent)
	, b(0)
	, a(0)
	, c(0)
	, s(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C七MFC一1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, a);
	DDX_Control(pDX, IDC_COMBO1, combox);
	DDX_Text(pDX, IDC_EDIT4, c);
	DDX_CBString(pDX, IDC_COMBO1, s);
}

BEGIN_MESSAGE_MAP(C七MFC一1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &C七MFC一1Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &C七MFC一1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C七MFC一1Dlg 消息处理程序

BOOL C七MFC一1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	combox.AddString(_T("+"));
	combox.AddString(_T("-"));
	combox.AddString(_T("*"));
	combox.AddString(_T("/"));
	combox.AddString(_T("开平方"));
	combox.AddString(_T("求倒数"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C七MFC一1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C七MFC一1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C七MFC一1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C七MFC一1Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	int t = combox.GetCurSel();
	combox.GetLBText(t,s);
	UpdateData(false);
}


void C七MFC一1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if (s == "+")
	{
		c = a + b;
	}
	if (s == "-")
	{
		c = a - b;
	}
	if (s == "*")
	{
		c = a*b;
	}
	if (s == "/")
	{
		if (b == 0)
		{
			MyDlg dlg;
			dlg.DoModal();
		}
		else
			c = a / b;
	}
	if (s == "开平方")
	{
		if (a < 0)
		{
			MyDlg dlg;
			dlg.DoModal();
		}
		else
		c = sqrt(a);
	}
	if (s == "求倒数")
	{
		c = 1 / a;
	}
	UpdateData(false);
}
