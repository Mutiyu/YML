
// ��MFC��1View.h : C��MFC��1View ��Ľӿ�
//

#pragma once


class C��MFC��1View : public CView
{
protected: // �������л�����
	C��MFC��1View();
	DECLARE_DYNCREATE(C��MFC��1View)

// ����
public:
	C��MFC��1Doc* GetDocument() const;

// ����
public:
	CBitmap cb;
	int c_Width;
	int c_Height;
	bool set1, set2, set3;
	CPoint d;
	CPoint u;
	CRect cr;

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
	virtual ~C��MFC��1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowmyname();
	afx_msg void OnShowline();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRectangle();
	afx_msg void Oncircle();
};

#ifndef _DEBUG  // ��MFC��1View.cpp �еĵ��԰汾
inline C��MFC��1Doc* C��MFC��1View::GetDocument() const
   { return reinterpret_cast<C��MFC��1Doc*>(m_pDocument); }
#endif

