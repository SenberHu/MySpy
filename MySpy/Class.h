#pragma once


// CClass �Ի���

class CClass : public CDialog
{
	DECLARE_DYNAMIC(CClass)

public:
	CClass(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CClass();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
