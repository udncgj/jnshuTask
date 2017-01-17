// SETTING2.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "SETTING2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SETTING2 dialog


SETTING2::SETTING2(CWnd* pParent /*=NULL*/)
	: CDialog(SETTING2::IDD, pParent)
{
	//{{AFX_DATA_INIT(SETTING2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SETTING2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SETTING2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SETTING2, CDialog)
	//{{AFX_MSG_MAP(SETTING2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SETTING2 message handlers
