
// 11MFC1and2and3View.cpp : CMy11MFC1and2and3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "11MFC1and2and3.h"
#endif

#include "11MFC1and2and3Set.h"
#include "11MFC1and2and3Doc.h"
#include "11MFC1and2and3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11MFC1and2and3View

IMPLEMENT_DYNCREATE(CMy11MFC1and2and3View, CRecordView)

BEGIN_MESSAGE_MAP(CMy11MFC1and2and3View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy11MFC1and2and3View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &CMy11MFC1and2and3View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMy11MFC1and2and3View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMy11MFC1and2and3View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMy11MFC1and2and3View::OnRecordLast)
END_MESSAGE_MAP()

// CMy11MFC1and2and3View 构造/析构

CMy11MFC1and2and3View::CMy11MFC1and2and3View()
	: CRecordView(IDD_MY11MFC1AND2AND3_FORM)
	, column1(0)
	, column2(_T(""))
	, column3(0)
	, column4(_T(""))
	, column5(_T(""))
	, column6(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("D:\\桌面\\512\\");
}

CMy11MFC1and2and3View::~CMy11MFC1and2and3View()
{
}

void CMy11MFC1and2and3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column6);
}

BOOL CMy11MFC1and2and3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMy11MFC1and2and3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My11MFC1and2and3Set;
	CRecordView::OnInitialUpdate();

}


// CMy11MFC1and2and3View 诊断

#ifdef _DEBUG
void CMy11MFC1and2and3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy11MFC1and2and3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy11MFC1and2and3Doc* CMy11MFC1and2and3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11MFC1and2and3Doc)));
	return (CMy11MFC1and2and3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11MFC1and2and3View 数据库支持
CRecordset* CMy11MFC1and2and3View::OnGetRecordset()
{
	return m_pSet;
}



// CMy11MFC1and2and3View 消息处理程序
void CMy11MFC1and2and3View::draw_pic(CString file)
{

	CImage img1;
	img1.Load(file);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	int sx, sy, w, h;
	float cr_ratio = 1.0*cr.Width() / cr.Height();
	float img_ratio = 1.0*img1.GetWidth() / img1.GetHeight();
	if (cr_ratio > img_ratio)
	{
		h = cr.Height()*1.0;
		w = img_ratio*h;
		sx = (cr.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = cr.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (cr.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img1.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void CMy11MFC1and2and3View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	filename = m_pSet->column6;
	CString file = path + filename;
	draw_pic(file);

}


void CMy11MFC1and2and3View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	filename = m_pSet->column6;
	CString file = path + filename;
	draw_pic(file);

}


void CMy11MFC1and2and3View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	filename = m_pSet->column6;
	CString file = path + filename;
	draw_pic(file);
}


void CMy11MFC1and2and3View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	filename = m_pSet->column6;
	CString file = path + filename;
	draw_pic(file);
}


void CMy11MFC1and2and3View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	filename = m_pSet->column6;
	CString file = path + filename;
	draw_pic(file);
}
