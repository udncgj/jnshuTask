#if !defined(AFX_IOCHACKDLG_H__06E6521D_325B_4E3E_8DC1_4B9F916BFF2E__INCLUDED_)
#define AFX_IOCHACKDLG_H__06E6521D_325B_4E3E_8DC1_4B9F916BFF2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IOChackDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIOChackDlg dialog

class CIOChackDlg : public CDialog
{
// Construction
public:
	CIOChackDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CIOChackDlg)
	enum { IDD = IDD_IO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIOChackDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIOChackDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnReset();
	afx_msg void OnButton2();
	afx_msg void OnInName1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IOCHACKDLG_H__06E6521D_325B_4E3E_8DC1_4B9F916BFF2E__INCLUDED_)
