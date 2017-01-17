// SETTING3.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "SETTING3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SETTING3 dialog


SETTING3::SETTING3(CWnd* pParent /*=NULL*/)
	: CDialog(SETTING3::IDD, pParent)
{
	//{{AFX_DATA_INIT(SETTING3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SETTING3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SETTING3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SETTING3, CDialog)
	//{{AFX_MSG_MAP(SETTING3)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SETTING3 message handlers
