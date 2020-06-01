
// 九MFCpractise1View.cpp : C九MFCpractise1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "九MFCpractise1.h"
#endif

#include "九MFCpractise1Doc.h"
#include "九MFCpractise1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include"MyDlg.h"
// C九MFCpractise1View

IMPLEMENT_DYNCREATE(C九MFCpractise1View, CView)

BEGIN_MESSAGE_MAP(C九MFCpractise1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &C九MFCpractise1View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &C九MFCpractise1View::OnFileSaveAs)
	ON_COMMAND(ID_popDlg, &C九MFCpractise1View::Onpopdlg)
	ON_COMMAND(ID_FILE_SAVE, &C九MFCpractise1View::OnFileSave)
END_MESSAGE_MAP()

// C九MFCpractise1View 构造/析构

C九MFCpractise1View::C九MFCpractise1View()
{
	// TODO: 在此处添加构造代码

}

C九MFCpractise1View::~C九MFCpractise1View()
{
}

BOOL C九MFCpractise1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C九MFCpractise1View 绘制

void C九MFCpractise1View::OnDraw(CDC* /*pDC*/)
{
	C九MFCpractise1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C九MFCpractise1View 打印

BOOL C九MFCpractise1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C九MFCpractise1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C九MFCpractise1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C九MFCpractise1View 诊断

#ifdef _DEBUG
void C九MFCpractise1View::AssertValid() const
{
	CView::AssertValid();
}

void C九MFCpractise1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C九MFCpractise1Doc* C九MFCpractise1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C九MFCpractise1Doc)));
	return (C九MFCpractise1Doc*)m_pDocument;
}
#endif //_DEBUG


// C九MFCpractise1View 消息处理程序


void C九MFCpractise1View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	/*CFileDialog cfd(true);
	int t=cfd.DoModal();
	string txts;
	CImage img;
	if (t == IDOK)
	{
		 filename = cfd.GetPathName();
		ifstream ifs(filename);
		CClientDC dc(this);
		//int x = 20, y = 10;
		while (ifs >> txts)   //从文件读出来
		{
			//dc.TextOutW(x, y, CString(txts.c_str()));
			//y += 30;
			img.Load(CString(txts.c_str()));
			//CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
			img.Draw(GetDC()->m_hDC, 0, 0);
			MyDlg dlg;
			dlg.DoModal();
			

		}
	}*/

}


void C九MFCpractise1View::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码
	/*CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(cfd.GetPathName());  //输出流
	    //s = cfd.GetPathName();
		ofs << CT2A(s1.GetString()) << endl;
		
	}*/
}


void C九MFCpractise1View::Onpopdlg()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		//ofstream ofs(cfd.GetPathName());  //输出流
		s = cfd.GetPathName();
		//ofs << CT2A(s.GetString()) << endl;  

	}
}


void C九MFCpractise1View::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(cfd.GetPathName());  //输出流
		ofs << CT2A(s.GetString()) << endl;  //将打开的文件路径存入文本文件中

	}
}
