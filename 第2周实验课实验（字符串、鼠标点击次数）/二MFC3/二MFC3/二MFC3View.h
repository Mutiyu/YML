
// ��MFC3View.h : C��MFC3View ��Ľӿ�
//

#pragma once


class C��MFC3View : public CView
{
protected: // �������л�����
	C��MFC3View();
	DECLARE_DYNCREATE(C��MFC3View)

// ����
public:
	C��MFC3Doc* GetDocument() const;

// ����
public:

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
	virtual ~C��MFC3View();
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

#ifndef _DEBUG  // ��MFC3View.cpp �еĵ��԰汾
inline C��MFC3Doc* C��MFC3View::GetDocument() const
   { return reinterpret_cast<C��MFC3Doc*>(m_pDocument); }
#endif

