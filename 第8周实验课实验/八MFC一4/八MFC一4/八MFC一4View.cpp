
// ��MFCһ4View.cpp : C��MFCһ4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFCһ4.h"
#endif

#include "��MFCһ4Doc.h"
#include "��MFCһ4View.h"
#include"MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFCһ4View

IMPLEMENT_DYNCREATE(C��MFCһ4View, CView)

BEGIN_MESSAGE_MAP(C��MFCһ4View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &C��MFCһ4View::OnBnClickedButton1)
END_MESSAGE_MAP()

// C��MFCһ4View ����/����

C��MFCһ4View::C��MFCһ4View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
	X = 0;
}

C��MFCһ4View::~C��MFCһ4View()
{
}

BOOL C��MFCһ4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFCһ4View ����

void C��MFCһ4View::OnDraw(CDC* /*pDC*/)
{
	C��MFCһ4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	MyDlg *pd = new MyDlg;
	pd->Create(IDD_DIALOG1);
	pd->ShowWindow(1);
	X = pd->x;

	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFCһ4View ��ӡ

BOOL C��MFCһ4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFCһ4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFCһ4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFCһ4View ���

#ifdef _DEBUG
void C��MFCһ4View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFCһ4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFCһ4Doc* C��MFCһ4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFCһ4Doc)));
	return (C��MFCһ4Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFCһ4View ��Ϣ�������


void C��MFCһ4View::OnBnClickedButton1()
{

}
