// filetest.h : main header file for the FILETEST application
//

#if !defined(AFX_FILETEST_H__A4DE2E0F_7E1C_4C02_9A0F_43FB328299B3__INCLUDED_)
#define AFX_FILETEST_H__A4DE2E0F_7E1C_4C02_9A0F_43FB328299B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFiletestApp:
// See filetest.cpp for the implementation of this class
//

class CFiletestApp : public CWinApp
{
public:
	CFiletestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiletestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFiletestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILETEST_H__A4DE2E0F_7E1C_4C02_9A0F_43FB328299B3__INCLUDED_)
