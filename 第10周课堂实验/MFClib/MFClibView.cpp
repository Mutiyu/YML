
// MFClibView.cpp : CMFClibView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFClib.h"
#endif

#include "MFClibDoc.h"
#include "MFClibView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"win32.h"
#include"win32D.h"
// CMFClibView

IMPLEMENT_DYNCREATE(CMFClibView, CView)

BEGIN_MESSAGE_MAP(CMFClibView, CView)
END_MESSAGE_MAP()

// CMFClibView ����/����

CMFClibView::CMFClibView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFClibView::~CMFClibView()
{
}

BOOL CMFClibView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFClibView ����

void CMFClibView::OnDraw(CDC* pDC)
{
	CMFClibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	s = CString(pchar());
	pDC->TextOutW(200, 200, s);
	CString ss;
	ss.Format(_T("%d�����ǴӶ�̬���ӿⷵ�ص�ֵ"), GetInt());
	pDC->TextOutW(100, 300, ss);
}


// CMFClibView ���

#ifdef _DEBUG
void CMFClibView::AssertValid() const
{
	CView::AssertValid();
}

void CMFClibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFClibDoc* CMFClibView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFClibDoc)));
	return (CMFClibDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFClibView ��Ϣ�������
