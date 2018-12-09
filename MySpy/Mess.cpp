// Mess.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MySpy.h"
#include "Mess.h"
#include "afxdialogex.h"


// CMess �Ի���
HWND g_hPage4 = NULL;

IMPLEMENT_DYNAMIC(CMess, CDialog)

CMess::CMess(CWnd* pParent /*=NULL*/)
	: CDialog(CMess::IDD, pParent)
{

}

CMess::~CMess()
{
}

void CMess::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTSTATUS, m_listStatus);
}


BEGIN_MESSAGE_MAP(CMess, CDialog)
	ON_LBN_SELCHANGE(IDC_LISTSTATUS, &CMess::OnLbnSelchangeListstatus)
END_MESSAGE_MAP()


// CMess ��Ϣ�������


BOOL CMess::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	g_hPage4=m_hWnd;

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CMess::OnLbnSelchangeListstatus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int n=m_listStatus.GetCurSel();
	//��ȡ��ǰѡ�е��±�
	switch(n)
	{
	case 0:
		if(m_listStatus.GetCheck(0)== 1 )
			::ShowWindow(g_hWnd, SW_SHOW);
		//�������� ���ڿɼ�
		else
			::ShowWindow(g_hWnd, SW_HIDE);
		//�������� ��������
		break;

	case 1:
		if(m_listStatus.GetCheck(1) == 1)
			::EnableWindow(g_hWnd, TRUE);
		//�ú�������/��ָֹ���Ĵ��ڻ�ؼ��������ͼ��̵�����
		//tureΪ����
		else
			::EnableWindow(g_hWnd,FALSE);
		//falseΪ��ֹ
		break;
	case 2:
		if(m_listStatus.GetCheck(2) == 1)
			::SetWindowPos(g_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);
		//�������� ������ǰ
		else
			::SetWindowPos(g_hWnd,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
		//�������� ȡ��������ǰ
		break;
	case 3:
		if(m_listStatus.GetCheck(3) == 1)
			::SendMessage(g_hWnd, EM_SETREADONLY, TRUE, 0);
		//EM_SETREADONLY(&HCF=207),1(0),0 �����Ƿ񽫱༭�ؼ���Ϊֻ����ͬʱ�����ؼ���ES_READONLY���
		//ture ֻ��
		else
			::SendMessage(g_hWnd, EM_SETREADONLY, FALSE, 0);
		//false ȡ��ֻ��
		break;

	case 4:
		if(m_listStatus.GetCheck(4) ==1)
		{
			::ShowWindow(g_hWnd, SW_MAXIMIZE);
			//SW_MAXIMIZE ���
			m_listStatus.SetCheck(5,0);
		}
		else
			::ShowWindow (g_hWnd, SW_RESTORE);
		//SW_RESTORE �ָ�
		break;
	case 5:

		if (m_listStatus.GetCheck(5) == 1)
		{
			::ShowWindow(g_hWnd, SW_MINIMIZE);
			//SW_MINIMIZE  ��С��
			m_listStatus.SetCheck(4,0);
		}
		else
			::ShowWindow(g_hWnd, SW_RESTORE);
		//SW_RESTORE �ָ�ԭ��
		break;
	case 6:
		if(m_listStatus.GetCheck(6) ==1)
		{       ::ShowWindow (g_hWnd, SW_RESTORE);
		//SW_RESTORE �ָ�ԭ��
		m_listStatus.SetCheck(6,0);
		m_listStatus.SetCheck(5,0);
		m_listStatus.SetCheck(4,0);
		//����� ��С�� �ͻ�ԭѡ����0
		}
		break;
	case 7:
		if(m_listStatus.GetCheck(7) ==1)
		{
			::SendMessage (g_hWnd, WM_CLOSE, 0, 0);
			//WM_CLOSE �رմ���
			m_listStatus.SetCheck(7,0);
		}
		break;
	case 8:
		if(m_listStatus.GetCheck(8) ==1)
		{
			::BringWindowToTop(g_hWnd);
			//�ú�����ָ���Ĵ������õ�Z��Ķ�����
			m_listStatus.SetCheck(8,0);
		}
		break;
	default:
		;
	}

}
