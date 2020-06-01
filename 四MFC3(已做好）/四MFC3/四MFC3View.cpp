
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
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C��MFC3View ����/����

C��MFC3View::C��MFC3View()
{
	// TODO: �ڴ˴���ӹ������
	cr.left = 100; cr.top = 100;
	cr.right = 400; cr.bottom = 400;
	set = false;
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

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
      SetTimer(1, 500, NULL);
	  if (set)
	  {
		  KillTimer(1);
      SetTimer(2, 500, NULL);
	  }
	
	pDC->Ellipse(cr);
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


void C��MFC3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect client;
	GetClientRect(&client);
	switch (nIDEvent) {
case 1:
	
	if (cr.bottom <(client.bottom - client.top))
	{
		cr.top += 20;
		cr.bottom += 20;
	}
	else
	   {
			set =true;
		}
	break; 
	
case 2:
	if (cr.top > 0) 
	{
        cr.top -= 20;
		cr.bottom -= 20;
	}
	   
		break;
	}
		
	Invalidate();
	CView::OnTimer(nIDEvent);
}
