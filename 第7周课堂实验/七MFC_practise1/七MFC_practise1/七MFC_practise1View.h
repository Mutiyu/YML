
// ��MFC_practise1View.h : C��MFC_practise1View ��Ľӿ�
//

#pragma once


class C��MFC_practise1View : public CView
{
protected: // �������л�����
	C��MFC_practise1View();
	DECLARE_DYNCREATE(C��MFC_practise1View)

// ����
public:
	C��MFC_practise1Doc* GetDocument() const;

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
	virtual ~C��MFC_practise1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
};

#ifndef _DEBUG  // ��MFC_practise1View.cpp �еĵ��԰汾
inline C��MFC_practise1Doc* C��MFC_practise1View::GetDocument() const
   { return reinterpret_cast<C��MFC_practise1Doc*>(m_pDocument); }
#endif

