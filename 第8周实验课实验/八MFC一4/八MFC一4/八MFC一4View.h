
// ��MFCһ4View.h : C��MFCһ4View ��Ľӿ�
//

#pragma once


class C��MFCһ4View : public CView
{
protected: // �������л�����
	C��MFCһ4View();
	DECLARE_DYNCREATE(C��MFCһ4View)

// ����
public:
	C��MFCһ4Doc* GetDocument() const;

// ����
public:
	bool set;
	int X;
	CString s2;
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
	virtual ~C��MFCһ4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // ��MFCһ4View.cpp �еĵ��԰汾
inline C��MFCһ4Doc* C��MFCһ4View::GetDocument() const
   { return reinterpret_cast<C��MFCһ4Doc*>(m_pDocument); }
#endif

