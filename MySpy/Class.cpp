// Class.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MySpy.h"
#include "Class.h"
#include "afxdialogex.h"


// CClass �Ի���
HWND g_hPage2=NULL;
IMPLEMENT_DYNAMIC(CClass, CDialog)

CClass::CClass(CWnd* pParent /*=NULL*/)
	: CDialog(CClass::IDD, pParent)
{

}

CClass::~CClass()
{
}

void CClass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CClass, CDialog)
END_MESSAGE_MAP()


// CClass ��Ϣ�������


BOOL CClass::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��


	g_hPage2=m_hWnd;
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
