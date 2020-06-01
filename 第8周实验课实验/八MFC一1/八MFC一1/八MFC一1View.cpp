
// ��MFCһ1View.cpp : C��MFCһ1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFCһ1.h"
#endif

#include "��MFCһ1Doc.h"
#include "��MFCһ1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFCһ1View

IMPLEMENT_DYNCREATE(C��MFCһ1View, CView)

BEGIN_MESSAGE_MAP(C��MFCһ1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C��MFCһ1View ����/����

C��MFCһ1View::C��MFCһ1View()
{
	// TODO: �ڴ˴���ӹ������
	cr.left = 100; cr.top = 150;
	cr.right = 400; cr.bottom = 500;
	set = false;
	x1 = x2 = y1 = y2 = 0;
}

C��MFCһ1View::~C��MFCһ1View()
{
}

BOOL C��MFCһ1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFCһ1View ����

void C��MFCһ1View::OnDraw(CDC* pDC)
{
	C��MFCһ1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFCһ1View ��ӡ

BOOL C��MFCһ1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFCһ1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFCһ1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFCһ1View ���

#ifdef _DEBUG
void C��MFCһ1View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFCһ1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFCһ1Doc* C��MFCһ1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFCһ1Doc)));
	return (C��MFCһ1Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFCһ1View ��Ϣ�������


void C��MFCһ1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = true;
	dMove = point;
	x1 = point.x - cr.left;
	x2 = cr.right - point.x;
	y1 = point.y - cr.top;
	y2 = cr.bottom - point.y;
	CView::OnLButtonDown(nFlags, point);
}


void C��MFCһ1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void C��MFCһ1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (set)
	{
		mMove = point;
		cr.left = mMove.x - x1;
		cr.top = mMove.y - y1;
		cr.right = mMove.x + x2;
		cr.bottom = mMove.y + y2;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
