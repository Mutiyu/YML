
// ��MFC2View.cpp : C��MFC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC2.h"
#endif

#include "��MFC2Doc.h"
#include "��MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFC2View

IMPLEMENT_DYNCREATE(C��MFC2View, CView)

BEGIN_MESSAGE_MAP(C��MFC2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C��MFC2View ����/����

C��MFC2View::C��MFC2View()
{
	// TODO: �ڴ˴���ӹ������
	M = 0;
	N = 0;
	cr.left = 0; cr.top = 0;
	cr.right = 0; cr.bottom = 0;
	a = 0; b = 0;
}

C��MFC2View::~C��MFC2View()
{
}

BOOL C��MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC2View ����

void C��MFC2View::OnDraw(CDC* pDC)
{
	C��MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//int a = cr.Width();
	

}


// C��MFC2View ���

#ifdef _DEBUG
void C��MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC2Doc* C��MFC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC2Doc)));
	return (C��MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC2View ��Ϣ�������


void C��MFC2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = true;
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}

void C��MFC2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	 M = N;
	  N = 0;
	  CString t;
	CClientDC dc(this);
	cr.right = point.x;
	cr.bottom = point.y;
	a = cr.Width();
	t.Format(_T("�����ƶ�  %d   �����ط���һ��"), a / M);
	dc.TextOutW(40, 40, t);
	CView::OnLButtonUp(nFlags, point);
}

void C��MFC2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s,t;
	if (set) {
		N += nFlags;
		CString s, t;
		s.Format(_T("MouseMove������   %d    ��"), N);
		dc.TextOutW(20, 20, s);
		
		}
	//b = a /N ;
		//t.Format(_T("�����ƶ�  %d   �����ط���һ��"),a);
		//dc.TextOutW(40, 80, t);
	
       
	
	CView::OnMouseMove(nFlags, point);
}



