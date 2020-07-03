
// �ۺ�ʵ��֮һView.cpp : C�ۺ�ʵ��֮һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ۺ�ʵ��֮һ.h"
#endif

#include "�ۺ�ʵ��֮һSet.h"
#include "�ۺ�ʵ��֮һDoc.h"
#include "�ۺ�ʵ��֮һView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��֮һView

IMPLEMENT_DYNCREATE(C�ۺ�ʵ��֮һView, CRecordView)

BEGIN_MESSAGE_MAP(C�ۺ�ʵ��֮һView, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C�ۺ�ʵ��֮һView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C�ۺ�ʵ��֮һView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C�ۺ�ʵ��֮һView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C�ۺ�ʵ��֮һView::OnRecordLast)
END_MESSAGE_MAP()

// C�ۺ�ʵ��֮һView ����/����

C�ۺ�ʵ��֮һView::C�ۺ�ʵ��֮һView()
	: CRecordView(IDD_MY_FORM)
	, cloumn1(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("D:\\����\\512\\");
}

C�ۺ�ʵ��֮һView::~C�ۺ�ʵ��֮һView()
{
}

void C�ۺ�ʵ��֮һView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL C�ۺ�ʵ��֮һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C�ۺ�ʵ��֮һView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_�ۺ�ʵ��֮һSet;
	CRecordView::OnInitialUpdate();

}


// C�ۺ�ʵ��֮һView ���

#ifdef _DEBUG
void C�ۺ�ʵ��֮һView::AssertValid() const
{
	CRecordView::AssertValid();
}

void C�ۺ�ʵ��֮һView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C�ۺ�ʵ��֮һDoc* C�ۺ�ʵ��֮һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ۺ�ʵ��֮һDoc)));
	return (C�ۺ�ʵ��֮һDoc*)m_pDocument;
}
#endif //_DEBUG


// C�ۺ�ʵ��֮һView ���ݿ�֧��
CRecordset* C�ۺ�ʵ��֮һView::OnGetRecordset()
{
	return m_pSet;
}



// C�ۺ�ʵ��֮һView ��Ϣ�������
void C�ۺ�ʵ��֮һView::draw_pic(CString file)
{

	CImage img1;
	img1.Load(file);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	int sx, sy, w, h;
	float cr_ratio = 1.0*cr.Width() / cr.Height();
	float img_ratio = 1.0*img1.GetWidth() / img1.GetHeight();
	if (cr_ratio > img_ratio)
	{
		h = cr.Height()*1.0;
		w = img_ratio*h;
		sx = (cr.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = cr.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (cr.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img1.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void C�ۺ�ʵ��֮һView::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	filename = m_pSet->column1;
	file= path + filename;
	draw_pic(file);
	//InvalidateRect(picRect);
}


void C�ۺ�ʵ��֮һView::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	filename = m_pSet->column1;
	file = path + filename;
	draw_pic(file);
}


void C�ۺ�ʵ��֮һView::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	filename = m_pSet->column1;
	file = path + filename;
	draw_pic(file);
}


void C�ۺ�ʵ��֮һView::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	filename = m_pSet->column1;
	file = path + filename;
	draw_pic(file);
}
