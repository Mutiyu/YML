
// ��MFCһ1View.h : C��MFCһ1View ��Ľӿ�
//

#pragma once


class C��MFCһ1View : public CView
{
protected: // �������л�����
	C��MFCһ1View();
	DECLARE_DYNCREATE(C��MFCһ1View)

// ����
public:
	C��MFCһ1Doc* GetDocument() const;

// ����
public:
	CRect cr;
	bool set;
	CPoint dMove, mMove;
	int x1, x2, y1, y2;
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
	virtual ~C��MFCһ1View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ��MFCһ1View.cpp �еĵ��԰汾
inline C��MFCһ1Doc* C��MFCһ1View::GetDocument() const
   { return reinterpret_cast<C��MFCһ1Doc*>(m_pDocument); }
#endif

