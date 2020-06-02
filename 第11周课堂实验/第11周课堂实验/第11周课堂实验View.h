
// 第11周课堂实验View.h : C第11周课堂实验View 类的接口
//

#pragma once

class C第11周课堂实验Set;

class C第11周课堂实验View : public CRecordView
{
protected: // 仅从序列化创建
	C第11周课堂实验View();
	DECLARE_DYNCREATE(C第11周课堂实验View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY11_FORM };
#endif
	C第11周课堂实验Set* m_pSet;

// 特性
public:
	C第11周课堂实验Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C第11周课堂实验View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	double column1;
	CString column2;
	double column3;
	CString column4;
	CString column5;
	CString column6;
};

#ifndef _DEBUG  // 第11周课堂实验View.cpp 中的调试版本
inline C第11周课堂实验Doc* C第11周课堂实验View::GetDocument() const
   { return reinterpret_cast<C第11周课堂实验Doc*>(m_pDocument); }
#endif

