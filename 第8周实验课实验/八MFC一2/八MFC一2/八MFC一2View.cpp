
// ��MFCһ2View.cpp : C��MFCһ2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFCһ2.h"
#endif

#include "��MFCһ2Doc.h"
#include "��MFCһ2View.h"
#include"MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFCһ2View

IMPLEMENT_DYNCREATE(C��MFCһ2View, CView)

BEGIN_MESSAGE_MAP(C��MFCһ2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popDialog, &C��MFCһ2View::Onpopdialog)
END_MESSAGE_MAP()

// C��MFCһ2View ����/����

C��MFCһ2View::C��MFCһ2View()
{
	// TODO: �ڴ˴���ӹ������

}

C��MFCһ2View::~C��MFCһ2View()
{
}

BOOL C��MFCһ2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFCһ2View ����

void C��MFCһ2View::OnDraw(CDC* /*pDC*/)
{
	C��MFCһ2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFCһ2View ��ӡ

BOOL C��MFCһ2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFCһ2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFCһ2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFCһ2View ���

#ifdef _DEBUG
void C��MFCһ2View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFCһ2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFCһ2Doc* C��MFCһ2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFCһ2Doc)));
	return (C��MFCһ2Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFCһ2View ��Ϣ�������


void C��MFCһ2View::Onpopdialog()
{
	// TODO: �ڴ���������������
	MyDlg *pd = new MyDlg;
		pd->Create(IDD_DIALOG1);
		pd->ShowWindow(1);
}
