
// ��MFCһ3View.cpp : C��MFCһ3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFCһ3.h"
#endif

#include "��MFCһ3Doc.h"
#include "��MFCһ3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFCһ3View

IMPLEMENT_DYNCREATE(C��MFCһ3View, CView)

BEGIN_MESSAGE_MAP(C��MFCһ3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C��MFCһ3View ����/����

C��MFCһ3View::C��MFCһ3View()
{
	// TODO: �ڴ˴���ӹ������
	//cr.left = 0;
	//cr.top = 433 - 40;
	//cr.right = 100;
	//cr.bottom = 433 + 60;
	set = false;
	set1 = false;
	t = 0;
}

C��MFCһ3View::~C��MFCһ3View()
{
}

BOOL C��MFCһ3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFCһ3View ����

void C��MFCһ3View::OnDraw(CDC* pDC)
{
	C��MFCһ3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&client);
	cr.left = 0;
	cr.top = (client.bottom-client.top)/2 - 40;
	cr.right = 100;
	cr.bottom = (client.bottom - client.top) / 2 + 60;
SetTimer(1, 500, NULL);

	if (set1)
	{
		KillTimer(1);
	    cr.left = client.right - 100;
		cr.right = client.right;
 		SetTimer(2, 500, NULL);
	}
	
pDC->Ellipse(cr.left + t, cr.top, cr.right + t, cr.bottom);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFCһ3View ��ӡ

BOOL C��MFCһ3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFCһ3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFCһ3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFCһ3View ���

#ifdef _DEBUG
void C��MFCһ3View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFCһ3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFCһ3Doc* C��MFCһ3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFCһ3Doc)));
	return (C��MFCһ3Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFCһ3View ��Ϣ�������


void C��MFCһ3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent)
	{
	case 1:
		if(set)
		{
if (t <= (client.right -cr.right))
		{
	     t+= 50;
		}
else
           {
	set1 = true;
	t = 0;
		   }
			
	}

break;
	case 2:
		if (set)
		{
			
			t -= 50;
		}
			
			break;
	
	}
		
    Invalidate();
	CView::OnTimer(nIDEvent);
}


void C��MFCһ3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = true;
	CView::OnLButtonDown(nFlags, point);
}


void C��MFCһ3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	CView::OnLButtonDblClk(nFlags, point);
}
