
// ��MFC1View.cpp : C��MFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC1.h"
#endif

#include "��MFC1Doc.h"
#include "��MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFC1View

IMPLEMENT_DYNCREATE(C��MFC1View, CView)

BEGIN_MESSAGE_MAP(C��MFC1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowCircle, &C��MFC1View::OnShowcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C��MFC1View ����/����

C��MFC1View::C��MFC1View()
{
	// TODO: �ڴ˴���ӹ������
	t = 0;
	
}

C��MFC1View::~C��MFC1View()
{
}

BOOL C��MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC1View ����

void C��MFC1View::OnDraw(CDC* pDC)
{
	C��MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush cb;
	CRgn rgn;
	CPen cc;
    SetTimer(1, 500, NULL);
	GetClientRect(&cr);
	cp = cr.CenterPoint();
	cr.left = cp.x - 25; cr.top = cp.y - 25;
	cr.right = cp.x + 25; cr.bottom = cp.y + 25;
	
	
		cr.left -= t; cr.top -= t; cr.right += t; cr.bottom += t;
		cb.CreateSolidBrush(RGB(rand()%255, rand()%255, rand()%255));
		rgn.CreateEllipticRgn(cr.left, cr.top, cr.right, cr.bottom);
		pDC->FillRgn(&rgn, &cb);
		//cc.CreatePen(PS_SOLID, 1, RGB(rand() % 255, rand() % 255, rand() % 255));
		//pDC->SelectObject(cc);

		//pDC->Ellipse(cr); 

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFC1View ��ӡ

BOOL C��MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFC1View ���

#ifdef _DEBUG
void C��MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC1Doc* C��MFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC1Doc)));
	return (C��MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC1View ��Ϣ�������


void C��MFC1View::OnShowcircle()
{
	// TODO: �ڴ���������������
	//set = true;
	
}


void C��MFC1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	    t += 5;
		Invalidate();
		
	CView::OnTimer(nIDEvent);
}
