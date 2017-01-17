#if !defined(AFX_PARA2_H__0B2CFC20_2208_480E_A308_0CA8B7B2A324__INCLUDED_)
#define AFX_PARA2_H__0B2CFC20_2208_480E_A308_0CA8B7B2A324__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Para2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPara2 dialog

class CPara2 : public CDialog
{
// Construction
public:
	CPara2(CWnd* pParent = NULL);   // standard constructor
    int GetParaValue();

// Dialog Data
	//{{AFX_DATA(CPara2)
	enum { IDD = IDD_PARA2 };
	int		m_nPara2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPara2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPara2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARA2_H__0B2CFC20_2208_480E_A308_0CA8B7B2A324__INCLUDED_)
