
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
#include"MyDlg.h"

// C��MFC��1View

IMPLEMENT_DYNCREATE(C��MFC��1View, CView)

BEGIN_MESSAGE_MAP(C��MFC��1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_popDlg, &C��MFC��1View::Onpopdlg)
END_MESSAGE_MAP()

// C��MFC��1View ����/����

C��MFC��1View::C��MFC��1View()
{
	// TODO: �ڴ˴���ӹ������
	filename = "yu";
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

void C��MFC��1View::OnDraw(CDC* /*pDC*/)
{
	C��MFC��1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

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


void C��MFC��1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		 filename = cfd.GetFileName();
		GetDC()->TextOutW(300, 300, filename);
	}


	CView::OnLButtonDblClk(nFlags, point);
}


void C��MFC��1View::Onpopdlg()
{
	// TODO: �ڴ���������������

	MyDlg *pd = new MyDlg;
	UpdateData(true);
	pd->s = filename;
	pd->set = true;
	pd->Create(IDD_DIALOG1);
	pd->ShowWindow(1);
	UpdateData(false);


}
