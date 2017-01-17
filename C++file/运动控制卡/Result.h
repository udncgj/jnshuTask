#if !defined(AFX_RESULT_H__5ED4EEB3_7EFF_4930_B3F2_EC40ED6AF18F__INCLUDED_)
#define AFX_RESULT_H__5ED4EEB3_7EFF_4930_B3F2_EC40ED6AF18F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Result.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CResult dialog

class CResult : public CDialog
{
// Construction
public:
	CResult(CWnd* pParent = NULL);   // standard constructor
	void SetResultValue(int nResult);

// Dialog Data
	//{{AFX_DATA(CResult)
	enum { IDD = IDD_RESULT };
	int		m_nResult;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResult)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CResult)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESULT_H__5ED4EEB3_7EFF_4930_B3F2_EC40ED6AF18F__INCLUDED_)
