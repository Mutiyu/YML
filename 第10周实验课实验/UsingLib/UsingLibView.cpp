
// UsingLibView.cpp : CUsingLibView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CUsingLibView ����/����

CUsingLibView::CUsingLibView()
{
	// TODO: �ڴ˴���ӹ������

}

CUsingLibView::~CUsingLibView()
{
}

BOOL CUsingLibView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CUsingLibView ����

void CUsingLibView::OnDraw(CDC* pDC)
{
	CUsingLibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	s.Format(_T("%d"), factorial(5));
	pDC->TextOutW(20, 10, _T("��̬����:"));
	pDC->TextOutW(20, 50, s);
	FAC fac;
	s.Format(_T("%f"), fac.convert(30.0));
	pDC->TextOutW(20, 80, s);
	pDC->TextOutW(200, 10, _T("��̬����:"));
	s.Format(_T("%d"), factorialDll(5));
	pDC->TextOutW(200,50, s);
	FACDll facdll;
	s.Format(_T("%f"), facdll.convertDll(30.0));
	pDC->TextOutW(200, 80, s);
}


// CUsingLibView ��ӡ

BOOL CUsingLibView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CUsingLibView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CUsingLibView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CUsingLibView ���

#ifdef _DEBUG
void CUsingLibView::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLibDoc* CUsingLibView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLibDoc)));
	return (CUsingLibDoc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLibView ��Ϣ�������
