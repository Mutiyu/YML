
// 0302MFC1and2View.h : CMy0302MFC1and2View ��Ľӿ�
//

#pragma once


class CMy0302MFC1and2View : public CView
{
protected: // �������л�����
	CMy0302MFC1and2View();
	DECLARE_DYNCREATE(CMy0302MFC1and2View)

// ����
public:
	CMy0302MFC1and2Doc* GetDocument() const;

// ����
public:
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
	virtual ~CMy0302MFC1and2View();
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

#ifndef _DEBUG  // 0302MFC1and2View.cpp �еĵ��԰汾
inline CMy0302MFC1and2Doc* CMy0302MFC1and2View::GetDocument() const
   { return reinterpret_cast<CMy0302MFC1and2Doc*>(m_pDocument); }
#endif

