
// ��MFC2.4View.h : C��MFC24View ��Ľӿ�
//

#pragma once


class C��MFC24View : public CView
{
protected: // �������л�����
	C��MFC24View();
	DECLARE_DYNCREATE(C��MFC24View)

// ����
public:
	C��MFC24Doc* GetDocument() const;

// ����
public:
	CRect cr;
	CBrush brush;
	CRgn rgn;
	bool set;
	int A, B, C;
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
	virtual ~C��MFC24View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onpopdlg();
};

#ifndef _DEBUG  // ��MFC2.4View.cpp �еĵ��԰汾
inline C��MFC24Doc* C��MFC24View::GetDocument() const
   { return reinterpret_cast<C��MFC24Doc*>(m_pDocument); }
#endif

