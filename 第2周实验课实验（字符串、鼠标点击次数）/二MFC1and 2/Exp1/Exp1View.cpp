
// Exp1View.cpp : CExp1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exp1.h"
#endif

#include "Exp1Doc.h"
#include "Exp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp1View

IMPLEMENT_DYNCREATE(CExp1View, CView)

BEGIN_MESSAGE_MAP(CExp1View, CView)
END_MESSAGE_MAP()

// CExp1View ����/����

CExp1View::CExp1View()
{
	// TODO: �ڴ˴���ӹ������
	

}

CExp1View::~CExp1View()
{
}

BOOL CExp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExp1View ����

void CExp1View::OnDraw(CDC* pDC)
{
	CExp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString  s1,A1;
	s1 = _T("����С��");
	
	int h1;
	h1= 91;
	A1.Format(_T("A1��ֵΪ%d"),h1);
	pDC->TextOutW(100, 200, _T("View�ࣺ"));
	pDC->TextOutW( 300,200,s1);
	pDC->TextOutW( 600,200,A1);
	pDC->TextOutW(100, 400, _T("Doc�ࣺ"));
	pDC->TextOutW( 300,400,pDoc->s2);
	pDC->TextOutW( 600,400,pDoc->A2);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExp1View ���

#ifdef _DEBUG
void CExp1View::AssertValid() const
{
	CView::AssertValid();
}

void CExp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp1Doc* CExp1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp1Doc)));
	return (CExp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp1View ��Ϣ�������
