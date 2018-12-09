// Com.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MySpy.h"
#include "Com.h"
#include "afxdialogex.h"


#include <stdio.h>
#include <tlhelp32.h>



// CCom �Ի���

IMPLEMENT_DYNAMIC(CCom, CDialog)

HWND  g_hPage0;

CCom::CCom(CWnd* pParent /*=NULL*/)
	: CDialog(CCom::IDD, pParent)
{

}

CCom::~CCom()
{
}

void CCom::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_HWND, m_EditHwnd);
	DDX_Control(pDX, IDC_EDIT_CLASS, m_EditClass);
	DDX_Control(pDX, IDC_EDIT_TITLE, m_EditTitle);
	DDX_Control(pDX, IDC_EDIT_RECT, m_EditRect);
	DDX_Control(pDX, IDC_EDIT_WNDID, m_EditHwndID);
	DDX_Control(pDX, IDC_EDIT_PROCESSID, m_EditProcessID);
	DDX_Control(pDX, IDC_EDIT_PATH, m_EditPath);
}


BEGIN_MESSAGE_MAP(CCom, CDialog)
END_MESSAGE_MAP()


// CCom ��Ϣ�������


BOOL CCom::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	g_hPage0=m_hWnd;

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


CString getProcPath(int PID)
{


	HANDLE hProcess=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	//����ͨ����ȡ������ϢΪָ���Ľ��̡�����ʹ�õĶ�[HEAP]��ģ��[MODULE]���߳̽���һ������.
	//TH32CS_SNAPPROCESS �践�صĶ���			0 Ϊ����ID��
	HANDLE hModule;
	//�½�һ�����
	PROCESSENTRY32* pinfo=new PROCESSENTRY32;
	//�½�������ſ��ս�����Ϣ��һ���ṹ��
	MODULEENTRY32* minfo=new MODULEENTRY32;
	//����ṹ������һ����Ŀ��һ���б��о���һ��ָ���Ľ�����ʹ�õ�ģ��
	pinfo->dwSize=sizeof(PROCESSENTRY32);
	minfo->dwSize=sizeof(MODULEENTRY32);
	//���ô�С

	char shortpath[MAX_PATH] = "";

	//Ϊ·��������ʱ����  MAX_PATHΪ·����󳤶�


	hModule=CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,PID);//pinfo->th32ProcessID);
	//����ͨ����ȡ������ϢΪָ���Ľ��̡�����ʹ�õĶ�[HEAP]��ģ��[MODULE]���߳̽���һ������.
	//TH32CS_SNAPMODULE �践�صĶ���			PID Ϊ����ID��
	Module32First(hModule, minfo);
	//�˺������������������ĵ�һ��ģ�����Ϣ���� hModule
	// minfo Ϊ MODULEENTRY32�ṹ��ָ�롣������������,�ɹ�����ture


	CString str;
	str.Format(L"%s",minfo->szExePath);
	//��·����Ϣ��minfo->szExePath��ȡ��

	CloseHandle(hProcess);
	CloseHandle(hModule);
	//�رվ��
	if(pinfo) delete pinfo;
	if(minfo) delete minfo;
	//ɾ�����

	return str;
	//���ؾ��
}
