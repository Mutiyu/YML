
// ��MFC2.1View.cpp : C��MFC21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC2.1.h"
#endif

#include "��MFC2.1Doc.h"
#include "��MFC2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFC21View

IMPLEMENT_DYNCREATE(C��MFC21View, CView)

BEGIN_MESSAGE_MAP(C��MFC21View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C��MFC21View ����/����

C��MFC21View::C��MFC21View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
	cr.left = 100; cr.top = 230;
	cr.right = 330; cr.bottom = 480;
	x1 = x2 = y1 = y2 = 0;
}

C��MFC21View::~C��MFC21View()
{
}

BOOL C��MFC21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC21View ����

void C��MFC21View::OnDraw(CDC* pDC)
{
	C��MFC21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFC21View ��ӡ

BOOL C��MFC21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFC21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFC21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFC21View ���

#ifdef _DEBUG
void C��MFC21View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC21Doc* C��MFC21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC21Doc)));
	return (C��MFC21Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC21View ��Ϣ�������


void C��MFC21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = true;
	x1 = point.x - cr.left;
	x2 = cr.right - point.x;
	y1 = point.y-cr.top ;
	y2 = cr.bottom - point.y;
	CView::OnLButtonDown(nFlags, point);
}


void C��MFC21View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void C��MFC21View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (set)
	{
		cr.left = point.x - x1;
		cr.right = point.x + x2;
		cr.top = point.y - y1;
		cr.bottom = point.y + y2;
	}
	
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
