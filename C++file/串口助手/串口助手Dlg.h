// ´®¿ÚÖúÊÖDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_DLG_H__F8FC9EB1_784C_4F0A_B25C_BB73E4B74702__INCLUDED_)
#define AFX_DLG_H__F8FC9EB1_784C_4F0A_B25C_BB73E4B74702__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	char ConverHexChar(char ch);
	int String2Hex(CString str,CByteArray &senddate);
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CButton	m_ctrlHexSend;
	CComboBox	m_ParityCheck_M;
	CComboBox	m_StopBit_M;
	CComboBox	m_Date_Select_M;
	CComboBox	m_BaudRate_M;
	CComboBox	m_ComboBox;
	CMSComm	m_ctrlComm;
	CString	m_strRXData;
	CString	m_strTXData;
	int		m_BaudRate;
	int		m_Index;
	int		m_Date_Select;
	int		m_ParityCheck;
	int		m_StopBit;
	UINT	m_Timer;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOnComm();
	afx_msg void OnButtonManualsend();
	afx_msg void OnSelchangeCOMBOCommSelect();
	afx_msg void OnSelchangeCOMBOBaudRateSelect();
	afx_msg void OnSelendcancelCOMBODateSelect();
	afx_msg void OnSelchangeCOMBOStopBit();
	afx_msg void OnSelchangeCOMBOParityCheck();
	afx_msg void OnButton1();
	afx_msg void OnBUTTONAutoSend();
	afx_msg void OnBUTTONStopAutoSend();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBUTTONCleanRXData();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__F8FC9EB1_784C_4F0A_B25C_BB73E4B74702__INCLUDED_)
