
// 一MFCView.cpp : C一MFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "一MFC.h"
#endif

#include "一MFCDoc.h"
#include "一MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C一MFCView

IMPLEMENT_DYNCREATE(C一MFCView, CView)

BEGIN_MESSAGE_MAP(C一MFCView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C一MFCView 构造/析构

C一MFCView::C一MFCView()
{
	// TODO: 在此处添加构造代码
	s1 = _T("谁是小余？");
}

C一MFCView::~C一MFCView()
{
}

BOOL C一MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C一MFCView 绘制

void C一MFCView::OnDraw(CDC* /*pDC*/)
{
	C一MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C一MFCView 打印

BOOL C一MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C一MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C一MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C一MFCView 诊断

#ifdef _DEBUG
void C一MFCView::AssertValid() const
{
	CView::AssertValid();
}

void C一MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C一MFCDoc* C一MFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C一MFCDoc)));
	return (C一MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// C一MFCView 消息处理程序


void C一MFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C一MFCDoc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.TextOutW(300, 40, pDoc->stuname);
	pDoc->count += nFlags;
	CString s;
	s = s1 + pDoc->s2;
	dc.TextOutW(200, 100, s);
	CView::OnLButtonDown(nFlags, point);
}


void C一MFCView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C一MFCDoc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	GetDC()->TextOutW(340, 230, s);
	CView::OnRButtonDown(nFlags, point);
}
