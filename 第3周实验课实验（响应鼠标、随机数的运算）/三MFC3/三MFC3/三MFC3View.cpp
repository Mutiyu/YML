
// ��MFC3View.cpp : C��MFC3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC3.h"
#endif

#include "��MFC3Doc.h"
#include "��MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFC3View

IMPLEMENT_DYNCREATE(C��MFC3View, CView)

BEGIN_MESSAGE_MAP(C��MFC3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C��MFC3View ����/����

C��MFC3View::C��MFC3View()
{
	// TODO: �ڴ˴���ӹ������
	
}

C��MFC3View::~C��MFC3View()
{
}

BOOL C��MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC3View ����

void C��MFC3View::OnDraw(CDC* pDC)
{
	C��MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->a);
	pDC->Rectangle(pDoc->b);
	pDC->Rectangle(pDoc->c);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFC3View ��ӡ

BOOL C��MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFC3View ���

#ifdef _DEBUG
void C��MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC3Doc* C��MFC3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC3Doc)));
	return (C��MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC3View ��Ϣ�������


void C��MFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	if (point.x >= 100 && point.x <= 300&&point.y >= 100 && point.y <= 400)
	{
		
			a = rand() % 100;
			s1.Format(_T("%d"), a);
			dc.TextOutW(point.x, point.y, s1);
		    
	}
	else if (point.x >= 400 && point.x <= 700&&point.y >= 400 && point.y <= 550)
	{
			b = rand() % 100;
			s2.Format(_T("%d"), b);
			dc.TextOutW(point.x, point.y, s2);
	}
	else
	{
		dc.TextOutW(point.x, point.y, _T("�����Ч"));
	}
	CView::OnLButtonDown(nFlags, point);
}


void C��MFC3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	if (point.x >= 900 && point.x <= 1050 && point.y >= 200 && point.y <= 500)
	{
		a = rand() % 100;
		b = rand() % 100;
		c = a + b;
		s3.Format(_T("%d", c));
		dc.TextOutW(point.x, point.y, s3);
	}
	CView::OnRButtonDown(nFlags, point);
}
