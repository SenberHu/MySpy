
// MySpyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MySpy.h"
#include "MySpyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

HWND g_hWnd=(HWND)123;
HWND g_hMe;
int  g_nHex=1;   //  ��־  16����  �Ƿ�ѡ��


CString Display(int nVal)
{
	CString str;
	if(g_nHex==1)		
	{
		str.Format(L"%x",nVal);
		str.MakeUpper();
		
	}
	else
		str.Format(L"%d",nVal);

	return str;
}


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMySpyDlg �Ի���




CMySpyDlg::CMySpyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMySpyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);



}

void CMySpyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_Tab);
}

BEGIN_MESSAGE_MAP(CMySpyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CMySpyDlg::OnTcnSelchangeTab)
	ON_BN_CLICKED(IDC_CHECK_TOP, &CMySpyDlg::OnBnClickedCheckTop)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK_16, &CMySpyDlg::OnBnClickedCheck16)
END_MESSAGE_MAP()


// CMySpyDlg ��Ϣ�������

BOOL CMySpyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	((CButton*)GetDlgItem(IDC_CHECK_TOP))->SetCheck(1);
	((CButton*)GetDlgItem(IDC_CHECK_16))->SetCheck(1);

	if(::SetWindowPos(m_hWnd,HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE))      //   һ��ʼ�ͰѴ���������ǰ  
		TRACE("������ǰʧ��");

	//�ؼ�����
	m_Pic.SubclassDlgItem(IDC_PIC,this);
	g_hMe=m_hWnd;

	InitTabDialog();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMySpyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMySpyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMySpyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CMySpyDlg::InitTabDialog()
{

	m_Tab.InsertItem(0,L"����");
	m_Tab.InsertItem(1,L"��ʽ");
	m_Tab.InsertItem(2,L"��");
	m_Tab.InsertItem(3,L"����");
	m_Tab.InsertItem(4,L"��Ϣ");

	m_page0.Create(IDD_DIALOG1,GetDlgItem(IDC_TAB));
	m_page1.Create(IDD_DIALOG2,GetDlgItem(IDC_TAB));
	m_page2.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB));
	m_page3.Create(IDD_DIALOG4,GetDlgItem(IDC_TAB));
	m_page4.Create(IDD_DIALOG5,GetDlgItem(IDC_TAB));

	CRect rc;
	m_Tab.GetClientRect(rc);
	rc.top +=23;
	rc.bottom -= 3;
	rc.left += 3;
	rc.right -= 3;

	m_page0.MoveWindow(rc);
	m_page1.MoveWindow(rc);
	m_page2.MoveWindow(rc);
	m_page3.MoveWindow(rc);
	m_page4.MoveWindow(rc);

    m_page0.ShowWindow(SW_SHOW);	
	m_Tab.SetCurSel(0);
	g_hMe=m_hWnd;

	
	CCheckListBox* plistStatus=((CCheckListBox*)FromHandle(g_hPage4)->GetDlgItem(IDC_LISTSTATUS));
	plistStatus->AddString(L"���ڿɼ�");
	plistStatus->AddString(L"���ڿ���");
	plistStatus->AddString(L"������ǰ");
	plistStatus->AddString(L"����ֻ��");	
	plistStatus->AddString(L"���");
	plistStatus->AddString(L"��С��");
	plistStatus->AddString(L"���ڻ�ԭ");
	plistStatus->AddString(L"�رմ���");
	plistStatus->AddString(L"�����");


	return TRUE;

}

void CMySpyDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{

	int i=m_Tab.GetCurSel();



	//���ݵ�ǰ��ѡ���±�����ʾ���贰��
	switch(i) {
	case 0:
		m_page0.ShowWindow(SW_SHOW);
		m_page1.ShowWindow(SW_HIDE);
		m_page2.ShowWindow(SW_HIDE);
		m_page3.ShowWindow(SW_HIDE);
		m_page4.ShowWindow(SW_HIDE);
		break;
	case 1:
		m_page0.ShowWindow(SW_HIDE);
		m_page1.ShowWindow(SW_SHOW);
		m_page2.ShowWindow(SW_HIDE);
		m_page3.ShowWindow(SW_HIDE);
		m_page4.ShowWindow(SW_HIDE);
		break;
	case 2:
		m_page0.ShowWindow(SW_HIDE);
		m_page1.ShowWindow(SW_HIDE);
		m_page2.ShowWindow(SW_SHOW);
		m_page3.ShowWindow(SW_HIDE);
		m_page4.ShowWindow(SW_HIDE);
		break;
	case 3:
		m_page0.ShowWindow(SW_HIDE);
		m_page1.ShowWindow(SW_HIDE);
		m_page2.ShowWindow(SW_HIDE);
		m_page3.ShowWindow(SW_SHOW);
		m_page4.ShowWindow(SW_HIDE);
		break;
	case 4:
		m_page0.ShowWindow(SW_HIDE);
		m_page1.ShowWindow(SW_HIDE);
		m_page2.ShowWindow(SW_HIDE);
		m_page3.ShowWindow(SW_HIDE);
		m_page4.ShowWindow(SW_SHOW);
		break;
	default:
		;
	}
}


void CMySpyDlg::OnBnClickedCheckTop()
{
	// TODO: Add your control notification handler code here
	int nTop=((CButton*)GetDlgItem(IDC_CHECK_TOP))->GetCheck();
	//�õ��ؼ�����    ѡ��Ϊ1  
	if(nTop==1)
		::SetWindowPos(m_hWnd,HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
	else
		::SetWindowPos(m_hWnd,HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
}



void CMySpyDlg::OnBnClickedCheck16()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	g_nHex=((CButton*)GetDlgItem(IDC_CHECK_16))->GetCheck();
}


void CMySpyDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ


	POINT pnt;
	RECT rc;


	HWND DeskHwnd = ::GetDesktopWindow();   //�ú����������洰�ڵľ�������洰�ڸ���������Ļ�����洰����һ��Ҫ�����ϻ������е�ͼ����������ڵ�����
	HDC DeskDC = ::GetWindowDC(DeskHwnd);     //��õ��豸������������������    


	int oldRop2 = SetROP2(DeskDC, 10);       //�ظ�ϵͳĬ��ɫ��ģʽ      ???   û����һ��  ��������  �ػ��ɫ��

	::GetCursorPos(&pnt);                    //�õ���ǰ���λ��   
	HWND UnHwnd = ::WindowFromPoint(pnt) ;   //�ú�����ð���ָ����Ĵ��ڵľ��    

	g_hWnd=UnHwnd;                             
	HWND grayHwnd = ::GetWindow(g_hWnd, GW_CHILD);     //�ú���������ָ���������ض���ϵ����Z��������ߣ��Ĵ��ھ����    GW_CHILD(&H5)�����ָ�������Ǹ����ڣ����õ�����Tab�򶥶˵��Ӵ��ڵľ��������ΪNULL��
														//���������ָ�������ڵ��Ӵ��ڣ������̳д��ڡ�

	RECT tempRc;
	BOOL bFind=FALSE;
	//�ҵ����
	while (grayHwnd)
	{
		::GetWindowRect(grayHwnd, &tempRc);

		if(::PtInRect(&tempRc,pnt))//�жϵ�pnt�Ƿ���RECT����tempRc ����ڣ��򷵻ط���
		{
			bFind = TRUE;
			break;
		}
		else
			grayHwnd = ::GetWindow(grayHwnd, GW_HWNDNEXT);


	}//while
	if(bFind == TRUE)
	{
		bFind= FALSE;
		g_hWnd = grayHwnd;
	}
	else
		;//Wnd=UnHwnd

	::GetWindowRect(g_hWnd, &rc);      
	//'��ô��ھ��εĳߴ�

	if( rc.left < 0 ) rc.left = 0;
	if (rc.top < 0 ) rc.top = 0;
	//�жϴ��ڳ�����Ļ������

	HPEN newPen = ::CreatePen(0, 3, RGB(125,0,125));    
	HGDIOBJ oldPen = ::SelectObject(DeskDC, newPen);
	::Rectangle(DeskDC, rc.left, rc.top, rc.right, rc.bottom);  

	Sleep(400);   
	::Rectangle( DeskDC, rc.left, rc.top, rc.right, rc.bottom);

	::SetROP2(DeskDC, oldRop2);
	::SelectObject( DeskDC, oldPen);
	::DeleteObject(newPen);
	::ReleaseDC( DeskHwnd, DeskDC);

	DeskDC = NULL;

	CDialogEx::OnTimer(nIDEvent);
}

