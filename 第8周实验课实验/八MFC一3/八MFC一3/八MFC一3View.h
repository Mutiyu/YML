
// ��MFCһ3View.h : C��MFCһ3View ��Ľӿ�
//

#pragma once


class C��MFCһ3View : public CView
{
protected: // �������л�����
	C��MFCһ3View();
	DECLARE_DYNCREATE(C��MFCһ3View)

// ����
public:
	C��MFCһ3Doc* GetDocument() const;

// ����
public:
	CRect cr;
	CRect client;
	bool set,set1;
	int t;
	
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
	virtual ~C��MFCһ3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ��MFCһ3View.cpp �еĵ��԰汾
inline C��MFCһ3Doc* C��MFCһ3View::GetDocument() const
   { return reinterpret_cast<C��MFCһ3Doc*>(m_pDocument); }
#endif

