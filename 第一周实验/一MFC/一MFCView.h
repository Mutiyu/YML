
// һMFCView.h : CһMFCView ��Ľӿ�
//

#pragma once


class CһMFCView : public CView
{
protected: // �������л�����
	CһMFCView();
	DECLARE_DYNCREATE(CһMFCView)

// ����
public:
	CһMFCDoc* GetDocument() const;

// ����
public:
	CString s1;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CһMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // һMFCView.cpp �еĵ��԰汾
inline CһMFCDoc* CһMFCView::GetDocument() const
   { return reinterpret_cast<CһMFCDoc*>(m_pDocument); }
#endif

