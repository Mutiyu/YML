
// 九MFCpractise1View.h : C九MFCpractise1View 类的接口
//

#pragma once


class C九MFCpractise1View : public CView
{
protected: // 仅从序列化创建
	C九MFCpractise1View();
	DECLARE_DYNCREATE(C九MFCpractise1View)

// 特性
public:
	C九MFCpractise1Doc* GetDocument() const;

// 操作
public:
	CString filename;
	CString s;
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
	virtual ~C九MFCpractise1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
	afx_msg void Onpopdlg();
	afx_msg void OnFileSave();
};

#ifndef _DEBUG  // 九MFCpractise1View.cpp 中的调试版本
inline C九MFCpractise1Doc* C九MFCpractise1View::GetDocument() const
   { return reinterpret_cast<C九MFCpractise1Doc*>(m_pDocument); }
#endif

