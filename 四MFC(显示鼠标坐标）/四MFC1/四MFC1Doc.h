
// ��MFC1Doc.h : C��MFC1Doc ��Ľӿ�
//


#pragma once


class C��MFC1Doc : public CDocument
{
protected: // �������л�����
	C��MFC1Doc();
	DECLARE_DYNCREATE(C��MFC1Doc)

// ����
public:

// ����
public:
	int a, b, c, d;
	CRect cr;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C��MFC1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
