
// 综合实验之二View.h : C综合实验之二View 类的接口
//

#pragma once

class C综合实验之二Set;

class C综合实验之二View : public CRecordView
{
protected: // 仅从序列化创建
	C综合实验之二View();
	DECLARE_DYNCREATE(C综合实验之二View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C综合实验之二Set* m_pSet;

// 特性
public:
	C综合实验之二Doc* GetDocument() const;

// 操作
public:
	CString path;
	CString filename;
	CString file;
	CRect cr;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	
// 实现
public:
	virtual ~C综合实验之二View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString column1;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void draw_pic(CString file);
	afx_msg void OnBnClickedButton1();
	
};

#ifndef _DEBUG  // 综合实验之二View.cpp 中的调试版本
inline C综合实验之二Doc* C综合实验之二View::GetDocument() const
   { return reinterpret_cast<C综合实验之二Doc*>(m_pDocument); }
#endif

