
// MFClibView.h : CMFClibView ��Ľӿ�
//

#pragma once


class CMFClibView : public CView
{
protected: // �������л�����
	CMFClibView();
	DECLARE_DYNCREATE(CMFClibView)

// ����
public:
	CMFClibDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFClibView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFClibView.cpp �еĵ��԰汾
inline CMFClibDoc* CMFClibView::GetDocument() const
   { return reinterpret_cast<CMFClibDoc*>(m_pDocument); }
#endif

