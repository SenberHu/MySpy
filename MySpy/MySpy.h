
// MySpy.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


#include "mypic.h"
#include "Com.h"
#include "Class.h"
#include "Mess.h"
#include "Style.h"
#include "Wind.h"


extern HWND g_hWnd;
extern HWND g_hMe;
extern HWND g_hPage0;
extern HWND g_hPage1;
extern HWND g_hPage2;
extern HWND g_hPage3;
extern HWND g_hPage4;

extern int g_nHex;
extern CString Display(int nVal);
extern CString getProcPath(int PID);
class CMySpyApp : public CWinApp
{
public:
	CMySpyApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMySpyApp theApp;