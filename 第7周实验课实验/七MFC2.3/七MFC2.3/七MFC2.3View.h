
// ��MFC2.3View.h : C��MFC23View ��Ľӿ�
//

#pragma once


class C��MFC23View : public CView
{
protected: // �������л�����
	C��MFC23View();
	DECLARE_DYNCREATE(C��MFC23View)

// ����
public:
	C��MFC23Doc* GetDocument() const;

// ����
public:
	CRect cr;
	bool set;
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
	virtual ~C��MFC23View();
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
};

#ifndef _DEBUG  // ��MFC2.3View.cpp �еĵ��԰汾
inline C��MFC23Doc* C��MFC23View::GetDocument() const
   { return reinterpret_cast<C��MFC23Doc*>(m_pDocument); }
#endif

