#pragma once
#include "afxwin.h"


// CCom �Ի���

class CCom : public CDialog
{
	DECLARE_DYNAMIC(CCom)

public:
	CCom(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCom();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_EditHwnd;
	CEdit m_EditClass;
	CEdit m_EditTitle;
	CEdit m_EditRect;
	CEdit m_EditHwndID;
	CEdit m_EditProcessID;
	CEdit m_EditPath;
	virtual BOOL OnInitDialog();
};
