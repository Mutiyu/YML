
// ��MFC2View.h : C��MFC2View ��Ľӿ�
//

#pragma once


class C��MFC2View : public CView
{
protected: // �������л�����
	C��MFC2View();
	DECLARE_DYNCREATE(C��MFC2View)

// ����
public:
	C��MFC2Doc* GetDocument() const;

// ����
public:
	int M,N,a,b;
	CRect cr;
	bool set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C��MFC2View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ��MFC2View.cpp �еĵ��԰汾
inline C��MFC2Doc* C��MFC2View::GetDocument() const
   { return reinterpret_cast<C��MFC2Doc*>(m_pDocument); }
#endif

