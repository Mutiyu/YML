
// ��MFCpractise1View.cpp : C��MFCpractise1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFCpractise1.h"
#endif

#include "��MFCpractise1Doc.h"
#include "��MFCpractise1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include"MyDlg.h"
// C��MFCpractise1View

IMPLEMENT_DYNCREATE(C��MFCpractise1View, CView)

BEGIN_MESSAGE_MAP(C��MFCpractise1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &C��MFCpractise1View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &C��MFCpractise1View::OnFileSaveAs)
	ON_COMMAND(ID_popDlg, &C��MFCpractise1View::Onpopdlg)
	ON_COMMAND(ID_FILE_SAVE, &C��MFCpractise1View::OnFileSave)
END_MESSAGE_MAP()

// C��MFCpractise1View ����/����

C��MFCpractise1View::C��MFCpractise1View()
{
	// TODO: �ڴ˴���ӹ������

}

C��MFCpractise1View::~C��MFCpractise1View()
{
}

BOOL C��MFCpractise1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFCpractise1View ����

void C��MFCpractise1View::OnDraw(CDC* /*pDC*/)
{
	C��MFCpractise1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFCpractise1View ��ӡ

BOOL C��MFCpractise1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFCpractise1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFCpractise1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFCpractise1View ���

#ifdef _DEBUG
void C��MFCpractise1View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFCpractise1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFCpractise1Doc* C��MFCpractise1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFCpractise1Doc)));
	return (C��MFCpractise1Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFCpractise1View ��Ϣ�������


void C��MFCpractise1View::OnFileOpen()
{
	// TODO: �ڴ���������������
	/*CFileDialog cfd(true);
	int t=cfd.DoModal();
	string txts;
	CImage img;
	if (t == IDOK)
	{
		 filename = cfd.GetPathName();
		ifstream ifs(filename);
		CClientDC dc(this);
		//int x = 20, y = 10;
		while (ifs >> txts)   //���ļ�������
		{
			//dc.TextOutW(x, y, CString(txts.c_str()));
			//y += 30;
			img.Load(CString(txts.c_str()));
			//CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
			img.Draw(GetDC()->m_hDC, 0, 0);
			MyDlg dlg;
			dlg.DoModal();
			

		}
	}*/

}


void C��MFCpractise1View::OnFileSaveAs()
{
	// TODO: �ڴ���������������
	/*CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(cfd.GetPathName());  //�����
	    //s = cfd.GetPathName();
		ofs << CT2A(s1.GetString()) << endl;
		
	}*/
}


void C��MFCpractise1View::Onpopdlg()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		//ofstream ofs(cfd.GetPathName());  //�����
		s = cfd.GetPathName();
		//ofs << CT2A(s.GetString()) << endl;  

	}
}


void C��MFCpractise1View::OnFileSave()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(cfd.GetPathName());  //�����
		ofs << CT2A(s.GetString()) << endl;  //���򿪵��ļ�·�������ı��ļ���

	}
}
