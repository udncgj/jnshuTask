#if !defined(AFX_SETTING2_H__D577C9ED_90E8_4FA1_A7F6_90922A09D071__INCLUDED_)
#define AFX_SETTING2_H__D577C9ED_90E8_4FA1_A7F6_90922A09D071__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SETTING2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SETTING2 dialog

class SETTING2 : public CDialog
{
// Construction
public:
	SETTING2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SETTING2)
	enum { IDD = IDD_SETTING2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SETTING2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SETTING2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTING2_H__D577C9ED_90E8_4FA1_A7F6_90922A09D071__INCLUDED_)
