
// 0302MFC1and2View.cpp : CMy0302MFC1and2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0302MFC1and2.h"
#endif

#include "0302MFC1and2Doc.h"
#include "0302MFC1and2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0302MFC1and2View

IMPLEMENT_DYNCREATE(CMy0302MFC1and2View, CView)

BEGIN_MESSAGE_MAP(CMy0302MFC1and2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0302MFC1and2View ����/����

CMy0302MFC1and2View::CMy0302MFC1and2View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0302MFC1and2View::~CMy0302MFC1and2View()
{
}

BOOL CMy0302MFC1and2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0302MFC1and2View ����

void CMy0302MFC1and2View::OnDraw(CDC* pDC)
{
	CMy0302MFC1and2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0302MFC1and2View ��ӡ

BOOL CMy0302MFC1and2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0302MFC1and2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0302MFC1and2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0302MFC1and2View ���

#ifdef _DEBUG
void CMy0302MFC1and2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0302MFC1and2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0302MFC1and2Doc* CMy0302MFC1and2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0302MFC1and2Doc)));
	return (CMy0302MFC1and2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0302MFC1and2View ��Ϣ�������


void CMy0302MFC1and2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int r = rand() % 100 + 50;
	cr.left = point.x - r; cr.top = point.y - r;
	cr.right = point.x + r;   cr.bottom = point.y + r;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
