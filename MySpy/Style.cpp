// Style.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MySpy.h"
#include "Style.h"
#include "afxdialogex.h"


// CStyle �Ի���

HWND g_hPage1=NULL;

IMPLEMENT_DYNAMIC(CStyle, CDialog)

CStyle::CStyle(CWnd* pParent /*=NULL*/)
	: CDialog(CStyle::IDD, pParent)
{

}

CStyle::~CStyle()
{
}

void CStyle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStyle, CDialog)
END_MESSAGE_MAP()


// CStyle ��Ϣ�������


BOOL CStyle::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	g_hPage1=m_hWnd;

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
