
// MFClibView.cpp : CMFClibView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFClib.h"
#endif

#include "MFClibDoc.h"
#include "MFClibView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"win32.h"
#include"win32D.h"
// CMFClibView

IMPLEMENT_DYNCREATE(CMFClibView, CView)

BEGIN_MESSAGE_MAP(CMFClibView, CView)
END_MESSAGE_MAP()

// CMFClibView 构造/析构

CMFClibView::CMFClibView()
{
	// TODO: 在此处添加构造代码

}

CMFClibView::~CMFClibView()
{
}

BOOL CMFClibView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFClibView 绘制

void CMFClibView::OnDraw(CDC* pDC)
{
	CMFClibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s = CString(pchar());
	pDC->TextOutW(200, 200, s);
	CString ss;
	ss.Format(_T("%d，这是从动态链接库返回的值"), GetInt());
	pDC->TextOutW(100, 300, ss);
}


// CMFClibView 诊断

#ifdef _DEBUG
void CMFClibView::AssertValid() const
{
	CView::AssertValid();
}

void CMFClibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFClibDoc* CMFClibView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFClibDoc)));
	return (CMFClibDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFClibView 消息处理程序
