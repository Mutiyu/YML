
// ��MFC2.4View.cpp : C��MFC24View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC2.4.h"
#endif

#include "��MFC2.4Doc.h"
#include "��MFC2.4View.h"
#include"MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFC24View

IMPLEMENT_DYNCREATE(C��MFC24View, CView)

BEGIN_MESSAGE_MAP(C��MFC24View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popDlg, &C��MFC24View::Onpopdlg)
END_MESSAGE_MAP()

// C��MFC24View ����/����

C��MFC24View::C��MFC24View()
{
	// TODO: �ڴ˴���ӹ������
	cr.left = 200; cr.top = 200;
	cr.right = 560; cr.bottom =740;
	set = false;
	A = B = C = 0;
}

C��MFC24View::~C��MFC24View()
{
}

BOOL C��MFC24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC24View ����

void C��MFC24View::OnDraw(CDC* pDC)
{
	C��MFC24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	
	
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFC24View ��ӡ

BOOL C��MFC24View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFC24View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFC24View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFC24View ���

#ifdef _DEBUG
void C��MFC24View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC24Doc* C��MFC24View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC24Doc)));
	return (C��MFC24Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC24View ��Ϣ�������


void C��MFC24View::Onpopdlg()
{
	// TODO: �ڴ���������������
	MyDlg dlg;
	int t=dlg.DoModal();
	if (t == IDOK)
	{
		set = true;
		A = dlg.a;
		B = dlg.b;
		C = dlg.c;
		rgn.CreateEllipticRgn(200, 200, 560, 740);
		brush.CreateSolidBrush(RGB(A, B, C));
		GetDC()->FillRgn(&rgn, &brush);
	}
}
