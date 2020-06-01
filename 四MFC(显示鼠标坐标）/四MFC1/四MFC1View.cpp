
// ��MFC1View.cpp : C��MFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC1.h"
#endif

#include "��MFC1Doc.h"
#include "��MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFC1View

IMPLEMENT_DYNCREATE(C��MFC1View, CView)

BEGIN_MESSAGE_MAP(C��MFC1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C��MFC1View ����/����

C��MFC1View::C��MFC1View()
{
	// TODO: �ڴ˴���ӹ������

}

C��MFC1View::~C��MFC1View()
{
}

BOOL C��MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC1View ����

void C��MFC1View::OnDraw(CDC* pDC)
{
	C��MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFC1View ���

#ifdef _DEBUG
void C��MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC1Doc* C��MFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC1Doc)));
	return (C��MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC1View ��Ϣ�������


void C��MFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��MFC1Doc* pDoc = GetDocument();
	
	pDoc->a = point.x;
	pDoc->b = point.y;
	

	CView::OnLButtonDown(nFlags, point);
}


void C��MFC1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��MFC1Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("x=%d    y=%d"), point.x, point.y);
	CClientDC dc(this);
	dc.TextOutW(20, 20, s);
	CView::OnMouseMove(nFlags, point);
}


void C��MFC1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��MFC1Doc* pDoc = GetDocument();
	pDoc->c = point.x;
	pDoc->d = point.y;
	pDoc->cr.left = pDoc->a; pDoc->cr.top = pDoc->b;
	pDoc->cr.right = pDoc->c; pDoc->cr.bottom = pDoc->d;
	CClientDC dc(this);
	dc.Rectangle(pDoc->cr);
	CView::OnLButtonUp(nFlags, point);
}
