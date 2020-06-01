
// 一MFCView.h : C一MFCView 类的接口
//

#pragma once


class C一MFCView : public CView
{
protected: // 仅从序列化创建
	C一MFCView();
	DECLARE_DYNCREATE(C一MFCView)

// 特性
public:
	C一MFCDoc* GetDocument() const;

// 操作
public:
	CString s1;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C一MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 一MFCView.cpp 中的调试版本
inline C一MFCDoc* C一MFCView::GetDocument() const
   { return reinterpret_cast<C一MFCDoc*>(m_pDocument); }
#endif

