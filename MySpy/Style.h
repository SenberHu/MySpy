#pragma once


// CStyle �Ի���

class CStyle : public CDialog
{
	DECLARE_DYNAMIC(CStyle)

public:
	CStyle(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStyle();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
