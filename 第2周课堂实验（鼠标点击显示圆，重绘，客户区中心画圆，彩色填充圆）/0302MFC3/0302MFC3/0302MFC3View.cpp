
// 0302MFC3View.cpp : CMy0302MFC3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0302MFC3.h"
#endif

#include "0302MFC3Doc.h"
#include "0302MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0302MFC3View

IMPLEMENT_DYNCREATE(CMy0302MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0302MFC3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy0302MFC3View ����/����

CMy0302MFC3View::CMy0302MFC3View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0302MFC3View::~CMy0302MFC3View()
{
}

BOOL CMy0302MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0302MFC3View ����

void CMy0302MFC3View::OnDraw(CDC* pDC)
{
	CMy0302MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CRect cr;
	GetClientRect(&cr);
	pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0302MFC3View ��ӡ

BOOL CMy0302MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0302MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0302MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0302MFC3View ���

#ifdef _DEBUG
void CMy0302MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0302MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0302MFC3Doc* CMy0302MFC3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0302MFC3Doc)));
	return (CMy0302MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0302MFC3View ��Ϣ�������
