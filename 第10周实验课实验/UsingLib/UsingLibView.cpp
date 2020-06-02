
// UsingLibView.cpp : CUsingLibView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "UsingLib.h"
#endif

#include "UsingLibDoc.h"
#include "UsingLibView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"win32.h"
#include"win32Dll.h"
// CUsingLibView

IMPLEMENT_DYNCREATE(CUsingLibView, CView)

BEGIN_MESSAGE_MAP(CUsingLibView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CUsingLibView 构造/析构

CUsingLibView::CUsingLibView()
{
	// TODO: 在此处添加构造代码

}

CUsingLibView::~CUsingLibView()
{
}

BOOL CUsingLibView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUsingLibView 绘制

void CUsingLibView::OnDraw(CDC* pDC)
{
	CUsingLibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s.Format(_T("%d"), factorial(5));
	pDC->TextOutW(20, 10, _T("静态库结果:"));
	pDC->TextOutW(20, 50, s);
	FAC fac;
	s.Format(_T("%f"), fac.convert(30.0));
	pDC->TextOutW(20, 80, s);
	pDC->TextOutW(200, 10, _T("动态库结果:"));
	s.Format(_T("%d"), factorialDll(5));
	pDC->TextOutW(200,50, s);
	FACDll facdll;
	s.Format(_T("%f"), facdll.convertDll(30.0));
	pDC->TextOutW(200, 80, s);
}


// CUsingLibView 打印

BOOL CUsingLibView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CUsingLibView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CUsingLibView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CUsingLibView 诊断

#ifdef _DEBUG
void CUsingLibView::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLibDoc* CUsingLibView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLibDoc)));
	return (CUsingLibDoc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLibView 消息处理程序
