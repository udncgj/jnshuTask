// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "SettingDlg.h"
#include "SETTING1.h"
#include "SETTING2.h"
#include "SETTING3.h"

SETTING1 m_Setting1;
SETTING2 m_Setting2;
SETTING3 m_Setting3;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog


CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingDlg)
	DDX_Control(pDX, IDC_TAB_SETTING, m_tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingDlg)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SETTING, OnTabSetting)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg message handlers

BOOL CSettingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.InsertItem(0,"参数一");
	m_tab.InsertItem(1,"参数二");
	m_tab.InsertItem(2,"结果");
	m_Setting1.Create(IDD_SETTING1,GetDlgItem(IDC_TAB_SETTING));
	m_Setting2.Create(IDD_SETTING2,GetDlgItem(IDC_TAB_SETTING));
	m_Setting3.Create(IDD_SETTING3,GetDlgItem(IDC_TAB_SETTING));
	MoveWindow();
	
//	GetDlgItem(IDC_EDIT_DATA)->SetWindowPos(NULL,x,y,105,16,SWP_NOZORDER);
//	m_Setting1.SetWindowPos(NULL,rs.top,rs.bottom,rs.left,rs.right,SWP_NOZORDER);
	m_tab.SetCurSel(m_ntab);
	OpenSetting();
	/*
	m_Setting1.ShowWindow(true);
	m_Setting2.ShowWindow(false);
	m_Setting3.ShowWindow(false);
	m_tab.SetCurSel(0);*/

//	SetTimer(1,1000,NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
	
}

void CSettingDlg::OnTabSetting(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	OpenSetting();
/*	int CurSel= m_tab.GetCurSel();
	switch(m_tab.GetCurSel())
	{
	case 0:
		m_Setting1.ShowWindow(true);
		m_Setting2.ShowWindow(false);
		m_Setting3.ShowWindow(false);
		break;
	case 1:
		m_Setting1.ShowWindow(false);
		m_Setting2.ShowWindow(true);
		m_Setting3.ShowWindow(false);
		break;
	case 2:
		m_Setting1.ShowWindow(false);
		m_Setting2.ShowWindow(false);
		m_Setting3.ShowWindow(true);
		break;
	default:
		break;
	}*/
	*pResult = 0;
}

void CSettingDlg::OnOK() 
{
	// TODO: Add extra validation here
	m_Setting1.UpdateData(true);
	m_Setting2.UpdateData(true);
//	m_Setting3.SetResultValue(m_Setting1.GetParaValue()+m_Setting2.GetParaValue());
	m_Setting3.UpdateData(false);
//	CDialog::OnOK();
}

void CSettingDlg::OpenSetting()
{
	switch(m_tab.GetCurSel())
	{
	case 0:
		m_Setting1.ShowWindow(true);
		m_Setting2.ShowWindow(false);
		m_Setting3.ShowWindow(false);
		break;
	case 1:
		m_Setting1.ShowWindow(false);
		m_Setting2.ShowWindow(true);
		m_Setting3.ShowWindow(false);
		break;
	case 2:
		m_Setting1.ShowWindow(false);
		m_Setting2.ShowWindow(false);
		m_Setting3.ShowWindow(true);
		break;
	default:
		break;
	}
}

void CSettingDlg::MoveWindow()
{
	CRect rs;
	m_tab.GetClientRect(&rs);
	rs.top+=50;
	rs.bottom-=60;
	rs.left+=50;
	rs.right-=50;
	m_Setting1.MoveWindow(&rs);
	m_Setting2.MoveWindow(&rs);
	m_Setting3.MoveWindow(&rs);
}

void CSettingDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	MoveWindow();
	CDialog::OnTimer(nIDEvent);
}
