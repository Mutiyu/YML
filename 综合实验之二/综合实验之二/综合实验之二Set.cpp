
// 综合实验之二Set.cpp : C综合实验之二Set 类的实现
//

#include "stdafx.h"
#include "综合实验之二.h"
#include "综合实验之二Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验之二Set 实现

// 代码生成在 2020年6月22日, 16:19

IMPLEMENT_DYNAMIC(C综合实验之二Set, CRecordset)

C综合实验之二Set::C综合实验之二Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	m_nFields = 1;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString C综合实验之二Set::GetDefaultConnect()
{
	return _T("DSN=photo;DBQ=D:\\\x684c\x9762\\photo.xls;DefaultDir=D:\\\x684c\x9762;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString C综合实验之二Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void C综合实验之二Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[照片]"), column1);

}
/////////////////////////////////////////////////////////////////////////////
// C综合实验之二Set 诊断

#ifdef _DEBUG
void C综合实验之二Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C综合实验之二Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

