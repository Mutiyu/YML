
// 11MFC1and2and3Set.cpp : CMy11MFC1and2and3Set 类的实现
//

#include "stdafx.h"
#include "11MFC1and2and3.h"
#include "11MFC1and2and3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11MFC1and2and3Set 实现

// 代码生成在 2020年6月1日, 21:32

IMPLEMENT_DYNAMIC(CMy11MFC1and2and3Set, CRecordset)

CMy11MFC1and2and3Set::CMy11MFC1and2and3Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = 0.0;
	column2 = L"";
	column3 = 0.0;
	column4 = L"";
	column5 = L"";
	column6 = L"";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMy11MFC1and2and3Set::GetDefaultConnect()
{
	return _T("DSN=Student;DBQ=D:\\\x684c\x9762\\Student.xls;DefaultDir=D:\\\x684c\x9762;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CMy11MFC1and2and3Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CMy11MFC1and2and3Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Double(pFX, _T("[编号]"), column1);
	RFX_Text(pFX, _T("[姓名]"), column2);
	RFX_Double(pFX, _T("[年龄]"), column3);
	RFX_Text(pFX, _T("[电话]"), column4);
	RFX_Text(pFX, _T("[学号]"), column5);
	RFX_Text(pFX, _T("[照片]"), column6);

}
/////////////////////////////////////////////////////////////////////////////
// CMy11MFC1and2and3Set 诊断

#ifdef _DEBUG
void CMy11MFC1and2and3Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMy11MFC1and2and3Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

