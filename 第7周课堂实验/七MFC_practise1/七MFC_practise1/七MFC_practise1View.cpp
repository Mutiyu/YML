
// ��MFC_practise1View.cpp : C��MFC_practise1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC_practise1.h"
#endif

#include "��MFC_practise1Doc.h"
#include "��MFC_practise1View.h"
#include "MyDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFC_practise1View

IMPLEMENT_DYNCREATE(C��MFC_practise1View, CView)

BEGIN_MESSAGE_MAP(C��MFC_practise1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

// C��MFC_practise1View ����/����

C��MFC_practise1View::C��MFC_practise1View()
{
	// TODO: �ڴ˴���ӹ������
	
}

C��MFC_practise1View::~C��MFC_practise1View()
{
}

BOOL C��MFC_practise1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC_practise1View ����

void C��MFC_practise1View::OnDraw(CDC* pDC)
{
	C��MFC_practise1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	MyDlg1 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		pDC->TextOutW(400, 350, _T("�����˳��Ի���"));
		
	}
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFC_practise1View ��ӡ

BOOL C��MFC_practise1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFC_practise1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFC_practise1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFC_practise1View ���

#ifdef _DEBUG
void C��MFC_practise1View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC_practise1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC_practise1Doc* C��MFC_practise1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC_practise1Doc)));
	return (C��MFC_practise1Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC_practise1View ��Ϣ�������


void C��MFC_practise1View::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CView::OnClose();
}
