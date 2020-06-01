
// һMFCView.cpp : CһMFCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "һMFC.h"
#endif

#include "һMFCDoc.h"
#include "һMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CһMFCView

IMPLEMENT_DYNCREATE(CһMFCView, CView)

BEGIN_MESSAGE_MAP(CһMFCView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CһMFCView ����/����

CһMFCView::CһMFCView()
{
	// TODO: �ڴ˴���ӹ������
	s1 = _T("˭��С�ࣿ");
}

CһMFCView::~CһMFCView()
{
}

BOOL CһMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CһMFCView ����

void CһMFCView::OnDraw(CDC* /*pDC*/)
{
	CһMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CһMFCView ��ӡ

BOOL CһMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CһMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CһMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CһMFCView ���

#ifdef _DEBUG
void CһMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CһMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CһMFCDoc* CһMFCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CһMFCDoc)));
	return (CһMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CһMFCView ��Ϣ�������


void CһMFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CһMFCDoc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.TextOutW(300, 40, pDoc->stuname);
	pDoc->count += nFlags;
	CString s;
	s = s1 + pDoc->s2;
	dc.TextOutW(200, 100, s);
	CView::OnLButtonDown(nFlags, point);
}


void CһMFCView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CһMFCDoc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	GetDC()->TextOutW(340, 230, s);
	CView::OnRButtonDown(nFlags, point);
}
