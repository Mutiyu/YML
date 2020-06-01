
// ��MFC2.2View.cpp : C��MFC22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC2.2.h"
#endif

#include "��MFC2.2Doc.h"
#include "��MFC2.2View.h"
#include"MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFC22View

IMPLEMENT_DYNCREATE(C��MFC22View, CView)

BEGIN_MESSAGE_MAP(C��MFC22View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popDlg, &C��MFC22View::Onpopdlg)
END_MESSAGE_MAP()

// C��MFC22View ����/����

C��MFC22View::C��MFC22View()
{
	// TODO: �ڴ˴���ӹ������
	Vset = false;
	X = 0.0;
	Y = 0.0;
}

C��MFC22View::~C��MFC22View()
{
}

BOOL C��MFC22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC22View ����

void C��MFC22View::OnDraw(CDC* pDC)
{
	C��MFC22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFC22View ��ӡ

BOOL C��MFC22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFC22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFC22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFC22View ���

#ifdef _DEBUG
void C��MFC22View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC22Doc* C��MFC22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC22Doc)));
	return (C��MFC22Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC22View ��Ϣ�������


void C��MFC22View::Onpopdlg()
{
	// TODO: �ڴ���������������
	Vset = true;
	MyDlg dlg;
	int t=dlg.DoModal();
		X = dlg.x;
		Y = dlg.y;
		cr.left = 500 - X / 2;
		cr.top = 500 - Y / 2;
		cr.right = 500 + X / 2;
		cr.bottom = 500 + Y / 2;
	
	if (t==IDOK)
	{
		GetDC()->Ellipse(cr);
	}
	Invalidate();
}
