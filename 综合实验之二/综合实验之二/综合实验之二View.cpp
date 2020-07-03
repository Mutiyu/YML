
// 综合实验之二View.cpp : C综合实验之二View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验之二.h"
#endif
#include"MyDlg.h"
#include "综合实验之二Set.h"
#include "综合实验之二Doc.h"
#include "综合实验之二View.h"


#ifdef _DEBUG
#define new DEBUG_NEW
//#define IDC_STATIC1 -1
#endif


// C综合实验之二View

IMPLEMENT_DYNCREATE(C综合实验之二View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验之二View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验之二View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合实验之二View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合实验之二View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合实验之二View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &C综合实验之二View::OnBnClickedButton1)
END_MESSAGE_MAP()

// C综合实验之二View 构造/析构

C综合实验之二View::C综合实验之二View()
	: CRecordView(IDD_MY_FORM)
	, column1(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("D:\\桌面\\512\\");
}

C综合实验之二View::~C综合实验之二View()
{
}

void C综合实验之二View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL C综合实验之二View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验之二View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验之二Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验之二View 诊断

#ifdef _DEBUG
void C综合实验之二View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验之二View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验之二Doc* C综合实验之二View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验之二Doc)));
	return (C综合实验之二Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验之二View 数据库支持
CRecordset* C综合实验之二View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验之二View 消息处理程序
void C综合实验之二View::draw_pic(CString file)
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


void C综合实验之二View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	filename = m_pSet->column1;
	file = path + filename;
	draw_pic(file);
}


void C综合实验之二View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	filename = m_pSet->column1;
	file = path + filename;
	draw_pic(file);
}


void C综合实验之二View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	filename = m_pSet->column1;
	file = path + filename;
	draw_pic(file);
}


void C综合实验之二View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	filename = m_pSet->column1;
	file = path + filename;
	draw_pic(file);
}


void C综合实验之二View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg dlg;
	dlg.m_pView = this;
	filename = m_pSet->column1;
	file = path + filename;
	dlg.file = file;
	int t = dlg.DoModal();
	
}
