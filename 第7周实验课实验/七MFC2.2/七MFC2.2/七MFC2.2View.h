
// ��MFC2.2View.h : C��MFC22View ��Ľӿ�
//

#pragma once


class C��MFC22View : public CView
{
protected: // �������л�����
	C��MFC22View();
	DECLARE_DYNCREATE(C��MFC22View)

// ����
public:
	C��MFC22Doc* GetDocument() const;

// ����
public:
	bool Vset;
	CRect cr;
	double X;
	double Y;
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
	virtual ~C��MFC22View();
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

#ifndef _DEBUG  // ��MFC2.2View.cpp �еĵ��԰汾
inline C��MFC22Doc* C��MFC22View::GetDocument() const
   { return reinterpret_cast<C��MFC22Doc*>(m_pDocument); }
#endif

