
// 综合实验之一View.cpp : C综合实验之一View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验之一.h"
#endif

#include "综合实验之一Set.h"
#include "综合实验之一Doc.h"
#include "综合实验之一View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验之一View

IMPLEMENT_DYNCREATE(C综合实验之一View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验之一View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验之一View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合实验之一View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合实验之一View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合实验之一View::OnRecordLast)
END_MESSAGE_MAP()

// C综合实验之一View 构造/析构

C综合实验之一View::C综合实验之一View()
	: CRecordView(IDD_MY_FORM)
	, cloumn1(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("D:\\桌面\\512\\");
}

C综合实验之一View::~C综合实验之一View()
{
}

void C综合实验之一View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL C综合实验之一View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验之一View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验之一Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验之一View 诊断

#ifdef _DEBUG
void C综合实验之一View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验之一View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验之一Doc* C综合实验之一View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验之一Doc)));
	return (C综合实验之一Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验之一View 数据库支持
CRecordset* C综合实验之一View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验之一View 消息处理程序
void C综合实验之一View::draw_pic(CString file)
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


void C综合实验之一View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	filename = m_pSet->column1;
	file= path + filename;
	draw_pic(file);
	//InvalidateRect(picRect);
}


void C综合实验之一View::OnRecordPrev()
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


void C综合实验之一View::OnRecordNext()
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


void C综合实验之一View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	filename = m_pSet->column1;
	file = path + filename;
	draw_pic(file);
}
