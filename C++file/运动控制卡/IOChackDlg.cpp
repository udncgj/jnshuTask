// IOChackDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "IOChackDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIOChackDlg dialog


CIOChackDlg::CIOChackDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIOChackDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIOChackDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CIOChackDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIOChackDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIOChackDlg, CDialog)
	//{{AFX_MSG_MAP(CIOChackDlg)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_IN_NAME1, OnInName1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIOChackDlg message handlers


BOOL CIOChackDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_NAME_CHANGE)->ShowWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CIOChackDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	UINT nID1[]={IDC_BUTTON2};//IN_NAME1
	if(pMsg->message == WM_LBUTTONDOWN)
	{
		for(int i=0;i<1;i++)
		{
		if(pMsg->hwnd == GetDlgItem(nID1[0])->m_hWnd)// && m_bLimitX==0)
		{
//		ScreenToClient(rect);//screen(屏幕坐标)to(客户区坐标)
//			CRect re;
//			GetWindowRect(&re);
			GetDlgItem(IDC_NAME_CHANGE)->ShowWindow(true);
//			GetDlgItem(IDC_NAME_CHANGE)->SetWindowPos(NULL,re.left,re.right,re.top,re.bottom,NULL);
		}
		}
	}
	else if(pMsg->message == WM_LBUTTONUP)
	{
		GetDlgItem(IDC_NAME_CHANGE)->ShowWindow(false);
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CIOChackDlg::OnReset() 
{
	// TODO: Add your control notification handler code here
//	GetDlgItem(IDC_NAME_CHANGE)->ShowWindow(true);
}

void CIOChackDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
//	GetDlgItem(IDC_NAME_CHANGE)->ShowWindow(false);
}

void CIOChackDlg::OnInName1() 
{
	// TODO: Add your control notification handler code here
//	GetDlgItem(IDC_NAME_CHANGE)->ShowWindow(true);
}
