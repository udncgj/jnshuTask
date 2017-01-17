#if !defined(AFX_SETTING1_H__1EBC320C_2893_43EE_9BED_7D1761F40BF0__INCLUDED_)
#define AFX_SETTING1_H__1EBC320C_2893_43EE_9BED_7D1761F40BF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SETTING1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SETTING1 dialog

class SETTING1 : public CDialog
{
// Construction
public:
	SETTING1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SETTING1)
	enum { IDD = IDD_SETTING1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SETTING1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SETTING1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTING1_H__1EBC320C_2893_43EE_9BED_7D1761F40BF0__INCLUDED_)
