// Wind.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MySpy.h"
#include "Wind.h"
#include "afxdialogex.h"


// CWind �Ի���

HWND g_hPage3=NULL;
IMPLEMENT_DYNAMIC(CWind, CDialog)

CWind::CWind(CWnd* pParent /*=NULL*/)
	: CDialog(CWind::IDD, pParent)
{

}

CWind::~CWind()
{
}

void CWind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWind, CDialog)
END_MESSAGE_MAP()


// CWind ��Ϣ�������


BOOL CWind::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	g_hPage3=m_hWnd;

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
