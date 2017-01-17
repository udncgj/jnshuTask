// µ¥Æ¬»úDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
#include "tchart.h"
//}}AFX_INCLUDES

#if !defined(AFX_DLG_H__FA9FC07E_21A9_468C_8C59_10838FA5D3E7__INCLUDED_)
#define AFX_DLG_H__FA9FC07E_21A9_468C_8C59_10838FA5D3E7__INCLUDED_

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
	void LeftMoveArray(int* ptr,int data);
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

	CMenu m_Menu;

	int m_nCom,m_bHex,m_nBaudRate,m_nDate,m_nParity,m_nStopBit;
//	double m_TeeChartArray[2096];
//	double m_X[10];
	int m_count;
	int* Test1;
	int* Test2;


// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CEdit	m_cReadTime;
	CButton	m_ctrlChart2;
	CButton	m_ctrlChart1;
	CComboBox	m_SCMModel;
	CMSComm	m_ctrlComm;
	int		m_nSCMModel;
	int		m_nTest1;
	int		m_nTest2;
	CString	m_strSend;
	CString	m_strMessage;
	CTChart	m_ctrlChart;
	int		m_nReadTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
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
	afx_msg void OnSerial();
	afx_msg void OnEditchangeSCMModel();
	afx_msg void OnButscm();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnOnCommMscomm();
	afx_msg void OnOnMouseMoveTchart(long Shift, long X, long Y);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__FA9FC07E_21A9_468C_8C59_10838FA5D3E7__INCLUDED_)
