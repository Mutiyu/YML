
// ��MFC��1View.cpp : C��MFC��1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC��1.h"
#endif

#include "��MFC��1Doc.h"
#include "��MFC��1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFC��1View

IMPLEMENT_DYNCREATE(C��MFC��1View, CView)

BEGIN_MESSAGE_MAP(C��MFC��1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowMyName, &C��MFC��1View::OnShowmyname)
	ON_COMMAND(ID_ShowLine, &C��MFC��1View::OnShowline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_Rectangle, &C��MFC��1View::OnRectangle)
	ON_COMMAND(ID_circle, &C��MFC��1View::Oncircle)
END_MESSAGE_MAP()

// C��MFC��1View ����/����

C��MFC��1View::C��MFC��1View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;
	cb.LoadBitmap(IDB_BITMAP1);
	cb.GetBitmap(&BM);
	c_Width= BM.bmWidth;
	c_Height = BM.bmHeight;
	set1 = false;
	set2 = false;
	set3 = false;



}

C��MFC��1View::~C��MFC��1View()
{
}

BOOL C��MFC��1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC��1View ����

void C��MFC��1View::OnDraw(CDC* pDC)
{
	C��MFC��1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MepDC;
	MepDC.CreateCompatibleDC(NULL);
	MepDC.SelectObject(cb);
	pDC->BitBlt(0, 0, c_Width, c_Height, &MepDC, 0, 0, SRCCOPY);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFC��1View ��ӡ

BOOL C��MFC��1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFC��1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFC��1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFC��1View ���

#ifdef _DEBUG
void C��MFC��1View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC��1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC��1Doc* C��MFC��1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC��1Doc)));
	return (C��MFC��1Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC��1View ��Ϣ�������


void C��MFC��1View::OnShowmyname()
{
	// TODO: �ڴ���������������
	CString s;
	s.Format(_T("������"));
	CClientDC dc(this);
	dc.TextOutW(600, 500, s);

}


void C��MFC��1View::OnShowline()
{
	set1 = true;
	set2 = false;
	set3 = false;
}


void C��MFC��1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	d = point;
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void C��MFC��1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	u = point;
	if (set1)
	{
		dc.MoveTo(d);
		dc.LineTo(point);
	}
	if (set2) {
		dc.Rectangle(cr.left,cr.top,point.x,point.y);
	}
	if (set3)
	{
		dc.Ellipse(cr.left, cr.top, point.x, point.y);
	}
	CView::OnLButtonUp(nFlags, point);
}


void C��MFC��1View::OnRectangle()
{
	set1 = false;
	set2 = true;
}


void C��MFC��1View::Oncircle()
{
	set1 = false;
	set2 = false;
	set3 = true;

}
