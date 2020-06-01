
// ��MFC2.3View.cpp : C��MFC23View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC2.3.h"
#endif

#include "��MFC2.3Doc.h"
#include "��MFC2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFC23View

IMPLEMENT_DYNCREATE(C��MFC23View, CView)

BEGIN_MESSAGE_MAP(C��MFC23View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C��MFC23View ����/����

C��MFC23View::C��MFC23View()
{
	// TODO: �ڴ˴���ӹ������
	cr.left = 200; cr.top = 100;
	cr.right = 400; cr.bottom = 400;
	set = false;
}

C��MFC23View::~C��MFC23View()
{
}

BOOL C��MFC23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC23View ����

void C��MFC23View::OnDraw(CDC* pDC)
{
	C��MFC23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFC23View ��ӡ

BOOL C��MFC23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFC23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFC23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFC23View ���

#ifdef _DEBUG
void C��MFC23View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC23Doc* C��MFC23View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC23Doc)));
	return (C��MFC23Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC23View ��Ϣ�������


void C��MFC23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC  dc(this);
	CPen *oldpen = NULL;
	CPen pen(PS_DASH, 1, RGB(255, 0, 0));
	GetDC()->SelectStockObject(NULL_BRUSH);
	CBrush *oldbrush = NULL;
	CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	oldbrush =dc.SelectObject(brush);
	if (point.x > cr.left&&point.x < cr.right)
	{
		if (point.y > cr.top&&point.y < cr.bottom)
		{
				//CreatePen(PS_DASH, 0,RGB(255,0,0));
				oldpen = dc.SelectObject(&pen);
				dc.Rectangle(cr);
				dc.SelectObject(oldpen);
			
	   }
	}
	//Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
