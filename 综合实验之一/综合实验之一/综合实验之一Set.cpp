
// �ۺ�ʵ��֮һSet.cpp : C�ۺ�ʵ��֮һSet ���ʵ��
//

#include "stdafx.h"
#include "�ۺ�ʵ��֮һ.h"
#include "�ۺ�ʵ��֮һSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��֮һSet ʵ��

// ���������� 2020��6��2��, 12:36

IMPLEMENT_DYNAMIC(C�ۺ�ʵ��֮һSet, CRecordset)

C�ۺ�ʵ��֮һSet::C�ۺ�ʵ��֮һSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	m_nFields = 1;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C�ۺ�ʵ��֮һSet::GetDefaultConnect()
{
	return _T("DSN=photo;DBQ=D:\\\x684c\x9762\\photo.xls;DefaultDir=D:\\\x684c\x9762;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString C�ۺ�ʵ��֮һSet::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void C�ۺ�ʵ��֮һSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[��Ƭ]"), column1);

}
/////////////////////////////////////////////////////////////////////////////
// C�ۺ�ʵ��֮һSet ���

#ifdef _DEBUG
void C�ۺ�ʵ��֮һSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void C�ۺ�ʵ��֮һSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

