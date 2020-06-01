
// MFClibView.h : CMFClibView 类的接口
//

#pragma once


class CMFClibView : public CView
{
protected: // 仅从序列化创建
	CMFClibView();
	DECLARE_DYNCREATE(CMFClibView)

// 特性
public:
	CMFClibDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFClibView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFClibView.cpp 中的调试版本
inline CMFClibDoc* CMFClibView::GetDocument() const
   { return reinterpret_cast<CMFClibDoc*>(m_pDocument); }
#endif

