
// ��MFCpractise1View.h : C��MFCpractise1View ��Ľӿ�
//

#pragma once


class C��MFCpractise1View : public CView
{
protected: // �������л�����
	C��MFCpractise1View();
	DECLARE_DYNCREATE(C��MFCpractise1View)

// ����
public:
	C��MFCpractise1Doc* GetDocument() const;

// ����
public:
	CString filename;
	CString s;
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
	virtual ~C��MFCpractise1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
	afx_msg void Onpopdlg();
	afx_msg void OnFileSave();
};

#ifndef _DEBUG  // ��MFCpractise1View.cpp �еĵ��԰汾
inline C��MFCpractise1Doc* C��MFCpractise1View::GetDocument() const
   { return reinterpret_cast<C��MFCpractise1Doc*>(m_pDocument); }
#endif

