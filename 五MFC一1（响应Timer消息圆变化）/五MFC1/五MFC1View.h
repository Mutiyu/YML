
// ��MFC1View.h : C��MFC1View ��Ľӿ�
//

#pragma once


class C��MFC1View : public CView
{
protected: // �������л�����
	C��MFC1View();
	DECLARE_DYNCREATE(C��MFC1View)

// ����
public:
	C��MFC1Doc* GetDocument() const;

// ����
public:
	CRect cr;
	CPoint cp;
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
	virtual ~C��MFC1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowcircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // ��MFC1View.cpp �еĵ��԰汾
inline C��MFC1Doc* C��MFC1View::GetDocument() const
   { return reinterpret_cast<C��MFC1Doc*>(m_pDocument); }
#endif

