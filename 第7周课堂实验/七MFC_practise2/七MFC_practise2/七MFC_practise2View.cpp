
// ��MFC_practise2View.cpp : C��MFC_practise2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC_practise2.h"
#endif

#include "��MFC_practise2Doc.h"
#include "��MFC_practise2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"MyDlg.h"

// C��MFC_practise2View

IMPLEMENT_DYNCREATE(C��MFC_practise2View, CView)

BEGIN_MESSAGE_MAP(C��MFC_practise2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C��MFC_practise2View ����/����

C��MFC_practise2View::C��MFC_practise2View()
{
	// TODO: �ڴ˴���ӹ������

}

C��MFC_practise2View::~C��MFC_practise2View()
{
}

BOOL C��MFC_practise2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC_practise2View ����

void C��MFC_practise2View::OnDraw(CDC* /*pDC*/)
{
	C��MFC_practise2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	MyDlg dlg;
	dlg.DoModal();
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFC_practise2View ��ӡ

BOOL C��MFC_practise2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFC_practise2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFC_practise2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFC_practise2View ���

#ifdef _DEBUG
void C��MFC_practise2View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC_practise2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC_practise2Doc* C��MFC_practise2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC_practise2Doc)));
	return (C��MFC_practise2Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC_practise2View ��Ϣ�������
