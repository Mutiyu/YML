
// ��MFC_practise2View.h : C��MFC_practise2View ��Ľӿ�
//

#pragma once


class C��MFC_practise2View : public CView
{
protected: // �������л�����
	C��MFC_practise2View();
	DECLARE_DYNCREATE(C��MFC_practise2View)

// ����
public:
	C��MFC_practise2Doc* GetDocument() const;

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
	virtual ~C��MFC_practise2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��MFC_practise2View.cpp �еĵ��԰汾
inline C��MFC_practise2Doc* C��MFC_practise2View::GetDocument() const
   { return reinterpret_cast<C��MFC_practise2Doc*>(m_pDocument); }
#endif

