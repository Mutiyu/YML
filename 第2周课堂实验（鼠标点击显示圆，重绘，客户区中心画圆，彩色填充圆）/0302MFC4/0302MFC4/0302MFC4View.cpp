
// 0302MFC4View.cpp : CMy0302MFC4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0302MFC4.h"
#endif

#include "0302MFC4Doc.h"
#include "0302MFC4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0302MFC4View

IMPLEMENT_DYNCREATE(CMy0302MFC4View, CView)

BEGIN_MESSAGE_MAP(CMy0302MFC4View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy0302MFC4View ����/����

CMy0302MFC4View::CMy0302MFC4View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0302MFC4View::~CMy0302MFC4View()
{
}

BOOL CMy0302MFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0302MFC4View ����

void CMy0302MFC4View::OnDraw(CDC* pDC)
{
	CMy0302MFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	rgn.CreateEllipticRgn( 200, 200, 560, 740);
	cb.CreateSolidBrush(RGB(255, 192, 203));
	pDC->FillRgn( &rgn, &cb);
	pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0302MFC4View ��ӡ

BOOL CMy0302MFC4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0302MFC4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0302MFC4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0302MFC4View ���

#ifdef _DEBUG
void CMy0302MFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0302MFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0302MFC4Doc* CMy0302MFC4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0302MFC4Doc)));
	return (CMy0302MFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0302MFC4View ��Ϣ�������
