
// ��MFC2.1View.h : C��MFC21View ��Ľӿ�
//

#pragma once


class C��MFC21View : public CView
{
protected: // �������л�����
	C��MFC21View();
	DECLARE_DYNCREATE(C��MFC21View)

// ����
public:
	C��MFC21Doc* GetDocument() const;

// ����
public:
	CRect cr;
	bool set;
	CPoint cp;
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
	virtual ~C��MFC21View();
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

#ifndef _DEBUG  // ��MFC2.1View.cpp �еĵ��԰汾
inline C��MFC21Doc* C��MFC21View::GetDocument() const
   { return reinterpret_cast<C��MFC21Doc*>(m_pDocument); }
#endif

