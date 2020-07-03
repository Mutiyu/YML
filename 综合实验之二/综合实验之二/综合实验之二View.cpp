
// �ۺ�ʵ��֮��View.cpp : C�ۺ�ʵ��֮��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ۺ�ʵ��֮��.h"
#endif
#include"MyDlg.h"
#include "�ۺ�ʵ��֮��Set.h"
#include "�ۺ�ʵ��֮��Doc.h"
#include "�ۺ�ʵ��֮��View.h"


#ifdef _DEBUG
#define new DEBUG_NEW
//#define IDC_STATIC1 -1
#endif


// C�ۺ�ʵ��֮��View

IMPLEMENT_DYNCREATE(C�ۺ�ʵ��֮��View, CRecordView)

BEGIN_MESSAGE_MAP(C�ۺ�ʵ��֮��View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C�ۺ�ʵ��֮��View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C�ۺ�ʵ��֮��View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C�ۺ�ʵ��֮��View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C�ۺ�ʵ��֮��View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &C�ۺ�ʵ��֮��View::OnBnClickedButton1)
END_MESSAGE_MAP()

// C�ۺ�ʵ��֮��View ����/����

C�ۺ�ʵ��֮��View::C�ۺ�ʵ��֮��View()
	: CRecordView(IDD_MY_FORM)
	, column1(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("D:\\����\\512\\");
}

C�ۺ�ʵ��֮��View::~C�ۺ�ʵ��֮��View()
{
}

void C�ۺ�ʵ��֮��View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL C�ۺ�ʵ��֮��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C�ۺ�ʵ��֮��View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_�ۺ�ʵ��֮��Set;
	CRecordView::OnInitialUpdate();

}


// C�ۺ�ʵ��֮��View ���

#ifdef _DEBUG
void C�ۺ�ʵ��֮��View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C�ۺ�ʵ��֮��View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C�ۺ�ʵ��֮��Doc* C�ۺ�ʵ��֮��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ۺ�ʵ��֮��Doc)));
	return (C�ۺ�ʵ��֮��Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ۺ�ʵ��֮��View ���ݿ�֧��
CRecordset* C�ۺ�ʵ��֮��View::OnGetRecordset()
{
	return m_pSet;
}



// C�ۺ�ʵ��֮��View ��Ϣ�������
void C�ۺ�ʵ��֮��View::draw_pic(CString file)
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


void C�ۺ�ʵ��֮��View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	filename = m_pSet->column1;
	file = path + filename;
	draw_pic(file);
}


void C�ۺ�ʵ��֮��View::OnRecordPrev()
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


void C�ۺ�ʵ��֮��View::OnRecordNext()
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


void C�ۺ�ʵ��֮��View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	filename = m_pSet->column1;
	file = path + filename;
	draw_pic(file);
}


void C�ۺ�ʵ��֮��View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MyDlg dlg;
	dlg.m_pView = this;
	filename = m_pSet->column1;
	file = path + filename;
	dlg.file = file;
	int t = dlg.DoModal();
	
}
