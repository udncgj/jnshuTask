#if !defined(AFX_SETTING_H__D285D88A_0C04_4C44_ADC6_489F7A6CD852__INCLUDED_)
#define AFX_SETTING_H__D285D88A_0C04_4C44_ADC6_489F7A6CD852__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Setting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetting dialog

class CSetting : public CDialog
{
// Construction
public:
	CSetting(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetting)
	enum { IDD = IDD_SETTING };
	CComboBox	m_StopBit;
	CComboBox	m_Parity;
	CComboBox	m_Date;
	CComboBox	m_Com;
	CComboBox	m_BaudRate;
	CButton	m_ctrHex;
	int		m_nBaudRate;
	int		m_nCom;
	int		m_nDate;
	int		m_nParity;
	int		m_nStopBit;
	BOOL	m_bHex;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetting)
	afx_msg void OnEditchangeCommSelect();
	afx_msg void OnEditchangeBaudRateSelect();
	afx_msg void OnEditchangeDateSelect();
	afx_msg void OnEditchangeStopBit();
	afx_msg void OnEditchangeParityCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTING_H__D285D88A_0C04_4C44_ADC6_489F7A6CD852__INCLUDED_)
