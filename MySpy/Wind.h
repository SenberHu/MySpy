#pragma once


// CWind �Ի���

class CWind : public CDialog
{
	DECLARE_DYNAMIC(CWind)

public:
	CWind(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWind();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
