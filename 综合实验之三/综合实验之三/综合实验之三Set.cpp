
// �ۺ�ʵ��֮��Set.cpp : C�ۺ�ʵ��֮��Set ���ʵ��
//

#include "stdafx.h"
#include "�ۺ�ʵ��֮��.h"
#include "�ۺ�ʵ��֮��Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��֮��Set ʵ��

// ���������� 2020��6��27��, 23:42

IMPLEMENT_DYNAMIC(C�ۺ�ʵ��֮��Set, CRecordset)

C�ۺ�ʵ��֮��Set::C�ۺ�ʵ��֮��Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0.0;
	m_nFields = 1;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C�ۺ�ʵ��֮��Set::GetDefaultConnect()
{
	return _T("DSN=\x7efc\x4e09;DBQ=D:\\\x684c\x9762\\VC\\\x7efc\x4e09.xls;DefaultDir=D:\\\x684c\x9762\\VC;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString C�ۺ�ʵ��֮��Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void C�ۺ�ʵ��֮��Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);

}
/////////////////////////////////////////////////////////////////////////////
// C�ۺ�ʵ��֮��Set ���

#ifdef _DEBUG
void C�ۺ�ʵ��֮��Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C�ۺ�ʵ��֮��Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

