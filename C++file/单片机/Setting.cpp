// Setting.cpp : implementation file
//

#include "stdafx.h"
#include "µ¥Æ¬»ú.h"
#include "Setting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetting dialog


CSetting::CSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CSetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetting)
	m_nBaudRate = -1;
	m_nCom = -1;
	m_nDate = -1;
	m_nParity = -1;
	m_nStopBit = -1;
	m_bHex = FALSE;
	//}}AFX_DATA_INIT
}


void CSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetting)
	DDX_Control(pDX, IDC_StopBit, m_StopBit);
	DDX_Control(pDX, IDC_ParityCheck, m_Parity);
	DDX_Control(pDX, IDC_DateSelect, m_Date);
	DDX_Control(pDX, IDC_CommSelect, m_Com);
	DDX_Control(pDX, IDC_BaudRateSelect, m_BaudRate);
	DDX_Control(pDX, IDC_HexSend, m_ctrHex);
	DDX_CBIndex(pDX, IDC_BaudRateSelect, m_nBaudRate);
	DDX_CBIndex(pDX, IDC_CommSelect, m_nCom);
	DDX_CBIndex(pDX, IDC_DateSelect, m_nDate);
	DDX_CBIndex(pDX, IDC_ParityCheck, m_nParity);
	DDX_CBIndex(pDX, IDC_StopBit, m_nStopBit);
	DDX_Check(pDX, IDC_HexSend, m_bHex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetting, CDialog)
	//{{AFX_MSG_MAP(CSetting)
	ON_CBN_EDITCHANGE(IDC_CommSelect, OnEditchangeCommSelect)
	ON_CBN_EDITCHANGE(IDC_BaudRateSelect, OnEditchangeBaudRateSelect)
	ON_CBN_EDITCHANGE(IDC_DateSelect, OnEditchangeDateSelect)
	ON_CBN_EDITCHANGE(IDC_StopBit, OnEditchangeStopBit)
	ON_CBN_EDITCHANGE(IDC_ParityCheck, OnEditchangeParityCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetting message handlers

void CSetting::OnEditchangeCommSelect() 
{
	// TODO: Add your control notification handler code here
	m_nCom = ((CComboBox*)GetDlgItem(IDC_CommSelect))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_CommSelect))->SetCurSel(m_nCom);
}

void CSetting::OnEditchangeBaudRateSelect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_nBaudRate = ((CComboBox*)GetDlgItem(IDC_BaudRateSelect))->GetCurSel();
}

void CSetting::OnEditchangeDateSelect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_nDate = ((CComboBox*)GetDlgItem(IDC_DateSelect))->GetCurSel();
	
}

void CSetting::OnEditchangeStopBit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_nStopBit = ((CComboBox*)GetDlgItem(IDC_StopBit))->GetCurSel();
	
}

void CSetting::OnEditchangeParityCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_nParity = ((CComboBox*)GetDlgItem(IDC_ParityCheck))->GetCurSel();
	
}
